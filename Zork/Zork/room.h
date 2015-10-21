#ifndef __ROOM_H__
#define __ROOM_H__

#include "entity.h"
#include "exit.h"
#include "answers.h"


class Room : public entity
{
public:
	char* onceDescription;
	char* Description;
	Exit exit;
	answers CheckCommand(const char* command)const;

}
#endif