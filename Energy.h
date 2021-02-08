#pragma once

#include "DynamicObject.h"

constexpr int ENERGYGAIN = 50;


class Energy : public DynamicObject
{
	int EnergyGain;
	bool IsIn(double Mx, double My);

public: 
	Energy(double xIn, double yIn, olc::Sprite* SpriteIn, PlantsGame* GameIn);

	void useSpeciality(float fElapsedTime = 0, DynamicObject* Target = nullptr);		//Get Collected
};