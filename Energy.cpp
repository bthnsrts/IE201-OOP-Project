#include "Energy.h"

bool Energy::IsIn(double Mx, double My)
{
	return distance(x + 20, y + 20, Mx, My) < 20;
}

Energy::Energy(double xIn, double yIn, olc::Sprite* SpriteIn, PlantsGame* GameIn):DynamicObject(1, xIn, yIn, SpriteIn, GameIn)
{
	EnergyGain = ENERGYGAIN;
}

void Energy::useSpeciality(float fElapsedTime, DynamicObject* Target)
{
	if (IsIn(Game->GetMouseX(), Game->GetMouseY())) {
		Game->addEnergy(EnergyGain);
		HP = 0;			//Set its own HP to zero to get erased
	}
}
