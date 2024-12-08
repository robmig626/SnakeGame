#include "Node.h"

void Node::Append(Node* ToBeAttatchedTo)
{
	Node* NewNode = new Node{ nullptr,
		ToBeAttatchedTo,
		ToBeAttatchedTo->PosX,
		ToBeAttatchedTo->PosY,
		ToBeAttatchedTo->Direction 
	};
	switch (ToBeAttatchedTo->Direction)
	{
	case Move_Up:
		NewNode->PosX = (PosX + 1) % GAME_FIELD_SIZE_X;
		break;
	case Move_Left:
		NewNode->PosY = (PosY+1)% GAME_FIELD_SIZE_Y;
		break;
	case Move_Down:
		NewNode->PosX = PosX == 0 ? GAME_FIELD_SIZE_X : (PosX - 1) % GAME_FIELD_SIZE_X;
		break;
	case Move_Right:
		NewNode->PosY = PosY == 0? GAME_FIELD_SIZE_Y : (PosY - 1) % GAME_FIELD_SIZE_Y;
		break;
	}
	ToBeAttatchedTo->next = NewNode;
}