#include "Neo.h"

Neo::Neo(double xIn, double yIn, olc::Sprite* SpriteIn, olc::Sprite* SpriteIn_2, PlantsGame* gameIn) :
	Human(xIn, yIn, SpriteIn, gameIn), SpecialSprite(SpriteIn_2)
{
	HP = NEOHP;

	specialCD = NEOreflexTime;
	SpecialActive = false;
	specialDuration = NEOspecialDuration;
}

void Neo::Move(float fElapsedTime)
{
	if (!SpecialActive)
	{
		Human::Move(fElapsedTime);
	}
	if (!SpecialActive && specialCD >= 0)
	{
		specialCD -= fElapsedTime;
	}
	if (SpecialActive)
	{
		specialDuration -= fElapsedTime;

		if (specialDuration <= 0)
		{
			specialDuration = NEOspecialDuration;
			SpecialActive = false;
			ChangeSprite(SpecialSprite);
			y -= 22;
		}
	}
}

void Neo::SpecialPower(DynamicObject* Bullet)
{
	if (!SpecialActive)
	{
		if (specialCD <= 0)
		{
			if (Bullet->IsClose(x, y, 10))
			{
				if (rand() % 2 == 0) 
				{
					SpecialActive = true;
					specialCD = NEOreflexTime;
					ChangeSprite(SpecialSprite);
					y += 22;
				}
			}
		}
	}
}
