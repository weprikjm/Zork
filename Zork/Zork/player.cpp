#include "player.h"


void player::PrintInventory()
{

	printf("\n\n\t :::::: Inventory ::::::\n\n");


	for (int i = 0; i < inventory.Count(); i++)
	{
		printf("\n%s\n\n", inventory[i]->GetName()); 
	}
}