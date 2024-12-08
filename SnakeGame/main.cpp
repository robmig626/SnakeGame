#include <iostream>
#include "GameManager.h"

int main(void)
{
	GameManager Game = GameManager();

	Game.BeginPlay();
	while (!Game.IsGameOver())
	{
		Game.Tick();
	}

	if (Game.GetGameLost())
	{
		std::cout << "\n\nYOU LOST!" << std::endl;
	}
	else
	{
		std::cout << "\n\nYOU WON!" << std::endl;
	}
}