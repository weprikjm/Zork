
#include "iostream"

#include "room.h"
#include "RoomManager.h"

RoomManager::RoomManager()
{
	for (int i = 0; i < TOTAL_ROOMS_GAME; i++)
	{
		roomList.add(new Room);
	}
	
	currentRoom = roomList.At(0)->data;

}

void RoomManager::Init()
{
	roomList.At(0)->data->name = "Consciousness entry point";
	roomList.At(0)->data->onceDescription = "Long time ago there was a man who was told to be a legend..";
	roomList.At(0)->data->Description = "Histories say that his spirit lives within all of us. Will you ever find it?\n";

	Answers* a = new Answers(roomList.At(0)->data->Description, "show");
	
	roomList.At(0)->data->answers.add(a);


	currentRoom = roomList.At(0)->data;


	roomList.At(1)->data->name = "Portal room";
	roomList.At(1)->data->onceDescription = "With the speed of thought you travelled timelessly between both positions";
	roomList.At(1)->data->Description = "You are in front of a huge portal\n";










}







