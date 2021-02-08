#pragma once

#include "PlantsGame.h"

class DynamicObject				//Zombie, Sunflower, Peahooter, Sun, Seed	//Dynamic Objects are destructable or constructable through the game
{
private:

protected:
	olc::Sprite* Sprite;

	double HP;
	double x, y;

	PlantsGame* Game;
public:
	DynamicObject(double HPIn, double xIn, double yIn, olc::Sprite* spriteIn, PlantsGame* gameIn);
	virtual ~DynamicObject() {};				//Plants have a destructor which sets the corresponding Tile empty.

	bool IsClose(double x, double y, double Epsilon = 5);

	void lowerHP(double damage);

	virtual void Draw();

	virtual void Move(float fElapsedTime = 0);

	virtual void useSpeciality(float fElapsedTime = 0, DynamicObject* Target = nullptr) = 0;

	virtual bool isErasable();

	void ChangeSprite(olc::Sprite*& SpriteOther);
};
