#include "map.h"
#include <iostream>
#include "GlobalRessources.h"
#include <windows.h>
#include "potion.h"
#include "trap.h"
#include <time.h>
#include <fstream>
#include <string>

Ressource ressource;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);


Map::Map(int playerPositionX, int playerPositionY)
{
	srand(time(NULL));
	map = std::vector<std::vector<char> >(20, std::vector<char>(70));
	
	for (unsigned int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			map[i][j] = ressource.ground;
		}
	}

	
	
	for (unsigned int i = 0; i < 20; i++)
	{
		map[i][69] = ressource.walls;
		map[i][0] = ressource.walls;

	}

	for (unsigned int i = 0; i < 70; i++)
	{
		map[0][i] = ressource.walls;
		map[19][i] = ressource.walls;
	}
	map[playerPositionX][playerPositionY] = ressource.player;
	map[16][12] = Potion::potion;
	map[1][38] = Potion::potion;
	map[4][68] = Potion::potion;
	map[18][61] = Potion::potion;
	
	map[8][14] = Trap::trap;
	map[10][53] = Trap::trap;
	map[5][50] = Trap::trap;
	
	map[12][15] = ressource.ennemy;
	map[8][47] = Trap::trap;
	map[8][47] = ressource.ennemy;
	map[10][46] = Trap::trap;
	map[9][49] = Trap::trap;
	map[9][56] = ressource.ennemy;
	map[6][57] = Trap::trap;
	map[6][52] = Trap::trap;
	
	map[6][46]= ressource.walls;
	map[6][47] = ressource.walls;
	map[7][51] = ressource.winningObject;
	
	for(int i = 0; i < 30; i++)
	{
		map[(rand() % 16)+3][(rand() % 66)+3] = Trap::trap;
	}
	for (int i = 0; i < 5; i++)
	{
		map[rand() % 16 + 3][rand() % 66 + 3] = Potion::potion ;
	}
	for (int i = 0; i < 5; i++)
	{
		map[rand() % 16 + 3][rand() % 66 + 3] = Ressource::ennemy;
	}
	for (unsigned int i = 0; i < 5; i++)
	{
		map[i+1][32] = ressource.walls;
		map[i+1][33] = ressource.walls;
		map[10][i+1] = ressource.walls;
		map[10][i + 6] = ressource.walls;
		map[11][i + 1] = ressource.walls;
		map[11][i + 6] = ressource.walls;
		map[16][i + 34] = ressource.walls;
		map[16][i + 39] = ressource.walls;
		map[16][i + 44] = ressource.walls;
		
	}
	for (unsigned int i = 0; i < 3; i++)
	{
		map[i + 1][1] = ressource.walls;
		map[i + 1][2] = ressource.walls;
		map[i + 16][33] = ressource.walls;
		map[i + 9][45] = ressource.walls;
		map[i + 6][45] = ressource.walls;
		map[11][i+46] = ressource.walls;
		map[11][i + 49] = ressource.walls;
		map[11][i + 52] = ressource.walls;
		map[11][i + 55] = ressource.walls;
		map[i + 9][58] = ressource.walls;
		map[i + 6][58] = ressource.walls;
		map[i + 3][58] = ressource.walls;
		map[3][i + 55] = ressource.walls;
		map[3][i + 52] = ressource.walls;
		map[3][i + 49] = ressource.walls;
		map[i + 3][48] = ressource.walls;
		map[i + 6][48] = ressource.walls;
		map[8][i + 49] = ressource.walls;
		map[8][i + 52] = ressource.walls;
		map[i + 6][55] = ressource.walls;
	}
	for(int i = 0; i<=10;i++)
	{
		map[i + 7][25] = ressource.walls;
		map[i + 7][26] = ressource.walls;
		map[4][i + 7] = ressource.walls;
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

void Map::loadLevel2()
{

	std::ifstream inFile;
	inFile >> std::noskipws;

	char line;
	inFile.open("Niveau2.txt");
	map = std::vector<std::vector<char> >(18, std::vector<char>(56));

	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++)
		{
			while (inFile >> line) {

				map[i][j] = line;
				break;
			}

		}

	}


	inFile.close();



};

void Map::Add(char objectImage, int objectPositionX, int objectPositionY)
{
	srand(time(NULL));
	map[objectPositionX][objectPositionY] = objectImage;
}

void Map::UpdateMap(int getPositionX, int getPositionY)
{
	map[getPositionX][getPositionY] = ressource.ground;
}	

void Map::ShowMenu(int playerHealth)
{
	SetConsoleTextAttribute(color, 11);
	std::cout << " #####################################################################\n";
	std::cout << " |                                                                   |\n";
	std::cout << " |      Player health = " << playerHealth << "				             |\n";
	std::cout << " |         To move up press : W      To move down press : S          |\n";
	std::cout << " |         To move right press : D   To move left press : A          |\n";
	std::cout << " |                                                                   |\n";
	std::cout << " #####################################################################\n";
	
}

void Map::ShowEnding()
{
	std::cout << " #####################################################################\n";
	std::cout << " |                                                                   |\n";
	std::cout << " |                                                                   |\n";
	std::cout << " |                       End of the game                             |\n";
	std::cout << " |                                                                   |\n";
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
		for (int i = 0; i <= 10; i++)
		{
			Add(Trap::trap, (rand() % 16) + 3, (rand() % 66) + 3);
		}
	}
	if (map[playerNewPositionx][playerNewPositionY] == Trap::trap)
	{
		isTrap = true;
		for (int i = 0; i <= 10; i++)
		{
			Add(Trap::trap, rand() % 16 + 3, rand() % 66 + 3);
		}
	}
	if (map[playerNewPositionx][playerNewPositionY] == ressource.mystery )
	{
		isMistery = true;
		Add(ressource.ground, 6, 46);
		Add(ressource.ground, 6, 47);
		
	}
	if (map[playerNewPositionx][playerNewPositionY] == ressource.winningObject)
	{
		isWinningObject = true;
		loadLevel2();
	}
}

void Map::CheckWinOrDeath(int playerHealth, bool& isRunning, bool isWinningObject)
{

	if (playerHealth <= 0)
	{
		isRunning = false;
	}
	/*if(isWinningObject == true)
	{
		isRunning = false;
	}*/
}

void Map::GiveKey(int potionTaken, char keyImage, int keyXPosition, int keyYPosition, bool level2)
{
	int numberNeeded = 3;
	if(potionTaken == numberNeeded && level2 == false)
	{
			Add(keyImage, keyXPosition, keyYPosition);
	}
}








