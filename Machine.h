#pragma once

#include "DynamicObject.h"

constexpr int MACHINEHP = 100;

class Machine : public DynamicObject
{
	double EnergyRate, EnergyCD;
    Tile* tileHabited;
public:
    Machine(double xIn, double yIn, olc::Sprite* SpriteIn, PlantsGame* GameIn, Tile* TileIn);
    ~Machine();

    void Draw();

    void useSpeciality(float fElapsedTime, DynamicObject* Target = nullptr);     //Create Energy
};