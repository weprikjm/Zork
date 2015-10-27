
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
	roomArray[0]->Description = "Histories say that his spirit lives within all of us. Will you ever find it?\n you can see a glimmering orb, there's something shining north from where you are";

	Answers* a = new Answers(roomArray[0]->Description, "show");
	
	roomArray[0]->answers.PushBack(a);

	roomArray[0]->items.PushBack(new item("glimmering orb"));

	currentRoom = roomArray[0];


	roomArray[1]->nameEnum = PORTAL1;
	roomArray[1]->name = "Portal space";
	roomArray[1]->onceDescription = "With the speed of thought you travelled timelessly between both positions";
	roomArray[1]->Description = "You are in front of a huge portal\n";

	roomArray[1]->items.PushBack(new item("Doll"));
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
	bool ret = false;

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
		
	}
	if (!strcmp(_command, "drop glimmering orb") || !strcmp(_command, "drop orb") || !strcmp(_command, "Drop Orb"))
	{

	}

	if(!ret)printf("Try again!\n\t\t");

	return ret;
}

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

	if(!ret)printf("Try harder!!!\n\t\t");

	return ret;
}