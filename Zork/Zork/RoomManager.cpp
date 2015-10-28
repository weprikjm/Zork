
#include "iostream"

#include "room.h"
#include "RoomManager.h"

RoomManager::RoomManager(player* p)
{
	
	//Creating rooms
	for (int i = 0; i < TOTAL_ROOMS_GAME; i++)
	{
		Room* rmptr = new Room;
		roomArray.PushBack(rmptr);
	}

	currentRoom = roomArray[0];
	
	//Loading player
	Player = p;
}

void RoomManager::Init()
{
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



bool RoomManager::CheckCommand(const char* _command, Room* _currentRoom, bool& _end)
{
	if (_currentRoom->nameEnum == CONSCIOUSNESSENTRY)
	{
		bool ret = Room1CheckCommand(_command,_currentRoom, _end);
		return ret;
	}

	if (_currentRoom->nameEnum == PORTAL1)
	{
		bool ret = Room2CheckCommand(_command, _currentRoom, _end);
		return ret;
	}




	return true;


}



bool RoomManager::Room1CheckCommand(const char* _command, Room* _currentRoom, bool& _end)
{
	bool ret = false;//false = try again, true = room changed
	//end = true finishes the game //false it continues
	bool progress = false;//Something happened but player continues in the same room

	if (!strcmp(_command, "exit") || !strcmp(_command, "Exit"))
	{
		_end = false;
		ret = true;
	}
	if (!strcmp(_command, "go north") || !strcmp(_command, "Go north") || !strcmp(_command, "Go North"))
	{
		currentRoom = roomArray[1];
		ret = true;
	}
	if (!strcmp(_command, "pick glimmering orb") || !strcmp(_command, "pick orb")|| !strcmp(_command, "Pick Orb"))
	{
		if (currentRoom->items.Count() != 0 && !strcmp(currentRoom->items[0]->GetName(), "glimmering orb"))//If item list of the room is empty player doesn't pick the object
		{
			item* itemToRemove;
			currentRoom->items.Pop(itemToRemove);
			Player->inventory.PushBack(itemToRemove);
			printf("\nYou now have %s\n\n", itemToRemove->GetName());
			progress = true;
		}
		else
		{
			printf("\n\nYou already have the object\n\n");
		}
	}
	if (!strcmp(_command, "drop glimmering orb") || !strcmp(_command, "drop orb") || !strcmp(_command, "Drop Orb"))
	{
		if (Player->inventory.Count() != 0)
		{
			item* itemToRemove;
			Player->inventory.Pop(itemToRemove);
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
bool RoomManager::Room2CheckCommand(const char* _command, Room* _currentRoom, bool& _end)
{
	bool ret = false;
	if (!strcmp(_command, "exit") || !strcmp(_command, "Exit"))
	{
		_end = false;
		ret = true;
	}
	if (!strcmp(_command, "go south") || !strcmp(_command, "Go south") || !strcmp(_command, "Go South"))
	{
		currentRoom = roomArray[0];
		ret = true;
	}

	if (!strcmp(_command, "pick glimmering orb") || !strcmp(_command, "pick orb") || !strcmp(_command, "Pick Orb"))
	{
		if (currentRoom->items.Count() != 0 && !strcmp(currentRoom->items[0]->GetName(), "glimmering orb"))//If item list of the room is empty player doesn't pick the object
		{
			item* itemToRemove;
			currentRoom->items.Pop(itemToRemove);
			Player->inventory.PushBack(itemToRemove);
			printf("\nYou now have %s\n\n", itemToRemove->GetName());
			
		}
		else if (Player->inventory.Count() == 0 && currentRoom->items.Count() == 0)
		{
			printf("\n\nThere's no such thing around\n\n");
		}
		else if (Player->inventory.Count() > 0)
		{
			printf("\n\nYou already have the object\n\n");
		}

	}

	if (!strcmp(_command, "drop glimmering orb") || !strcmp(_command, "drop orb") || !strcmp(_command, "Drop Orb"))
	{
		if (Player->inventory.Count() != 0)
		{
			item* itemToRemove;
			Player->inventory.Pop(itemToRemove);
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