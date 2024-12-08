#pragma once
#include "Constants.h"

class Fruit {
private:
	char Avatar = 'Q';
	int PosX =-1;
	int PosY = -1;
public:
	void BeginPlay();
	void Tick();
	char GetAvatar() const;
	int GetPosX() const;
	int GetPosY() const;

	void SetRandomLocation();
};