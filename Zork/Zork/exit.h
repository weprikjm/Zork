
#ifndef __EXIT_H__
#define __EXIT_H__

#include "Entity.h"




enum direction
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
	UP,
	DOWN,
	FORWARD,
	BACKWARDS
};

class Exit : public entity
{
public:
	Exit(const char* _name): entity(_name){}

public:
	char* description;
	direction orientation;

	~Exit();
	
};

#endif