#pragma once

#include "DynamicObject.h"

class Smith : public DynamicObject {

private:
	
	double AttackCD;
	double AttackRate;

	Tile* tileHabited;

public:
	Smith(double xIn, double yIn, olc::Sprite* spriteIn, PlantsGame* gameIn, Tile* TileIn);
	~Smith();

	void Draw();

	void useSpeciality(float fElapsedTime, DynamicObject* Target = nullptr);		//ShootSeed

};