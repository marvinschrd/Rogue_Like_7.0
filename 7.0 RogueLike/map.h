#pragma once
#include<vector>




class Map
{
public:
	Map(int playerPositionX, int PlayerPositionY);
	
	std::vector<std::vector<char> >map;
	bool isObstacle = false;
	bool isEnnemy = false;
	bool isPotion = false;
	bool isTrap = false;
	bool isMistery = false;
	bool isWinningObject = false;
	
	int keyXPosition = 10;
	int keyYPosition = 35;
	
	void Print();
	void Add(char objectImage,int objectPositionX, int objectPositionY);
	void UpdateMap(int getPositionX, int getPositionY);
	void ShowMenu(int playerHealth);
	void ShowEnding();
	void MoveSecurity(int playerNewPositionx, int playerNewPositionY);
	void CheckWinOrDeath(int playerHealth, bool& isRunning, bool isWinningObject);
	void GiveKey(int potionTaken, char keyImage, int keyXPosition, int keyYPosition);
private:
};

