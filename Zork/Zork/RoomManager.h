#ifndef __ROOMMANAGER__H__
#define __ROOMMANAGER__H__

#include "exit.h"
#include "DataStructures/p2DynArray.h"
#include "room.h"
#include "player.h"
class RoomManager
{
public:
	RoomManager(player*);

public:
	bool CheckCommand(const char*, Room* _currentRoom, bool& _end);
	bool Room1CheckCommand(const char*,Room*,bool&);
	bool Room2CheckCommand(const char* _command, Room* _currentRoom, bool& _end);
public:
	void Init();
	void sleep(unsigned int mseconds);
public:
	
	p2DynArray<Room*> roomArray;
	Room* currentRoom;
	player* Player;
};



#endif