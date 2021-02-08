#include "Card.h"
#include "Machine.h"
#include "Smith.h"

Card::Card(double index, olc::Sprite* SpriteIn, PlantsGame* GameIn, int CostIn) : 
    EnvironmentObject(index * STANDARDWIDTH, 0 * STANDARDHEIGTH, SpriteIn, GameIn), 
    IsSelected(false), Cost(CostIn){}

Card::~Card()
{
}

void Card::Draw() {
    Game->FillRect(x, y, 49, 49, olc::WHITE);
    EnvironmentObject::Draw();

    //calculate num digits, this is not optimal since it does this operation every time, it can hold num of digits to get rid of this. However, since it is a very easy calculation it is not a problem.
    int i = Cost;
    int numDigits;
    for (numDigits = 1; i >= 10; numDigits++)
    {
        i = i / 10;
    }
    //calculate num digits
    //Game->DrawString(x + 40 - numDigits * 5, y + 40, to_string(Cost), olc::DARK_RED); //Original format
    double xDraw = x + 49 - numDigits * 8;
    double yDraw = y + 40;
    Game->DrawString(xDraw, yDraw, to_string(Cost), olc::DARK_RED); //each digit holds 8 pixel width, better visuals
}

void Card::Highlight() {
    if (IsSelected == true)
    {
        Game->DrawRect(x, y, 49, 49, olc::RED);
    }
    else
    {
        if (IsIn(Game->GetMouseX(), Game->GetMouseY()))
        {
            Game->DrawRect(x, y, 49, 49, olc::WHITE);
        }

        else
        {
            Game->DrawRect(x, y, 49, 49, olc::BLACK);
        }
    }
}


void Card::Deselect(bool& anyselection) {
    anyselection = anyselection || IsSelected;
    if (IsIn(Game->GetMouseX(), Game->GetMouseY()))
    {
        if (IsSelected) {
            IsSelected = false;
        }
    }
}

void Card::Select(bool& anyselection) {
    if (!anyselection) {
        if (IsIn(Game->GetMouseX(), Game->GetMouseY()))
        {
            if (!IsSelected) { IsSelected = true; }
        }
    }
}

bool Card::IsPlantable()
{
    if (IsSelected && Game->IsEnoughEnergy(Cost))
    {
        IsSelected = false;
        Game->addEnergy(-Cost);
        return true;
    } 
    return false;
}
