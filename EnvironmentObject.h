#pragma once

#include "PlantsGame.h"

constexpr int STANDARDWIDTH = 50;
constexpr int STANDARDHEIGTH = 50;

//Another name idea static
class EnvironmentObject			//Tile and Card				//Environment Objects are not destructable or constructable through the game
{
protected:
	olc::Sprite* Sprite;
	double x, y;
	PlantsGame* Game;

public:
	EnvironmentObject(double xIn, double yIn, olc::Sprite* spriteIn, PlantsGame* gameIn);

	bool IsIn(double xIn, double yIn);

	void Draw();
};


