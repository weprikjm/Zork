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

	const char* GetName();


public:
	RoomNames nameEnum;
	MyString onceDescription;
	MyString Description;
	
	p2DynArray<Exit*> exits;
	p2DynArray<Answers*> answers;
	p2DynArray<item*> items;
	
	bool FindItem(const char* nameObject);

	~Room();
};


#endif



