#ifndef __ITEM_H__
#define __ITEM_H__

#include "entity.h"


class item : entity
{
public:
	//Constructors
	item(const char* _name) : entity(_name){} //-> pending

	const char* GetName();

	

};

#endif