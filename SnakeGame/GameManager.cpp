#include <iostream>
#include <Windows.h>
#include "GameManager.h"

void GameManager::ClearField()
{
	for (int i = 0; i < GAME_FIELD_SIZE_X;i++)
	{
		for (int j = 0; j < GAME_FIELD_SIZE_Y;j++)
		{
			GameField[i][j] = ' ';
		}
	}
}
void GameManager::RenderField()
{
	//Set the cursor position to be 0 0
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0, 0 };
	SetConsoleCursorPosition(hConsole, pos);

	for (int i = 0; i < GAME_FIELD_SIZE_X;i++)
	{
		for (int j = 0; j < GAME_FIELD_SIZE_Y;j++)
		{
			std::cout << GameField[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void GameManager::UpdateField()
{
	Node* index = Snake->GetSnakeHead();

	ClearField();

	if (IsOverlappingWithSnake(Snake->GetSnakeHead()->PosX, Snake->GetSnakeHead()->PosY, true))
	{
		SetGameOver(true);
		if (Snake->GetLength() >= WinLength)
		{
			SetGameLost(false);
		}
	}
	
	//Snake Eating behaviour
	if ((Food->GetPosX() == Snake->GetSnakeHead()->PosX) && \
		(Food->GetPosY() == Snake->GetSnakeHead()->PosY))
	{
		do
		{
			Food->SetRandomLocation();
			Snake->Grow();
		} while (IsOverlappingWithSnake(Food->GetPosX(), Food->GetPosY(),false));
	}

	//Print snake
	GameField[index->PosX][index->PosY] = Snake->GetSnakeHeadAvatar();

	while (index->next != nullptr)
	{
		index = index->next;
		GameField[index->PosX][index->PosY] = Snake->GetSnakeBodyAvatar();
	}

	//Print foods
	GameField[Food->GetPosX()][Food->GetPosY()] = Food->GetAvatar();

	//Print Snake Length:
	std::cout << "Snake Length: " << Snake->GetLength() << std::endl;

	//Print Win Condition:
	std::cout << "Desired Length: " << WinLength << std::endl;

}

void GameManager::BeginPlay()
{
	Snake = new PlayerSnake();
	Snake->BeginPlay();

	Food = new Fruit();
	Food->BeginPlay();

	ClearField();
}
void GameManager::Tick()
{
	Snake->Tick();

	UpdateField();
	RenderField();
	Sleep(100);
}

bool GameManager::IsGameOver() const
{
	return bGameOver;
}

bool GameManager::GetGameLost() const
{
	return bGameLost;
}

void GameManager::SetGameOver(bool newGameOver)
{
	bGameOver = newGameOver;
}

void GameManager::SetGameLost(bool newGameLost)
{
	bGameLost = newGameLost;
}

bool GameManager::IsOverlappingWithSnake(int PosX, int PosY, bool bIgnoreHead)
{
	Node* index = Snake->GetSnakeHead();

	if (bIgnoreHead)
	{
		index = index->next;
	}

	while (index != nullptr)
	{
		if (index->PosX == PosX && index->PosY == PosY)
		{
			return true;
		}
		index = index->next;
	}
	return false;
}