#include "room.h"
//#include "answers.h"
//#include "RoomManager.h"
//#include "GameManager.h"



Room::~Room()
{

	exits.Clear();
	answers.Clear();

}

bool Room::FindItem(const char* nameObject)
{
	for (int i = 0; i < items.Count(); i++)
	{
		if (items[i]->GetName() == nameObject)
		{
			return true;
		}
	}
	return false;
}

const char* Room::GetName()
{
	return name.c_str();
}