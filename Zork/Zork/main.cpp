#include <stdio.h>
#include <time.h>
#include <iostream>
#include "DataStructures/p2SString.h"
#include "entity.h"
#include "exit.h"
#include "room.h"
#include "answers.h"
#include "input.h"
#include "GameManager.h"
#include "DataStructures/p2List.h"

#define MAX_SIZE_COMMAND 1000

int genericCounter = 0;




void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}



int main()
{


	GameManager* game;

	
	
	game->Init();

	game->CleanUp();
	
	getchar();
	return 0;
}

