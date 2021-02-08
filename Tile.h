#pragma once

#include "EnvironmentObject.h"

class Tile : public EnvironmentObject
{
	bool IsFull;

public:
	Tile(int xIn, int yIn, PlantsGame* gameIn);

	void Draw();
	void Highlight();
	void Plant(Card* Card);
	void setEmpty();

	
};