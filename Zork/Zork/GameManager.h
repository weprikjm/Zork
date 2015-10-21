#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__


#include "input.h"

#include "RoomManager.h"
#include "RoomRenderer.h"


class GameManager
{

public:
	void Init();
	void GameLoop();
	void CleanUp();

public:
	input input;
	p2SString command;
	RoomManager* ROOMManager;
	RoomRenderer* ROOMRenderer;
};
#endif