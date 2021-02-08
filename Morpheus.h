#pragma once
#include "Human.h"

class Morpheus : public Human {

public:
	Morpheus(double xIn, double yIn, olc::Sprite* SpriteIn, PlantsGame* gameIn);

	void SpecialPower(DynamicObject* Bullet = nullptr);
};