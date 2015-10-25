#ifndef __ROOM__H__
#define __ROOM__H__

#include "entity.h"
#include "exit.h"
#include "Answers.h"
#include "DataStructures/p2List.h"

enum RoomNames
{
	CONSCIOUSNESSENTRY = 0,
	PORTAL1
};




class Room : public entity
{
public:
	
	bool(*checkCommand)(const char*, bool&);

	Room(bool(*room)(const char*, bool&))
	{

		checkCommand = room;
	}
	

	
	
public:
	
	char* name;
	char* onceDescription;
	char* Description;
	
	p2List<Exit*> exits;
	p2List<Answers*> answers;

	
	//bool CheckCommand(const char* command, bool&);




	~Room();
};



	bool room1CheckCommand(const char* command, bool& end)
	{
		bool ret = true;

		if (!strcmp(command, "exit") || !strcmp(command, "Exit") || !strcmp(command, "quit") || !strcmp(command, "Quit"))
			ret = false, end = false;

		if (!strcmp(command, "show") || !strcmp(command, "Show"))
			ret = false;
		if (!strcmp(command, "go west") || !strcmp(command, "Go west"))
			game->ROOMManager->currentRoom = game->ROOMManager->roomList.At(1)->data;

		return ret;
	}

	bool room2CheckCommand()
	{
		
	}

	bool room3CheckCommand()
	{
		
	}










#endif



	void my_int_func(int x)
	{
		printf("%d\n", x);
	}

	int main()
	{
		
		/* the ampersand is actually optional */
		foo = &my_int_func;

		return 0;
	}