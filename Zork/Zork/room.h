#ifndef __ROOM_H__
#define __ROOM_H__

#include "entity.h"
#include "exit.h"
#include "answers.h"
#include "DataStructures/p2DynArray.h"





enum RoomNames
{
	CONSCIOUSNESSENTRY = 0,
	PORTAL1
};




class Room : public entity
{
public:
	
	Room(){ }
public:
	
	char* roomName;
	RoomNames name;
	char* onceDescription;
	char* Description;
	
	p2DynArray<Exit*> exits;
	p2DynArray<Answers*> answers;

	

	~Room();
};


#endif



