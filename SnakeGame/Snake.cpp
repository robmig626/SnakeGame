#include <Windows.h>
#include "Snake.h"

void PlayerSnake::BeginPlay()
{
	SnakeBody = new Node{ nullptr, nullptr,10, 10, Move_Up};
	Grow();
	Grow();

}

void PlayerSnake::Tick()
{
	//Check if player wishes to switch directions
	if ((GetKeyState('W') & 0x8000) || (GetKeyState(VK_UP) & 0x8000))
	{
		GetSnakeHead()->Direction = Move_Up;
	}
	if ((GetKeyState('A') & 0x8000) || (GetKeyState(VK_LEFT) & 0x8000))
	{
		GetSnakeHead()->Direction = Move_Left;
	}
	if ((GetKeyState('D') & 0x8000) || (GetKeyState(VK_RIGHT) & 0x8000))
	{
		GetSnakeHead()->Direction = Move_Right;
	}
	if ((GetKeyState('S') & 0x8000) || (GetKeyState(VK_DOWN) & 0x8000))
	{
		GetSnakeHead()->Direction = Move_Down;
	}

	//Update the position of the nodes
	Node* index = SnakeBody;
	while (index != nullptr)
	{
		switch (index->Direction)
		{
		case Move_Up:
			index->PosX = index->PosX == 0 ? GAME_FIELD_SIZE_X-1 : (index->PosX - 1) % GAME_FIELD_SIZE_X;
			break;
		case Move_Down:
			index->PosX = (index->PosX + 1) % GAME_FIELD_SIZE_X;
			break;
		case Move_Left:
			index->PosY = index->PosY == 0 ? GAME_FIELD_SIZE_Y-1 : (index->PosY - 1) % GAME_FIELD_SIZE_Y;
			break;
		case Move_Right:
			index->PosY = (index->PosY + 1) % GAME_FIELD_SIZE_Y;
			break;
		}
		index = index->next;
	}
	
	//Update the direction of the next step
	index = SnakeTail;
	while (index != SnakeBody)
	{
		index->Direction = index->previous->Direction;
		index = index->previous;
	}
}

void PlayerSnake::Grow()
{
	Node* index = SnakeBody;
	while (index->next != nullptr)
	{
		index = index->next;
	}
	index->Append(index);
	SnakeTail = index->next;
}

bool PlayerSnake::IsBitingTail()
{
	return false;
}

char PlayerSnake::GetSnakeHeadAvatar()
{
	switch (SnakeBody->Direction)
	{
	case Move_Up:
		return HeadAvatarUp;
		break;
	case Move_Down:
		return HeadAvatarDown;
		break;
	case Move_Left:
		return HeadAvatarLeft;
		break;
	case Move_Right:
		return HeadAvatarRight;
	}
}

char PlayerSnake::GetSnakeBodyAvatar()
{
	return BodyAvatar;
}

Node* PlayerSnake::GetSnakeHead()
{
	return SnakeBody;
}

Node* PlayerSnake::GetSnakeTail()
{
	return SnakeTail;
}

int PlayerSnake::GetLength()
{
	int Length = 0;
	Node* index = SnakeBody;
	while (index != nullptr)
	{
		Length++;
		index = index->next;
	}
	return Length;
}