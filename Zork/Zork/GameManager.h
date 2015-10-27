
#ifndef __GAMEMANAGER__H__
#define __GAMEMANAGER__H__

#include "input.h"

#include "RoomManager.h"
#include "RoomRenderer.h"
#include "DataStructures/p2SString.h"
#include "input.h"
#include <string>
#include <sstream>
#include "player.h"

class GameManager
{
public:
	GameManager(){}
public:
	void Init();
	void GameLoop();
	void CleanUp();

public:
	input input;
	std::string command;
	RoomManager* ROOMManager;
	RoomRenderer* ROOMRenderer;

	player* PC; //Player Controller


	bool end;
	bool InSameRoom;
};

#endif