#pragma once

#include "DynamicObject.h"

constexpr int HUMANHP = 100;


class Human : public DynamicObject {
private:
	double Speed;
	double AttackCD;
	double AttackRate;
	bool CanAttack;
protected:
	double Damage;
public:
	Human(double xIn, double yIn, olc::Sprite* SpriteIn, PlantsGame* gameIn);
	virtual ~Human();

	bool DidZombiePass();

	virtual void Move(float fElapsedTime);

	void useSpeciality(float fElapsedTime, DynamicObject* Target);		//Attack

	void Draw();

	virtual void SpecialPower(DynamicObject* Seed);	//special power
};