#pragma once
#include "Card.h"

class CardMachine : public Card
{
public:
    CardMachine(double index, olc::Sprite* SpriteIn, PlantsGame* GameIn, int CostIn);

    void CreateType(double TileX, double TileY, Tile* TileIn);
};