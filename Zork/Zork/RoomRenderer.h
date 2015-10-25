#ifndef __ROOMRENDERER_H__
#define __ROOMRENDERER_H__

#include "room.h"

class RoomRenderer
{
public:
	RoomRenderer();
public:
	void sleep(unsigned int mseconds);
	void PrintRoom(Room* _currentRoom);
private:


};
#endif