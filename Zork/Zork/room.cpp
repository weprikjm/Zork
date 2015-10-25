#include "room.h"
#include "answers.h"
#include "RoomManager.h"
#include "GameManager.h"




Room::Room()
{



}

bool Room::CheckCommand(const char* command, bool& end)
{
	bool ret = true;

	if (!strcmp(command, "exit") || !strcmp(command, "Exit") || !strcmp(command, "quit") || !strcmp(command, "Quit"))
		ret = false , end = false;

	if (!strcmp(command, "show") || !strcmp(command, "Show"))
		ret = false;
	if (!strcmp(command, "go west") || !strcmp(command, "Go west"))
		game->ROOMManager->currentRoom = game->ROOMManager->roomList.At(1)->data;

	return ret;
}




Room::~Room()
{

	exits.clear();


}