#include "Human.h"
#include "Smith.h"
#include "Machine.h"

Human::Human(double xIn, double yIn, olc::Sprite* SpriteIn, PlantsGame* gameIn) : DynamicObject(HUMANHP, xIn, yIn, SpriteIn, gameIn)
{
	Speed = 10;
	AttackCD = 0;
	AttackRate = 4;
	Damage = 40;
	CanAttack = false;
}

Human::~Human()
{
}

bool Human::DidZombiePass()
{
	return x <= 0;
}

void Human::Move(float fElapsedTime)
{
	if (!CanAttack) 
	{
		x -= Speed * fElapsedTime;
	}

	CanAttack = false;

	AttackCD -= fElapsedTime;
}

void Human::useSpeciality(float fElapsedTime, DynamicObject* Target)
{
	if (Target->IsClose(x,y)) 
	{
		CanAttack = true;
		if (AttackCD <= 0) {
			Target->lowerHP(Damage);
			AttackCD = AttackRate;
		}
	}
}

void Human::Draw()
{
	DynamicObject::Draw();
	Game->FillRect(x+25, y + 2, 20 * (HP / HUMANHP), 5, olc::DARK_RED);
	Game->DrawRect(x + 25, y + 2, 20 * (HP / HUMANHP), 5, olc::BLACK);
}

void Human::SpecialPower(DynamicObject* Seed)
{
}
