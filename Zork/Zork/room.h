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
	Room();
public:
	char* name;
	char* onceDescription;
	char* Description;
	
	p2List<Exit*> exits;
	p2List<Answers*> answers;

	
	bool CheckCommand(const char* command, bool&);

	



	~Room();
};
#endif