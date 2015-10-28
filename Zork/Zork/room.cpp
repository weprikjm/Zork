#include "room.h"
//#include "answers.h"
//#include "RoomManager.h"
//#include "GameManager.h"



Room::~Room()
{

	exits.Clear();
	answers.Clear();

}


const char* Room::GetName()
{
	return name;
}