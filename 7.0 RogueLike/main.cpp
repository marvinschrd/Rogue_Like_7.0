#include <iostream>
#include "player.h"
#include "ennemy.h"
#include "map.h"
#include "potion.h"
#include "trap.h"
#include "GlobalRessources.h"
#include <Windows.h>
#include <time.h>



int main() {

	
	
	Player player = Player();
	Ennemy ennemy = Ennemy();
	Potion potion = Potion();
	Trap trap = Trap();
	Map map = Map(player.xPlayerPosition, player.yPlayerPosition);
	
	
	
	
	bool isRunning = true;
	while (isRunning == true)
	{
		
		map.isObstacle = false;
		map.isEnnemy = false;
		map.isPotion = false;
		map.isTrap = false;
		map.isMistery = false;
		map.isWinningObject = false;
		
		
		system("cls");
		map.Print();
		map.ShowMenu(player.health_);
		map.GiveKey(potion.potionsLeft, Ressource::mystery,map.keyXPosition, map.keyYPosition, map.level2);
		player.AskUserInput();
		player.CheckMove(player.UserInputs);
		map.MoveSecurity(player.xNewPlayerPosition, player.yNewPlayerPosition);
		map.UpdateMap(player.GetPlayerXposition(), player.GetPlayerYposition());
		
		player.MovePosition(player.xNewPlayerPosition, player.yNewPlayerPosition, map.isObstacle, map.isEnnemy,
			map.isPotion, map.isTrap,map.isMistery,map.isWinningObject, map.level2,potion.potionVie, 
			ennemy.attack_, trap.attackTrap, player.UserChoice, potion.potionsLeft);
		
		map.Add(Ressource::player, player.xPlayerPosition, player.yPlayerPosition);
		map.CheckWinOrDeath(player.health_, isRunning, map.isWinningObject);
		
		
	}
	system("cls");
	map.ShowEnding();
	system("pause");
	return EXIT_SUCCESS;
}