//#include <iostream>
#ifndef __EXIT_H__
#define __EXIT_H__
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
	char* description;
	direction orientation;

}exitRoom1, exitRoom2;

#endif