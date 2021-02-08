#include "CardSmith.h"

CardSmith::CardSmith(double index, olc::Sprite* SpriteIn, PlantsGame* GameIn, int CostIn) :Card(index, SpriteIn, GameIn, CostIn)
{
}

void CardSmith::CreateType(double TileX, double TileY, Tile* TileIn)
{
	Game->createSmith(TileX, TileY, TileIn);
}
