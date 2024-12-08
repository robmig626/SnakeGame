#pragma once
#include "Constants.h"

struct Node {
	Node* next;
	Node* previous;
	int PosX;
	int PosY;
	int Direction;
	void Append(Node* ToBeAttatchedTo);
};