#include <stdio.h>
#include <time.h>
#include <iostream>
#include "p2SString.h"
#include "entity.h"
#include "exit.h"
#include "room.h"
#include "answers.h"
#include "input.h"s

#define MAX_SIZE_COMMAND 1000

int genericCounter = 0;

enum direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	UP,
	DOWN,
	FORWARD,
	BACKWARDS
};



void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}







void PrintRoom(Room* room)
{
	
	Room* roomCopy;
	roomCopy = room;
	roomCopy->name = room->name;


	for (; *room->name != '\0'; room->name++)
	{
		printf("%c",*room->name);
		sleep(100);
	}
	
	printf("\n");
	room->name = roomCopy->name;
	roomCopy->onceDescription = room->onceDescription;




	

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

void Init()
{

	input.nextMessage = "\\-- What's next? ";


	roomConsciousnessEntrance.name = "Oblivion";
	roomConsciousnessEntrance.onceDescription = "Thoughts: You are not alone, you never were.. Bump.. Bump.. (Heart Pounds). My mind's \nstill. My breath's steady. I feel boundless. ..Where am I? Who I am?";
	roomConsciousnessEntrance.Description = "Facts: You are floating in the void, everything is dark here, you are at awe with the nothingness. Take a look around..";
	roomConsciousnessEntrance.exit.name = "Portal";
	roomConsciousnessEntrance.exit.description = "You can see a tiny spot of light in the distance. It's glowing in blue. It's right above you at about several thousands of km";
	roomConsciousnessEntrance.exit.orientation = UP;

	roomBlueLight.name = "next room";
	roomBlueLight.onceDescription = "Under Construction";
	roomBlueLight.Description = "Under Construction";
	roomBlueLight.exit.name = "exit";
	roomBlueLight.exit.description = "Under Construction";
	roomBlueLight.exit.orientation = WEST;



}



int main()
{

	p2SString command;
	char temp[101];
	Room* ptr_roomConsciousnessEntrance = &roomConsciousnessEntrance;
	Room* ptrTMP_roomConsciousnessEntrance = ptr_roomConsciousnessEntrance;

	Room* ptr_room2 = &roomBlueLight;
	Room* ptrTMP_room2 = ptr_room2;
	
	bool InSameRoom = false;


	bool end = true;
	Init();

	Room* CurrentRoom;
	CurrentRoom = ptr_roomConsciousnessEntrance;


	while (end)
	{

		PrintRoom(CurrentRoom);
		InSameRoom = true;
			while(InSameRoom)
			{ 
				printf("%s", input.nextMessage);
				command = fgets(temp, 5, stdin);

				CurrentRoom->CheckCommand(command);

				if (command == "exit" || command == "Exit" || command == "quit" || command == "Quit")
					end = false;




				InSameRoom = false;
			}


	}



	
	//getchar();
	return 0;
}

