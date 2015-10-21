#include "RoomManager.h"


RoomManager::RoomManager()
{
	for (int i = 0; i < TOTAL_ROOMS_GAME; i++)
	{
		roomList.add(new Room);
	}
	


}

void RoomManager::Init()
{
	


}


void RoomManager::PrintRoom(Room* _currentRoom)
{
	
	

		Room* roomCopy;
		roomCopy = _currentRoom;
		roomCopy->name = _currentRoom->name;


		for (; *_currentRoom->name != '\0'; _currentRoom->name++)
		{
			printf("%c", *room->name);
			sleep(100);
		}

		printf("\n");
		_currentRoom->name = roomCopy->name;
		roomCopy->onceDescription = _currentRoom->onceDescription;






		for (; *room->onceDescription != '\0'; room->onceDescription++)
		{
			printf("%c", *room->onceDescription);
			sleep(100);

		}
		room->Description = roomCopy->Description;

		printf("\n");

		printf("\n");

		for (; *room->Description != '\0'; room->Description++)
		{
			printf("%c", *room->Description);
			sleep(50);

		}
		room->Description = roomCopy->Description;

		printf("\n");
		printf("\n");



	



}