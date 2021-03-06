#include "GameManager.h"
#include <ctime>

void GameManager::sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}






void GameManager::Init()
{
	PC = new player("Trevor");

	//Creating rooms
	for (int i = 0; i < TOTAL_ROOMS_GAME; i++)
	{
		Room* rmptr = new Room;
		roomArray.PushBack(rmptr);
	}

	currentRoom = roomArray[0];


	roomArray[0]->nameEnum = CONSCIOUSNESSENTRY;
	roomArray[0]->name = "Consciousness Entry Point";
	roomArray[0]->onceDescription = "Long time ago there was a man who was told to be a legend..";
	roomArray[0]->Description = "Histories say that his spirit lives within all of us. Will you ever find it?\nyou can see a glimmering orb, there's something shining north from where you are\n";

	Answers* a = new Answers(roomArray[0]->Description.c_str(), "show");

	roomArray[0]->answers.PushBack(a);

	roomArray[0]->items.PushBack(new item("glimmering orb"));

	currentRoom = roomArray[0];


	roomArray[1]->nameEnum = PORTAL1;
	roomArray[1]->name = "Portal space";
	roomArray[1]->onceDescription = "With the speed of thought you travelled timelessly between both positions";
	roomArray[1]->Description = "You are in front of a huge portal\n";

	//roomArray[1]->items.PushBack(new item("Doll"));
}







void GameManager::GameLoop()
{
		end = true;
		InSameRoom = false;
		char temp[101];

		while (end)
		{
			system("cls");
			PrintRoom(currentRoom);

			InSameRoom = true;
			while (InSameRoom)
			{
				printf("%s ", input.nextMessage);
				std::getline(std::cin, command);
				
				commandDef = command.c_str();

				bool comprovation = CheckCommand();

				if (roomChange||comprovation)
					InSameRoom = false;
				roomChange = false;
			}


		}

}





void GameManager::CleanUp()
{


}

//Needs further work
bool GameManager::DivideInWords(MyString& commandDef, p2DynArray<MyString*>& arrayToFill)
{
	int j = 0;
	MyString* tmpStr;
	tmpStr = new MyString(32);

	for (int i = 0; i < commandDef.Count(); i++)
	{
		if (commandDef[i] == ' ')
		{
			arrayToFill.PushBack(tmpStr);
			tmpStr->Clear();
			j = 0;
		}
		else if (i == (commandDef.Count() - 1))
			arrayToFill.PushBack(tmpStr);
		else
		{
			tmpStr[j] = commandDef[i];
			j++;
		}
			
	}
	if (arrayToFill.Count() > 0)
		return true;
	else
		return false;
}



bool GameManager::CheckCommand()
{
			bool ret = false;
			bool strings = false;
			//strings = DivideInWords(commandDef,arrayCommand);
			bool objects = false;


			ret = commandExit();

			if (!roomChange && !ret)
				roomChange = Room1CheckCommand();
			if (!roomChange && !ret)
				roomChange = Room2CheckCommand();
			if (!roomChange && !ret)
				roomChange = Room3CheckCommand();
			if (!roomChange && !ret)
				roomChange = Room4CheckCommand();
			if (!roomChange && !ret)
				roomChange = Room5CheckCommand();
			if (!roomChange && !ret)
				roomChange = Room6CheckCommand();
			
			if (!roomChange && !ret && !objects)
				objects = PickingItems();
			if (!roomChange && !ret && !objects)
				objects = DropingItems();
			if (!roomChange && !ret && !objects)
				objects = ShowInventory();

			if (!roomChange && !ret && !objects)
				printf("\n\nNo such action can be done");


	return ret;


}

bool GameManager::ShowInventory()
{
	bool ret = false;

	if (commandDef == "Show Inventory" || commandDef == "show inventory")
	{
		ret = true;
		PC->PrintInventory();
	}

	return ret;
}

bool GameManager::Room1CheckCommand()
{
	bool ret = false;//false = try again, true = room changed
	//end = true finishes the game //false it continues
	bool progress = false;//Something happened but player continues in the same room


	if (commandDef == "go north" || commandDef == "Go north" || commandDef == "Go North")
	{
		currentRoom = roomArray[1];
		ret = true;
	}

	return ret;
}
//Item picking and dropping temporary code. This code only lets the game have one object which is lame.
bool GameManager::Room2CheckCommand()
{
	bool action = false;

	if (commandDef == "go south" || commandDef == "Go south" || commandDef == "Go South")
	{
		currentRoom = roomArray[0];
		action = true;
	}

	




	return action;
}




bool GameManager::Room3CheckCommand()
{
	return false;
}

bool GameManager::Room4CheckCommand()
{
	return false;
}


bool GameManager::Room5CheckCommand()
{
	return false;
}

bool GameManager::Room6CheckCommand()
{
	return false;
}




bool GameManager::commandExit()
{
	bool ret = false;
	if (commandDef == "exit" || commandDef == "Exit")
	{
		end = false;
		ret = true;
	}

	return ret;
}




bool GameManager::PickingItems()
{
	bool ret = false;
	if (commandDef == "pick glimmering orb" || commandDef == "pick orb" || commandDef == "Pick Orb")
	{
		if (currentRoom->items.Count() != 0 && !currentRoom->FindItem("glimmering orb"))//If item list of the room is empty player doesn't pick the object
		{
			item* itemToRemove;
			currentRoom->items.Pop(itemToRemove);
			PC->inventory.PushBack(itemToRemove);
			printf("\nYou now have %s\n\n", itemToRemove->GetName());
			ret = true;
		}
		else if (PC->inventory.Count() == 0 && currentRoom->items.Count() == 0)
		{
			printf("\n\nThere's no such thing around\n\n");
		}
		else if (PC->inventory.Count() > 0)
		{
			printf("\n\nYou already have the object\n\n");
		}

	}
	return ret;
}
bool GameManager::DropingItems()
{

	bool ret = false;


	if (commandDef == "drop glimmering orb" || commandDef == "drop orb" || commandDef == "Drop Orb")
	{
		if (PC->inventory.Count() != 0)
		{
			item* itemToRemove;
			PC->inventory.Pop(itemToRemove);
			currentRoom->items.PushBack(itemToRemove);
			printf("\n\nYou dropped %s\n\n", itemToRemove->GetName());
			ret = true;

		}
		else
		{
			printf("\n\nYou cannot drop what you don't have\n\n");
			ret = true;
		}
	}

	return ret;
}



void GameManager::PrintRoom(Room* _currentRoom)
{



	Room* roomCopy;
	roomCopy = _currentRoom;



	for (int i=0; i <_currentRoom->name.Count(); i++)
	{
		printf("%c",_currentRoom->name[i]);
		sleep(10);
	}

	printf("\n");



	for (int i=0; i <_currentRoom->onceDescription.Count(); i++)
	{
		printf("%c", _currentRoom->onceDescription[i]);
		sleep(10);
	}



	printf("\n");
	printf("\n");


	
	for (int i=0; i < _currentRoom->Description.Count(); i++)
	{
		printf("%c", _currentRoom->Description[i]);
		sleep(5);
	}
	

	printf("\n");
	printf("\n");
}