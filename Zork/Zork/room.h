#ifndef __ROOM_H__
#define __ROOM_H__

#include "entity.h"
#include "exit.h"
#include "answers.h"
#include "DataStructures/p2DynArray.h"
#include "item.h"




enum RoomNames
{
	CONSCIOUSNESSENTRY = 0,
	PORTAL1
};




class Room : public entity
{
public:
	
	Room(const char* _name){ }
	Room(){}
public:
	
	
	RoomNames nameEnum;
	char* onceDescription;
	char* Description;
	
	p2DynArray<Exit*> exits;
	p2DynArray<Answers*> answers;
	p2DynArray<item*> items;
	

	~Room();
};


#endif



