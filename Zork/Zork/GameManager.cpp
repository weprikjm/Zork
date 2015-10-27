#include "GameManager.h"




void GameManager::Init()
{
	ROOMManager = new RoomManager;
	ROOMManager->Init();

	ROOMRenderer = new RoomRenderer;
	
	PC = new player("Trevor");
}


void GameManager::GameLoop()
{
		end = true;
		InSameRoom = false;
		char temp[101];

		while (end)
		{
			system("cls");
			ROOMRenderer->PrintRoom(ROOMManager->currentRoom);

			InSameRoom = true;
			while (InSameRoom)
			{
				printf("\n\t\t%s ", input.nextMessage);
				std::getline(std::cin, command);
				

				bool comprovation = ROOMManager->CheckCommand(command.c_str(),ROOMManager->currentRoom,end);

				if (comprovation)
					InSameRoom = false;
			
			}


		}

}





void GameManager::CleanUp()
{


}