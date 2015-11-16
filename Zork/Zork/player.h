#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "entity.h"
#include "DataStructures\p2DynArray.h"
#include "item.h"

class player : public entity
{
public:
	player(const char* _name) : entity(_name){}
	player(){}

	void PrintInventory();

	p2DynArray<item*> inventory;



};

#endif