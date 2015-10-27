#include "RoomRenderer.h"
#include <ctime>

RoomRenderer::RoomRenderer()
{



}




void RoomRenderer::PrintRoom(Room* _currentRoom)
{



	Room* roomCopy;
	roomCopy = _currentRoom;


	char* tmpName = _currentRoom->roomName;
	for (; *_currentRoom->roomName != '\0'; _currentRoom->roomName++)
	{
		printf("%c", *_currentRoom->roomName);
		sleep(100);
	}

	printf("\n");

	_currentRoom->roomName = tmpName;//We set the pointer again to the first char of the string.



	char* tmpOnceDescription =_currentRoom->onceDescription;

	for (; *_currentRoom->onceDescription != '\0'; _currentRoom->onceDescription++)
	{
		printf("%c", *_currentRoom->onceDescription);
		sleep(100);

	}
	

	_currentRoom->onceDescription = tmpOnceDescription;

	printf("\n");

	printf("\n");


	char* tmpDescription = _currentRoom->Description;
	for (; *_currentRoom->Description != '\0'; _currentRoom->Description++)
	{
		printf("%c", *_currentRoom->Description);
		sleep(50);

	}
	_currentRoom->Description = tmpDescription;

	printf("\n");
	printf("\n");



}


void RoomRenderer::sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());

}
