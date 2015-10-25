
#ifndef __GAMEMANAGER__H__
#define __GAMEMANAGER__H__

#include "input.h"

#include "RoomManager.h"
#include "RoomRenderer.h"
#include "DataStructures/p2SString.h"



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
	p2SString command;
	RoomManager* ROOMManager;
	RoomRenderer* ROOMRenderer;

	bool end;
	bool InSameRoom;
};
extern GameManager* game = new GameManager;
#endif