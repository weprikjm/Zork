
#ifndef __GAMEMANAGER__H__
#define __GAMEMANAGER__H__

#include "input.h"


#include "DataStructures/MyString.h"
#include "input.h"
#include <string>
#include <sstream>
#include "player.h"
#include "Room.h"

class GameManager
{
public:
	GameManager(){}
public:
	void Init();
	void GameLoop();
	void CleanUp();


	bool CheckCommand();
	bool commandExit();
	bool Room1CheckCommand();
	bool Room2CheckCommand();
	bool Room3CheckCommand();
	bool Room4CheckCommand();
	bool Room5CheckCommand();
	bool Room6CheckCommand();


	bool ShowInventory();
	bool PickingItems();
	bool DropingItems();

	bool DivideInWords(MyString& commandDef, p2DynArray<MyString*>& arrayCommand);

	void PrintRoom(Room* _currentRoom);

public:
	input input;
	std::string command;//Dunno any other way to get info by the user
	MyString commandDef;
	p2DynArray<MyString*> arrayCommand;

	player* PC; //Player Controller


	bool end;
	bool InSameRoom;


//Room Related
public:
	p2DynArray<Room*> roomArray;
	Room* currentRoom;
	

//Rendering utils
private:
void sleep(unsigned int mseconds);

//Atributes to control the game flow
bool roomChange = false;

};

#endif