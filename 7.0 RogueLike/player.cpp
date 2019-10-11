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
	std::cout << "Do you want to pick up the Potion ? Type Y or N\n";
	std::cin >> userChoice;

	switch (userChoice)
	{
	case('y'):
	{
		takeHealth(potionHealth);
		break;
	}
	case('n'):
	{
		std::cout << "You don't pick up the potion\n";
		system("pause");
		break;
	}
	default:
	std::cout << "You don't pick up the potion\n";
	break;
	}
}

//void Player::Position()
//{
//	
//}



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
		//ajouter prise de degats
		TakeDamage(ennemyAttack);
		return;
	}
	if(isPotion == true)
	{
		PickUpObject(userChoice, potionHealth);
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		//ajouter option de recuperer
		return;
	}
	if(isTrap == true)
	{
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		//ajouter prise de degats
		TakeDamage(trapDamage);
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


