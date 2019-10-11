#pragma once
#include<vector>




class Map
{
public:
	Map(int playerPositionX, int PlayerPositionY);
	void Print();
	//void CheckObject(int playerPositionX, int PlayerPositionY);
	std::vector<std::vector<char> >map;
	bool isObstacle = false;
	bool isEnnemy = false;
	bool isPotion = false;
	bool isTrap = false;
	void Add(char objectImage,int objectPositionX, int objectPositionY);
	void UpdateMap(int getPositionX, int getPositionY);
	void ShowMenu(int playerHealth);
	void MoveSecurity(int playerNewPositionx, int playerNewPositionY);
	void CheckWinOrDeath(int playerHealth, bool& isRunning);
private:
};

