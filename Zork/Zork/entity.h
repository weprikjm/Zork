#include <iostream>
#include "DataStructures\MyString.h"
#ifndef __ENTITY_H__
#define __ENTITY_H__

class entity
{
public:
	entity(){}
	entity(const char* _name) : name(_name){}

public:
	MyString name;


};

#endif