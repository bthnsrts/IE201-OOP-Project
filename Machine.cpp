#include "Machine.h"
#include "Tile.h"
#include "SpriteHolder.h"
#include "Energy.h"

Machine::Machine(double xIn, double yIn, olc::Sprite* SpriteIn, PlantsGame* GameIn, Tile* TileIn): DynamicObject(MACHINEHP, xIn, yIn, SpriteIn, GameIn),
    tileHabited(TileIn), EnergyRate(5), EnergyCD(3) {}

Machine::~Machine()
{
    tileHabited->setEmpty();
}

void Machine::Draw()
{
    DynamicObject::Draw();

    Game->FillRect(x + 15, y + 2, 20*(HP/ MACHINEHP), 5, olc::RED);
}

void Machine::useSpeciality(float fElapsedTime, DynamicObject* Target) //Create Energy
{
    EnergyCD -= fElapsedTime;
    if (EnergyCD <= 0)
    {
        EnergyCD = EnergyRate;
        Game->createEnergy(x, y);
    }
}