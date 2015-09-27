#include <stdio.h>
#include <time.h>

int genericCounter = 0;


void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}




struct Room1
{
	char* name = "Oblivion";
	char* onceDescription = "Thoughts: You are not alone, you never were.. Bump.. Bump.. (Heart Pounds). My mind's \nstill. My breath's steady. I feel boundless. ..Where am I? Who I am?";
	char* Description = "Facts: You are floating in the void, everything is dark here, you are at awe with the \nnothingness. Take a look around..";

}room1;


struct Answers
{
	char* Dunno = "I don't understand your brain.";
	char* Cant = "I'm afraid I can't do that.";
}ans;


void writeRoom1(Room1* room)
{

	Room1* roomCopy;
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


	for (; *room->name != '\0'; room->name++)
	{
		printf("%c", *room->name);
		sleep(100);
	}


	/*

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


	*/

}




int main()
{

	
	Room1* ptr_room1 = &room1;

	writeRoom1(ptr_room1);

	getchar();
	return 0;
}

