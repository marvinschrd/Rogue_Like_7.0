#include "player.h"
#include "map.h"
#include "GlobalRessources.h"
#include <iostream>


void Player::TakeDamage(const int attack)
{
	health_ -= attack;
}

void Player::PickUpObject(char userChoice ,int potionHealth)
{
	std::cout << "Do you want to eat the magical healing apple ? If you don't, it will be wasted .  Type Y or N\n";
	std::cin >> userChoice;

	switch (userChoice)
	{
	case('y'):
	{
		takeHealth(potionHealth);
		std::cout << "\nThe apple power gave you 20 health point\n";
		system("pause");
		break;
	}
	case('n'):
	{
		std::cout << "\nYou didn't eat the magical healing apple\nIt transformed into dust\n\n";
		system("pause");
		break;
	}
	default:
	std::cout << "\nYou don't pick up the potion\n\n";
	break;
	}
}

void Player::MovePosition(int newplayerPositionX, int newplayerPositionY, bool isObstacle, bool isEnnemy, bool isPotion, bool isTrap, int potionHealth, int ennemyAttack, int trapDamage, char userChoice)
{
	if(isObstacle== true)
	{
		xPlayerPosition = xPlayerPosition;
		yPlayerPosition = yPlayerPosition;
		return;
	}
	if(isEnnemy == true)
	{
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		TakeDamage(ennemyAttack);
		std::cout << "\nThe enemy got you, he hit you with his full strength, you die..\n\n";
		system("pause");
		return;
	}
	if(isPotion == true)
	{
		PickUpObject(userChoice, potionHealth);
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		return;
	}
	if(isTrap == true)
	{
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		TakeDamage(trapDamage);
		std::cout << "\nYou fell into a trap, hurting yourself and loosing 30 health points\n\n";
		system("pause");
		return;
	}
	else
	{
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		return;
	}
}

void Player::CheckMove(char userInput)
{
	switch(userInput)
	{
	case('w'):
		yNewPlayerPosition = yPlayerPosition ;
		xNewPlayerPosition = xPlayerPosition -1;
		
		
		break;
	case('a'):
		yNewPlayerPosition = yPlayerPosition -1;
		xNewPlayerPosition = xPlayerPosition;
		break;
	case('s'):
		yNewPlayerPosition = yPlayerPosition;
		xNewPlayerPosition = xPlayerPosition + 1;
		break;
	case('d'):
		yNewPlayerPosition = yPlayerPosition +1;
		xNewPlayerPosition = xPlayerPosition;
	}
}

//void Player::CheckObject()
//{
//	/*if(map.map[ressource.xNewPlayerPosition][ressource.yNewPlayerPosition] == ressources.walls || map.map[ressource.xNewPlayerPosition][ressource.yNewPlayerPosition] == ressources.rocks)
//	{
//		map.isObstacle = true;
//	}*/
//	
//}

void Player::AskUserInput()
{
	std::cin >> UserInputs;
}

int Player::GetPlayerXposition()
{
	return xPlayerPosition;
}

int Player::GetPlayerYposition()
{
	return yPlayerPosition;
}

void Player::takeHealth(int potionHealth)
{

	health_ += potionHealth;
	
}

Player::Player(const int health, char sprite)
{
}


