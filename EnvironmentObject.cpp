#include "EnvironmentObject.h"

EnvironmentObject::EnvironmentObject(double xIn, double yIn, olc::Sprite* spriteIn, PlantsGame* gameIn) : x(xIn), y(yIn), Sprite(spriteIn), Game(gameIn) {}

bool EnvironmentObject::IsIn(double xIn, double yIn)
{
	return (xIn >= x && xIn < x + STANDARDWIDTH) && (yIn >= y && yIn < y + STANDARDHEIGTH);
}

void EnvironmentObject::Draw()
{
	Game->DrawSprite(x, y, Sprite, 1);
}
