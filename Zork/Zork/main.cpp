#include <stdio.h>
#include <time.h>

int genericCounter = 0;


void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}




struct Room
{
	char* name; 
	char* onceDescription;
	char* Description;

}room1,room2;


struct Answers
{
	char* Dunno = "I don't understand your brain.";
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


	

}

void Init()
{
	room1.name = "Oblivion";
	room1.onceDescription = "Thoughts: You are not alone, you never were.. Bump.. Bump.. (Heart Pounds). My mind's \nstill. My breath's steady. I feel boundless. ..Where am I? Who I am?";
	room1.Description = "Facts: You are floating in the void, everything is dark here, you are at awe with the nothingness. Take a look around..";
}


int main()
{

	
	Room* ptr_room1 = &room1;

	Init();


	PrintRoom(ptr_room1);






	getchar();
	return 0;
}

