#include "CardMachine.h"

CardMachine::CardMachine(double index, olc::Sprite* SpriteIn, PlantsGame* GameIn, int CostIn):Card(index, SpriteIn, GameIn, CostIn)
{
}

void CardMachine::CreateType(double TileX, double TileY, Tile* TileIn)
{
	Game->createMachine(TileX, TileY, TileIn);
}
