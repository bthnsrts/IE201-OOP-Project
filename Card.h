#pragma once

#include "EnvironmentObject.h"
#include <string>



class Card : public EnvironmentObject
{
private:
    int Cost;
	bool IsSelected;
    
public:
    Card(double index, olc::Sprite* SpriteIn, PlantsGame* GameIn, int CostIn);
    virtual ~Card();

    void Draw();
    void Highlight();
    void Deselect(bool& anyselection);
    void Select(bool& anyselection);
    bool IsPlantable();
    
    virtual void CreateType(double TileX, double TileY, Tile* TileIn) = 0;
};