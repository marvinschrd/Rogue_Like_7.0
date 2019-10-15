#pragma once

struct Ressource
{
	static const char ground = '.';
	static const char walls = char(186);
	static const char rocks = '^';
	static const char player = '@';
	static const char ennemy = char(149);
	static const char mystery = char(232);
	static const char winningObject = char(244);
	int randomXNumber = 16 ;
	int randomYNumber = 66 ;
	int randomLimit = 3;
};