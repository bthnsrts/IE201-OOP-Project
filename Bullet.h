#pragma once

#include "DynamicObject.h"

constexpr int SEEDDAMAGE = 30;
constexpr int SEEDSPEED = 100; //50

class Bullet : public DynamicObject {
private:
	double Damage;
	double Speed;
public:
	Bullet(double xIn, double yIn, olc::Sprite* spriteIn, PlantsGame* gameIn);

	bool isErasable();

	void Draw();

	void Move(float fElapsedTime);

	void useSpeciality(float fElapsedTime, DynamicObject* Target);			//Attack
};

