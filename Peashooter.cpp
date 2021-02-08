#include "Smith.h"
#include "Bullet.h"
#include "Tile.h"

constexpr int PEASHOOTERHP = 100;

Peashooter::Peashooter(double xIn, double yIn, olc::Sprite* spriteIn, PlantsGame* gameIn, Tile* TileIn) : 
    DynamicObject(PEASHOOTERHP, xIn, yIn, spriteIn, gameIn), 
    tileHabited(TileIn), AttackCD(0), AttackRate(3) {}

Peashooter::~Peashooter()
{
    tileHabited->setEmpty(); 
}

void Peashooter::Draw()
{
    DynamicObject::Draw();
    Game->FillRect(x + 15, y + 2, 20 * (HP / PEASHOOTERHP), 5, olc::RED);
    //Game->DrawString(x + 15, y, to_string((int)HP), olc::BLACK);
}

void Peashooter::useSpeciality(float fElapsedTime, DynamicObject* Target)   //ShootSeed
{
    AttackCD -= fElapsedTime;
    if (AttackCD <= 0) {
        Game->createBullet(x, y);
        AttackCD = AttackRate;
    }
}
