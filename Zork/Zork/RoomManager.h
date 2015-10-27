#ifndef __ROOMMANAGER__H__
#define __ROOMMANAGER__H__

#include "exit.h"
#include "DataStructures/p2DynArray.h"
#include "room.h"
class RoomManager
{

public:
	RoomManager();
	bool CheckCommand(const char*, Room* _currentRoom, bool& _end);
	bool RoomManager::Room1CheckCommand(const char*,Room*,bool&);
public:
	void Init();
	void sleep(unsigned int mseconds);
public:
	
	p2DynArray<Room*> roomArray;
	Room* currentRoom;
};



#endif