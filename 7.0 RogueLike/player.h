#pragma once
#include<iostream>
class Player
{
public:
	Player(const int health, char sprite);
	~Player() {};

	void TakeDamage(int attack);
	void PickUpObject(char userChoice,int potionHealth);
	/*void Position();*/
	void MovePosition(int playerPositionX, int playerPositionY, bool isObstacle, bool isEnnemy, bool isPotion, bool isTrap, int potionHealth, int ennemyAttack, int trapDamage, char userChoice);
	void CheckMove(char userInput);
	void AskUserInput();
	int GetPlayerXposition();
	int GetPlayerYposition();
	void takeHealth(int potionHealth);
	char UserInputs;
	char UserChoice;
	int xPlayerPosition = 3;
	int yPlayerPosition = 18;
	int xNewPlayerPosition;
	int yNewPlayerPosition;
	int health_ = 100;
private:
	char sprite_;
	
};

