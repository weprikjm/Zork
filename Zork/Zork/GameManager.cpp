#include "GameManager.h"
#include <ctime>

void GameManager::sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
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
				

				bool comprovation = CheckCommand();

				if (roomChange)
					InSameRoom = false;
				roomChange = false;
			}


		}

}





void GameManager::CleanUp()
{


}


bool GameManager::CheckCommand()
{
			bool ret = false;
			commandExit();

			if (!roomChange)
				roomChange = Room1CheckCommand();
			if (!roomChange)
				roomChange = Room2CheckCommand();
			if (!roomChange)
				roomChange = Room3CheckCommand();
			if (!roomChange)
				roomChange = Room4CheckCommand();
			if (!roomChange)
				roomChange = Room5CheckCommand();
			if (!roomChange)
				roomChange = Room6CheckCommand();

			ret = PickingItems();
			ret = DropingItems();


			if (!roomChange && !ret)
				printf("\n\nNo such action can be done\n\n");


	return ret;


}



bool GameManager::Room1CheckCommand()
{
	bool ret = false;//false = try again, true = room changed
	//end = true finishes the game //false it continues
	bool progress = false;//Something happened but player continues in the same room


	if (!strcmp(command.c_str(), "go north") || !strcmp(command.c_str(), "Go north") || !strcmp(command.c_str(), "Go North"))
	{
		currentRoom = roomArray[1];
		ret = true;
	}

	if (!strcmp(command.c_str(), "drop glimmering orb") || !strcmp(command.c_str(), "drop orb") || !strcmp(command.c_str(), "Drop Orb"))
	{
		if (PC->inventory.Count() != 0)
		{
			item* itemToRemove;
			PC->inventory.Pop(itemToRemove);
			currentRoom->items.PushBack(itemToRemove);
			printf("\n\nYou dropped %s\n\n", itemToRemove->GetName());
			progress = true;
		}
		else
		{
			printf("\n\nYou cannot drop what you don't have\n\n");

		}
	}



	return ret;
}
//Item picking and dropping temporary code. This code only lets the game have one object which is lame.
bool GameManager::Room2CheckCommand()
{
	bool ret = false;

	if (!strcmp(command.c_str(), "go south") || !strcmp(command.c_str(), "Go south") || !strcmp(command.c_str(), "Go South"))
	{
		currentRoom = roomArray[0];
		ret = true;
	}

	

	if (!strcmp(command.c_str(), "drop glimmering orb") || !strcmp(command.c_str(), "drop orb") || !strcmp(command.c_str(), "Drop Orb"))
	{
		if (PC->inventory.Count() != 0)
		{
			item* itemToRemove;
			PC->inventory.Pop(itemToRemove);
			currentRoom->items.PushBack(itemToRemove);
			printf("\n\nYou dropped %s\n\n", itemToRemove->GetName());

		}
		else
		{
			printf("\n\nYou cannot drop what you don't have\n\n");

		}
	}



	return ret;
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
	if (!strcmp(command.c_str(), "exit") || !strcmp(command.c_str(), "Exit"))
	{
		end = false;
		ret = true;
	}

	return ret;
}




bool GameManager::PickingItems()
{
	bool ret = false;
	if (!strcmp(command.c_str(), "pick glimmering orb") || !strcmp(command.c_str(), "pick orb") || !strcmp(command.c_str(), "Pick Orb"))
	{
		if (currentRoom->items.Count() != 0 && !strcmp(currentRoom->items[0]->GetName(), "glimmering orb"))//If item list of the room is empty player doesn't pick the object
		{
			item* itemToRemove;
			currentRoom->items.Pop(itemToRemove);
			PC->inventory.PushBack(itemToRemove);
			printf("\nYou now have %s\n\n", itemToRemove->GetName());

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
	return false;
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

	Answers* a = new Answers(roomArray[0]->Description, "show");

	roomArray[0]->answers.PushBack(a);

	roomArray[0]->items.PushBack(new item("glimmering orb"));

	currentRoom = roomArray[0];


	roomArray[1]->nameEnum = PORTAL1;
	roomArray[1]->name = "Portal space";
	roomArray[1]->onceDescription = "With the speed of thought you travelled timelessly between both positions";
	roomArray[1]->Description = "You are in front of a huge portal\n";

	//roomArray[1]->items.PushBack(new item("Doll"));
}



void GameManager::PrintRoom(Room* _currentRoom)
{



	Room* roomCopy;
	roomCopy = _currentRoom;


	const char* tmpName = _currentRoom->name;
	for (; *_currentRoom->name != '\0'; _currentRoom->name++)
	{
		printf("%c", *_currentRoom->name);
		sleep(10);
	}

	printf("\n");

	_currentRoom->name = tmpName;//We set the pointer again to the first char of the string.



	char* tmpOnceDescription = _currentRoom->onceDescription;

	for (; *_currentRoom->onceDescription != '\0'; _currentRoom->onceDescription++)
	{
		printf("%c", *_currentRoom->onceDescription);
		sleep(10);

	}


	_currentRoom->onceDescription = tmpOnceDescription;

	printf("\n");

	printf("\n");


	char* tmpDescription = _currentRoom->Description;
	for (; *_currentRoom->Description != '\0'; _currentRoom->Description++)
	{
		printf("%c", *_currentRoom->Description);
		sleep(5);

	}
	_currentRoom->Description = tmpDescription;

	printf("\n");
	printf("\n");



}