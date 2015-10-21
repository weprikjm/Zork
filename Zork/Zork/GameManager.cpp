#include "GameManager.h"



void GameManager::Init()
{
	ROOMManager = new RoomManager;
	ROOMManager->Init();

	ROOMRenderer = new RoomRenderer;





}


void GameManager::GameLoop()
{
		bool end = true;
		bool InSameRoom = false;
		char temp[101];

		while (end)
		{

			ROOMManager->PrintRoom(ROOMManager->currentRoom);

			InSameRoom = true;
			while (InSameRoom)
			{
				printf("%s", input.nextMessage);
				command = fgets(temp, 5, stdin);

				bool comprovation = ROOMManager->currentRoom->CheckCommand(command.GetString());

				if (!comprovation)
					InSameRoom = false;

				if (command == "exit" || command == "Exit" || command == "quit" || command == "Quit")
					end = false;



			}


		}

}





void GameManager::CleanUp()
{


}