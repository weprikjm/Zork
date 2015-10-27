#include "RoomRenderer.h"
#include <ctime>

RoomRenderer::RoomRenderer()
{



}




void RoomRenderer::PrintRoom(Room* _currentRoom)
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



	char* tmpOnceDescription =_currentRoom->onceDescription;

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


void RoomRenderer::sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());

}
