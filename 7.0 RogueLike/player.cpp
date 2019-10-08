#include "player.h"
#include "map.h"
#include "GlobalRessources.h"
#include <iostream>



void Player::TakeDamage(const int attack)
{
	health_ -= attack;
}

void Player::PickUpObject()
{
	
}

//void Player::Position()
//{
//	
//}



void Player::MovePosition(int newplayerPositionX, int newplayerPositionY, bool isObstacle, bool isEnnemy, bool isPotion, bool isTrap, int potionHealth, int ennemyAttack)
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
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		//ajouter option de recuperer
		takeHealth(potionHealth);
		return;
	}
	if(isTrap == true)
	{
		xPlayerPosition = newplayerPositionX;
		yPlayerPosition = newplayerPositionY;
		//ajouter prise de degats
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


