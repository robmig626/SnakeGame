#pragma once
#include "Constants.h"
#include "Node.h"

class PlayerSnake
{
private:

	char HeadAvatarUp = 'A';
	char HeadAvatarDown = 'V';
	char HeadAvatarLeft = '<';
	char HeadAvatarRight = '>';
	char BodyAvatar = 'O';

	Node* SnakeBody = nullptr;
	Node* SnakeTail = nullptr;
public:

	void BeginPlay();
	void Tick();
	void Grow();
	bool IsBitingTail();

	char GetSnakeHeadAvatar();
	char GetSnakeBodyAvatar();
	Node* GetSnakeHead();
	Node* GetSnakeTail();
	int GetLength();

};