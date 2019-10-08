#pragma once
class Trap
{
public:
	
	Trap(int attack, char sprite);
	~Trap() {};

	static const char trap = 'X';
	int attackTrap = 30;

private:
};

