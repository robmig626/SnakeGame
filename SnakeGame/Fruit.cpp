#include <cstdlib>
#include<time.h>
#include "Fruit.h"

void Fruit::BeginPlay()
{
	srand(time(0));
	SetRandomLocation();
}

void Fruit::Tick()
{
	//Do nothing
}

char Fruit::GetAvatar() const
{
	return Avatar;
}

int Fruit::GetPosX() const
{
	return PosX;
}

int Fruit::GetPosY() const
{
	return PosY;
}

void Fruit::SetRandomLocation()
{
	PosX = rand() % GAME_FIELD_SIZE_X;
	PosY = rand() % GAME_FIELD_SIZE_Y;
}