#include "DynamicObject.h"

DynamicObject::DynamicObject(double HPIn, double xIn, double yIn, olc::Sprite* spriteIn, PlantsGame* gameIn) : HP(HPIn), x(xIn), y(yIn), Sprite(spriteIn), Game(gameIn)
{
}

bool DynamicObject::IsClose(double xIn, double yIn, double Epsilon)
{
	return distance(x, y, xIn, yIn) < Epsilon;
}

void DynamicObject::lowerHP(double damage)
{
	HP -= damage;
}

void DynamicObject::Draw()
{
	Game->DrawSprite(x, y, Sprite, 1);
}

void DynamicObject::Move(float fElapsedTime)
{
}

bool DynamicObject::isErasable()
{
	return HP <= 0;
}

void DynamicObject::ChangeSprite(olc::Sprite*& SpriteOther)
{
	olc::Sprite* temp = Sprite;
	Sprite = SpriteOther;
	SpriteOther = temp;
}
