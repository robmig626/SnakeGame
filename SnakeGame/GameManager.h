#pragma once
#include "Snake.h"
#include "Fruit.h"

class GameManager {
private:
	int WinLength = 7;
	bool bGameOver = false;
	bool bGameLost = true;
	char GameField[GAME_FIELD_SIZE_X][GAME_FIELD_SIZE_Y];
	PlayerSnake* Snake;
	Fruit* Food;

public:
	void ClearField();
	void RenderField();
	void UpdateField();
	void BeginPlay();
	void Tick();

	bool IsGameOver() const;
	bool GetGameLost() const;
	void SetGameOver(bool newGameOver);
	void SetGameLost(bool newGameLost);

	bool IsOverlappingWithSnake(int PosX, int PosY, bool bIgnoreHead);
};