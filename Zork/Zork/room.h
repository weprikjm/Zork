#include "entity.h"
#include "exit.h"


#ifndef __ROOM_H__
#define __ROOM_H__
class Room : public entity
{
public:
	char* onceDescription;
	char* Description;
	Exit exit;
	bool CheckCommand(char* command);

}roomConsciousnessEntrance, roomBlueLight;
#endif