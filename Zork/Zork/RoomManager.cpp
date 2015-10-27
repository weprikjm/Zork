
#include "iostream"

#include "room.h"
#include "RoomManager.h"

RoomManager::RoomManager()
{
	for (int i = 0; i < TOTAL_ROOMS_GAME; i++)
	{
		Room* rmptr = new Room;
		roomArray.PushBack(rmptr);
	}

	currentRoom = roomArray[0];

}

void RoomManager::Init()
{
	roomArray[0]->name = CONSCIOUSNESSENTRY;
	roomArray[0]->roomName = "Consciousness Entry Point";
	roomArray[0]->onceDescription = "Long time ago there was a man who was told to be a legend..";
	roomArray[0]->Description = "Histories say that his spirit lives within all of us. Will you ever find it?\n";

	Answers* a = new Answers(roomArray[0]->Description, "show");
	
	roomArray[0]->answers.PushBack(a);


	currentRoom = roomArray[0];


	roomArray[1]->name = PORTAL1;
	roomArray[1]->roomName = "Portal space";
	roomArray[1]->onceDescription = "With the speed of thought you travelled timelessly between both positions";
	roomArray[1]->Description = "You are in front of a huge portal\n";
}



bool RoomManager::CheckCommand(const char* _command, Room* _currentRoom, bool& _end)
{
	if (_currentRoom->name == CONSCIOUSNESSENTRY)
	{
		_end = Room1CheckCommand(_command,_currentRoom);
	}

	if (_currentRoom->name == PORTAL1)
	{

	}


	return _end;


}



bool RoomManager::Room1CheckCommand(const char* _command, Room* _currentRoom, bool& _end)
{
	if (!strcmp(_command, "exit") || !strcmp(_command, "Exit"))
	{
		return false;
	}
	if (!strcmp(_command, "go north") || !strcmp(_command, "Go north") || !strcmp(_command, "Go North"))
	{
		currentRoom = roomArray[1];
		_end = false;
	}



	return true;
}