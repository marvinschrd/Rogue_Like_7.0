#include "map.h"
#include <iostream>
#include "GlobalRessources.h"
#include "player.h"
#include <windows.h>
#include "potion.h"
#include "trap.h"
#include <time.h>

Ressource ressource;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);


Map::Map(int playerPositionX, int playerPositionY)
{
	map = std::vector<std::vector<char> >(20, std::vector<char>(70));
	
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			map[i][j] = ressource.ground;
		}
	}

	
	
	for (int i = 0; i < 20; i++)
	{
		map[i][69] = ressource.walls;
		map[i][0] = ressource.walls;

	}

	for (int i = 0; i < 70; i++)
	{
		map[0][i] = ressource.walls;
		map[19][i] = ressource.walls;
	}
	map[playerPositionX][playerPositionY] = ressource.player;
	map[16][12] = Potion::potion;
	map[8][14] = Trap::trap;
	map[8][17] = ressource.rocks;
	map[12][15] = ressource.ennemy;

	for(int i = 0; i < 10; i++)
	{
		map[rand() % 16+3][rand() % 66+3] = Trap::trap;
	}
	for (int i = 0; i < 5; i++)
	{
		map[rand() % 16 + 3][rand() % 66 + 3] = Potion::potion ;
	}
	for (int i = 0; i < 15; i++)
	{
		map[rand() % 16 + 3][rand() % 66 + 3] = ressource.rocks;
	}
}

void Map::Print()
{
	system("Color 0C");
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{

			std::cout << map[i][j];
		}
		std::cout << "\n";

	}
}

//void Map::CheckObject(int playerPositionX, int playerPositionY)
//{
//	if (map[playerPositionX +1][playerPositionY] == ressource.walls || map[playerPositionX+1][playerPositionY] == ressource.rocks)
//	{
//		isObstacle = true;
//	}
//}

void Map::Add(char objectImage, int objectPositionX, int objectPositionY)
{
	map[objectPositionX][objectPositionY] = objectImage;
	
}

void Map::UpdateMap(int getPositionX, int getPositionY)
{
	
	
	if(isTrap == true)
	{
		map[getPositionX][getPositionY] = 'X';
	}
	else
	{
		map[getPositionX][getPositionY] = ressource.ground;
	}
	
}

void Map::ShowMenu(int playerHealth)
{
	SetConsoleTextAttribute(color, 11);
	std::cout << " #####################################################################\n";
	std::cout << " |                                                                   |\n";
	std::cout << " |      Player health = " << playerHealth << "                                          |\n";
	std::cout << " |         To move up press : W      To move down press : S          |\n";
	std::cout << " |         To move right press : D   To move left press : A          |\n";
	std::cout << " |                                                                   |\n";
	std::cout << " #####################################################################\n";
	
}

void Map::MoveSecurity(int playerNewPositionx, int playerNewPositionY)
{
	if(map[playerNewPositionx][playerNewPositionY]==ressource.walls || map[playerNewPositionx][playerNewPositionY] == ressource.rocks)
	{
		isObstacle = true;
	}
	if(map[playerNewPositionx][playerNewPositionY]==ressource.ennemy)
	{
		isEnnemy = true;
	}
	if (map[playerNewPositionx][playerNewPositionY] == Potion::potion)
	{
		isPotion = true;
	}
	if (map[playerNewPositionx][playerNewPositionY] == Trap::trap)
	{
		isTrap = true;
	}

}

void Map::CheckWinOrDeath(int playerHealth, bool& isRunning)
{

	if (playerHealth <= 0)
	{
		isRunning = false;
	}
}




