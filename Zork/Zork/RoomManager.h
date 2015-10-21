#ifndef __ROOMMANAGER_H__
#define __ROOMMANAGER_H__

#include "exit.h"
#include "room.h"
#include "DataStructures/p2List.h"

class RoomManager
{
public:
	RoomManager();
	void Init();
	void PrintRoom(Room* _currentRoom);
public:
	
	p2List<Room*> roomList;
	Room* currentRoom;

};



#endif