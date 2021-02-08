#include "Bullet.h"
#include "Human.h"

Bullet::Bullet(double xIn, double yIn, olc::Sprite* spriteIn, PlantsGame* gameIn): DynamicObject(1, xIn, yIn, spriteIn, gameIn), Damage(SEEDDAMAGE), Speed(SEEDSPEED) {}


bool Bullet::isErasable()
{
    return HP <= 0 || x >= Game->ScreenWidth();
}

void Bullet::Draw()
{
    Game->DrawSprite(x-25, y+10, Sprite, 1);
}

void Bullet::Move(float fElapsedTime)
{
    x += Speed * fElapsedTime;
}

void Bullet::useSpeciality(float fElapsedTime, DynamicObject* Target)
{
    if (Target->IsClose(x,y)) //Does Hit fonksiyonu eklenebilir getlerden kurtulmak için
    {
        Target->lowerHP(Damage);
        HP = 0;     //Set its own HP to zero to get erased
    }
}

 