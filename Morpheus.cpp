#include "Morpheus.h"

Morpheus::Morpheus(double xIn, double yIn, olc::Sprite* SpriteIn, PlantsGame* gameIn):
Human(xIn, yIn, SpriteIn, gameIn){}

void Morpheus::SpecialPower(DynamicObject* Bullet)
{
	Damage = 140 - HP;
}

