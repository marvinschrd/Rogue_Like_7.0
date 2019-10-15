#include <iostream>
#include "player.h"
#include "ennemy.h"
#include "map.h"
#include "potion.h"
#include "trap.h"
#include "GlobalRessources.h"
#include <Windows.h>
#include <time.h>


/* EXERCICE 7.0 ROGUE LIKE
Créer un jeu dans le style roguelike.
Vous devez afficher une map dans la console, vous pouvez choisir le taille, et ce que vous mettez dedans,
mais il faut que celle-ci soit rafraîchie au moins à chaque déplacement du personnage.
N’oubliez pas de nettoyer la console avant d’afficher quelque chose.
Pour le personnage principale il faut qu’il puisse effectuer des actions (command-based style).
Il doit être capable de se déplacer et de prendre des objets. Il doit être présenter par un symbole précis.
Le joueur doit être capable de récupérer des potions de vie s’il est sur la même case(via une action) et
s’il marche sur un piège il faut que celui-ci perde de la vie. Il faut donc aussi afficher sa vie.
En plus du projet il faut rendre un document en format pdf avec un schéma qui explique comment les jeux s'exécute et
comment les classes sont liées entre elles.
Une fois les éléments de bases terminé (map, personnage, déplacement, UI) vous êtes libre de faire ce que vous voulez.
N’oubliez pas de faire quelque chose de fun et amusez-vous en le faisant.
*/

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
		
		system("cls");
		map.Print();
		map.ShowMenu(player.health_);
		map.GiveKey(potion.potionsLeft, Ressource::mystery,map.keyXPosition, map.keyYPosition);
		player.AskUserInput();
		player.CheckMove(player.UserInputs);
		map.MoveSecurity(player.xNewPlayerPosition, player.yNewPlayerPosition);
		map.UpdateMap(player.GetPlayerXposition(), player.GetPlayerYposition());
		player.MovePosition(player.xNewPlayerPosition, player.yNewPlayerPosition, map.isObstacle, map.isEnnemy, map.isPotion, map.isTrap,map.isMistery,map.isWinningObject,potion.potionVie, ennemy.attack_, trap.attackTrap, player.UserChoice, potion.potionsLeft);
		map.Add(Ressource::player, player.xPlayerPosition, player.yPlayerPosition);
		map.CheckWinOrDeath(player.health_, isRunning, map.isWinningObject);
		
	}
	system("cls");
	std::cout << " #####################################################################\n";
	std::cout << " |                                                                   |\n";
	std::cout << " |                                                                   |\n";
	std::cout << " |                       End of the game                             |\n";
	std::cout << " |                                                                   |\n";
	std::cout << " |                                                                   |\n";
	std::cout << " #####################################################################\n";
	system("pause");
	return EXIT_SUCCESS;
}