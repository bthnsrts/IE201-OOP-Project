#pragma once
#include "Human.h"

constexpr int NEOHP = 200;
constexpr double NEOreflexTime = 0.4;
constexpr double NEOspecialDuration = 0.3;

class Neo : public Human
{
private:
	olc::Sprite* SpecialSprite;

	double specialCD;
	bool SpecialActive;
	double specialDuration;
public:
	Neo(double xIn, double yIn, olc::Sprite* SpriteIn, olc::Sprite* SpriteIn_2, PlantsGame* gameIn);

	void Move(float fElapsedTime);

	void SpecialPower(DynamicObject* Bullet);

};