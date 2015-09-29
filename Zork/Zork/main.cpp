#include <stdio.h>
#include <time.h>
#include <iostream>
#include "p2SString.h"

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

struct input
{
	char* nextMessage;

}input;


struct Exit 
{
	char* name;
	char* description;
	direction orientation;

}exitRoom1, exitRoom2;


struct Room
{
	char* name; 
	char* onceDescription;
	char* Description;
	Exit exit;


}room1,room2;


struct Answers
{
	char* Dunno = "I can't understand your thought process.";
	char* Cant = "I'm afraid I can't do that.";
}ans;


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


	room1.name = "Oblivion";
	room1.onceDescription = "Thoughts: You are not alone, you never were.. Bump.. Bump.. (Heart Pounds). My mind's \nstill. My breath's steady. I feel boundless. ..Where am I? Who I am?";
	room1.Description = "Facts: You are floating in the void, everything is dark here, you are at awe with the nothingness. Take a look around..";
	room1.exit.name = "Portal";
	room1.exit.description = "You can see a tiny spot of light in the distance. It's glowing in blue. It's right above you at about several thousands of km";
	room1.exit.orientation = UP;

	room2.name = "next room";
	room2.onceDescription = "Under Construction";
	room2.Description = "Under Construction";
	room2.exit.name = "exit";
	room2.exit.description = "Under Construction";
	room2.exit.orientation = WEST;



}


int main()
{

	p2SString command;
	char temp[101];
	Room* ptr_room1 = &room1;
	Room* ptrTMP_room1 = ptr_room1;

	Room* ptr_room2 = &room2;
	Room* ptrTMP_room2 = ptr_room2;


	bool end = true;
	Init();


	PrintRoom(ptrTMP_room1);

	while (end)
	{
		printf("%s", input.nextMessage);
		command = fgets(temp, 5, stdin);






		if (command == "exit" || command == "Exit" || command == "quit" || command == "Quit")
			end = false;



	}



	
	//getchar();
	return 0;
}

