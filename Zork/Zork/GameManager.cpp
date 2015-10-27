#include "GameManager.h"



void GameManager::Init()
{
	ROOMManager = new RoomManager;
	ROOMManager->Init();

	ROOMRenderer = new RoomRenderer;
	
}


void GameManager::GameLoop()
{
		end = true;
		InSameRoom = false;
		char temp[101];

		while (end)
		{

			ROOMRenderer->PrintRoom(ROOMManager->currentRoom);

			InSameRoom = true;
			while (InSameRoom)
			{
				printf("%s", input.nextMessage);
				command = fgets(temp, 5, stdin);

				bool comprovation = ROOMManager->CheckCommand(ROOMManager->currentRoom);

				if (!comprovation)
					InSameRoom = false;
			

			}


		}

}





void GameManager::CleanUp()
{


}