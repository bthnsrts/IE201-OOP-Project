#pragma once
#include "Card.h"

class CardSmith : public Card
{
public:
    CardSmith(double index, olc::Sprite* SpriteIn, PlantsGame* GameIn, int CostIn);

    void CreateType(double TileX, double TileY, Tile* TileIn);
};