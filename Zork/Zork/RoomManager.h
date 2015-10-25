#ifndef __ROOMMANAGER__H__
#define __ROOMMANAGER__H__

#include "exit.h"
#include "room.h"
#include "DataStructures/p2List.h"

class RoomManager
{

public:
	RoomManager();
public:
	void Init();
	void sleep(unsigned int mseconds);
public:
	
	p2List<Room*> roomList;
	Room* currentRoom;

};



#endif