#pragma once
#include "player.h"
class Ennemy
{
public:
	Ennemy(const int attack, char sprite);
	~Ennemy() {};

	//void Attack(Player &Player) const;

	int attack_ = 200;
private:
	//int attack_;
	char sprite_;
	
};

