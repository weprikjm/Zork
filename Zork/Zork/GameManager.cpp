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
				std::getline(std::cin, command);
				//command = fgets(temp, 5, stdin);

				bool comprovation = ROOMManager->CheckCommand(command.c_str(),ROOMManager->currentRoom,end);

				if (!comprovation)
					InSameRoom = false;
			
			}


		}

}





void GameManager::CleanUp()
{


}