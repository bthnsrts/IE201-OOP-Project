#include "Tile.h"
#include "Card.h"
#include "Machine.h"
#include "Smith.h"

Tile::Tile(int xIn, int yIn, PlantsGame* gameIn) :EnvironmentObject(xIn, yIn, nullptr, gameIn), IsFull(false) {}

void Tile::Draw()
{
    if (IsFull)
    {
        Game->DrawRect(x, y, 49, 49, olc::BLACK);
    }
    else
    {
        Game->DrawRect(x, y, 49, 49, olc::VERY_DARK_GREY);
    }
}

void Tile::Highlight()
{
    if (IsIn(Game->GetMouseX(), Game->GetMouseY()))
    {
        Game->DrawRect(x, y, 49, 49, olc::WHITE);
    }
}

void Tile::Plant(Card* Card)
{
    if (IsIn(Game->GetMouseX(), Game->GetMouseY())) 
    {
        if (!IsFull) 
        {    
            if (Card->IsPlantable())
            {
                Card->CreateType(x, y, this);
                IsFull = TRUE;
            }
        }
    }
}

void Tile::setEmpty()
{
    IsFull = false;
}

