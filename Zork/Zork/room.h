#ifndef __ROOM__H__
#define __ROOM__H__

#include "entity.h"
#include "exit.h"
#include "answers.h"
#include "DataStructures/p2List.h"
#include "RoomManager.h"
#include "GameManager.h"
//#include "answers.h"
//#include "RoomManager.h"



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
	
	p2List<Exit*> exits;
	p2List<Answers*> answers;

	

	~Room();
};


#endif



