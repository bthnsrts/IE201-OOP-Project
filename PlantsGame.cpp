#include "PlantsGame.h"
#include "CardMachine.h"
#include "CardSmith.h"
#include "Smith.h"
#include "Bullet.h"
#include "Energy.h"
#include "Machine.h"
#include "Tile.h"
#include "Human.h"
#include "Neo.h"
#include "Morpheus.h"

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void PlantsGame::createEnergy(double x, double y)
{
    Energies.push_back(new Energy(x, y, energySprite, this));
}

void PlantsGame::createBullet(double x, double y)
{
    Bullets.push_back(new Bullet(x, y, bulletSprite, this));
}

void PlantsGame::createMachine(double x, double y, Tile* TileIn)
{
    Plants.push_back(new Machine(x, y, machineSprite, this, TileIn));
}

void PlantsGame::createSmith(double x, double y, Tile* TileIn)
{
    Plants.push_back(new Smith(x, y, smithSprite, this, TileIn));
}

void PlantsGame::ObjectUpdate(float fElapsedTime)
{
    //Human Spawns
    if (spawnCD < 0) {
        int s = (rand() % 4)+1;
         
        Humans.push_back(new Human(ScreenWidth(), s*50,humanSprite, this));
        spawnCD = spawnRate;
    }
    if (gameTime < 5) { spawnCD -= fElapsedTime; }
    else if (gameTime < 10) { spawnCD -= fElapsedTime * 2; }
    else if (gameTime < 15) { spawnCD -= fElapsedTime * 3; }
    else { spawnCD -= fElapsedTime * 4; }
    //Human Spawns

    // Neo Spawns
    if (NeospawnCD < 0) {
        int s = (rand() % 4) + 1;
        Humans.push_back(new Neo(ScreenWidth(),s*50, neoSprite, neoSprite2, this));
        NeospawnCD = NeospawnRate;
    }
    
    if (gameTime < 15) { NeospawnCD -= fElapsedTime; }
    else { NeospawnCD -= fElapsedTime * 2; }
    //Neo Spawns

    //Morpheus Spawns
    if (MspawnCD < 0) {
        int s = (rand() % 4) + 1;
        Humans.push_back(new Morpheus(ScreenWidth(), s*50, morpheusSprite, this));
        MspawnCD = MspawnRate;
    }
    
    if (gameTime < 10) { MspawnCD -= fElapsedTime ; }
    else if (gameTime < 15) { MspawnCD -= fElapsedTime ; }
    else { MspawnCD -= fElapsedTime ; }
    //Morpheus Spawns


    //Zombie Move & Attack
    for (auto z : Humans) {
        for (auto p : Plants)
        {
            z->useSpeciality(fElapsedTime, p);
        }
        z->Move(fElapsedTime);
        for (auto s : Bullets)
        {
            z->SpecialPower(s); 
        }
    }
    //Zombie Move & Attack

    //Plants Speciality
    for (auto S : Plants)
    {
        S->useSpeciality(fElapsedTime);     //  Peashooter Attack   //  Sunflower Sun Creation
    }
    //Plants Speciality

    //Bullets Move & Attack
    for (int i = 0; i < Bullets.size(); i++) {
        for (auto z : Humans)
        {
            Bullets[i]->useSpeciality(fElapsedTime, z);
        }
        Bullets[i]->Move(fElapsedTime);

        //Delete Seed if it hits
        //Also if it passes screen, Bullets disappear
        if (Bullets[i]->isErasable())
        {
            delete Bullets[i];
            Bullets.erase(Bullets.begin() + i);
            i--;
        }
    }
    //Bullets Move & Attack

    //Plants death
    for (int i = 0; i < Plants.size(); i++) {
        if (Plants[i]->isErasable()) {
            delete Plants[i];
            Plants.erase(Plants.begin() + i);
            i--;
        }
    }
    //Plants death
    
    //Humans death
    for (int i = 0; i < Humans.size(); i++) {
        if (Humans[i]->isErasable()) {
            delete Humans[i];
            Humans.erase(Humans.begin() + i);
            i--;
        }
    }
    //Humans death
}

void PlantsGame::DrawFrame()
{
    //Drawing the background
    Clear(olc::DARK_GREY);
    FillRect(0, 0, 300, 50, olc::BLACK);
    SetPixelMode(olc::Pixel::ALPHA);
    //Drawing the background

    //Drawing the tiles
    for (auto a : Tiles)
    {
        a->Draw();          //  This draws tile borders, if full black, if empty grey 
    }
    //Drawing the tiles

    //Drawing the cards
    for (auto a : Cards)
    {
        a->Draw();
    }
    //Drawing the cards

    //Drawing the remaining sun 
    DrawSprite(ScreenWidth() - 50, 0, energySprite, 1);
    DrawString(ScreenWidth() - 35, 40, to_string(CurrentEnergy), olc::WHITE);
    //Drawing the remaining sun

    //Seed Draw
    for (auto i : Bullets) {
        i->Draw();
    }
    //Seed Draw

    //Plant Draw
    for (auto i : Plants) 
    {
        i->Draw();          //  Peashooter Draw //  Sunflower Draw
    }
    //Plant Draw
    
    //Zombie Draw
    for (auto i : Humans) {
        i->Draw();
    }
    //Zombie Draw

    //Sun Draw
    for (auto i : Energies) {
        i->Draw();
    }
    //Sun Draw
}

void PlantsGame::MouseOperate()
{
    //Mouse operations

    //Highlight
    for (auto a : Tiles)
    {
        a->Highlight();     //  This changes border colour if mouse hovered over 
    }

    for (auto a : Cards)
    {
        a->Highlight();
    }
    //Highlight

    if (GetMouse(0).bPressed) 
    {
        // Selecting-Deselecting Card

        //Deselect
        bool anyselection = false;
        for (auto a : Cards) {
            a->Deselect(anyselection);

        }
        //Deselect

        //Select
        for (auto a : Cards) {
            a->Select(anyselection);
        }
        //Select

        // Selecting-Deselecting Card


        //Planting 
        for (auto a : Tiles) 
        {
            for (auto b : Cards)
            {
                a->Plant(b);
            }
        }
        //Planting   

        //Collecting Sun
        for (int i = 0; i < Energies.size(); i++) {
            Energies[i]->useSpeciality();
            if (Energies[i]->isErasable())
            {
                delete Energies[i];
                Energies.erase(Energies.begin() + i);
                i--;
            }
        }
        //Collecting Sun

    }
    //Mouse operation
}

bool PlantsGame::OnUserCreate() //override
{
    humanSprite = new olc::Sprite("Sprites/human.png");
    machineSprite = new olc::Sprite("Sprites/Factory.png");
    smithSprite = new olc::Sprite("Sprites/Agent.png");
    energySprite = new olc::Sprite("Sprites/Power.png");
    bulletSprite = new olc::Sprite("Sprites/Bullet.png");
    morpheusSprite = new olc::Sprite("Sprites/morpheus.png");
    neoSprite = new olc::Sprite("Sprites/Neo_v2.png");
    neoSprite2 = new olc::Sprite("Sprites/Neo-Sideways_v2.png");
    
    gameTime = 0;
    gameEnd = false;
    gamePause = false;

    //Create Tiles
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            Tiles.push_back(new Tile((i - 1) * STANDARDWIDTH, j * STANDARDHEIGTH, this));
        }

    }
    //Create Tiles

    //Create Cards
    Cards.push_back(new CardMachine(0, machineSprite, this, 50));    //Cost 50
    Cards.push_back(new CardSmith(1, smithSprite, this, 100)); //Cost 100
    //Create Cards

    //Initialization for zombies
    spawnCD = 7;
    spawnRate = 5;
    NeospawnCD = 20;
    NeospawnRate = 23;
    MspawnCD = 15;
    MspawnRate = 10;

    CurrentEnergy = 100;

    return true;
}

bool PlantsGame::OnUserUpdate(float fElapsedTime) //override
{
    gameTime += fElapsedTime;
   
    //GAME END SCREEN
    if (gameEnd) {
        Clear(olc::BLACK);
        DrawString(110, 10, "GAME OVER", olc::WHITE);

        FillRect(100, 90, 100, 50, olc::DARK_GREY);
        DrawString(110, 110, "PLAY AGAIN", olc::WHITE);
        FillRect(100, 150, 100, 50, olc::DARK_RED);
        DrawString(135, 170, "EXIT", olc::WHITE);
        SetPixelMode(olc::Pixel::ALPHA);
        if (GetMouseX() >= 100 && GetMouseX() <= 200 && GetMouseY() >= 90 && GetMouseY() <= 140)
        {
            FillRect(100, 90, 100, 50, olc::WHITE);
            DrawString(110, 110, "PLAY AGAIN", olc::DARK_GREY);

            if (GetMouse(0).bReleased)
            {
                OnUserCreate();

            }
        }
        if (GetMouseX() >= 100 && GetMouseX() <= 200 && GetMouseY() >= 150 && GetMouseY() <= 200)
        {
            FillRect(100, 150, 100, 50, olc::WHITE);
            DrawString(135, 170, "EXIT", olc::DARK_RED);

            if (GetMouse(0).bReleased)
            {
                return false;
            }
        }

        return true;
    }
    //GAME END SCREEN


    //GAME PAUSE
    if (GetKey(olc::Key::P).bPressed) {
        gamePause = true;
    }
    if (gamePause == true)
    {
        Clear(olc::BLACK);
        FillRect(100, 100, 100, 50, olc::DARK_GREY);
        DrawString(90, 10, "MATRIX PAUSED", olc::WHITE);
        DrawString(120, 120, "CONTINUE", olc::WHITE);
        SetPixelMode(olc::Pixel::ALPHA);
        if (GetMouseX() >= 100 && GetMouseX() <= 200 && GetMouseY() >= 100 && GetMouseY() <= 150)
        {
            FillRect(100, 100, 100, 50, olc::WHITE);
            DrawString(120, 120, "CONTINUE", olc::DARK_GREY);

            if (GetMouse(0).bReleased)
            {
                gamePause = false;
            }
        }
        return true;
    }
    //GAME PAUSE

    ObjectUpdate(fElapsedTime);
    DrawFrame();
    MouseOperate();

    //Exit game if pressed E or any zombie passes the left line
    if (GetKey(olc::E).bPressed) {
        gameEnd = true;
    }

    for (auto a : Humans) {
        if (a->DidZombiePass()) 
        {
            if (gameTime < 60)
            {
                cout << "You have survived " << gameTime << ", seconds. Thats not that good." << endl;
            }
            else if (gameTime < 120)
            {
                cout << "You have survived " << gameTime << ", seconds. Not bad." << endl;
            }
            else
            {
                cout << "You have survived " << gameTime << ", seconds. Thats impressive." << endl;
            }
            gameEnd = true; 
        }
    }

    //Deletings
    if (gameEnd) {

        for (int i = 0; i < Humans.size(); i++) {
            delete Humans[i];
            Humans.erase(Humans.begin() + i);
            i--;
        }

        for (int i = 0; i < Plants.size(); i++) {
            delete Plants[i];
            Plants.erase(Plants.begin() + i);
            i--;
        }

        for (int i = 0; i < Energies.size(); i++) {
            delete Energies[i];
            Energies.erase(Energies.begin() + i);
            i--;
        }

        for (int i = 0; i < Bullets.size(); i++) {
            delete Bullets[i];
            Bullets.erase(Bullets.begin() + i);
            i--;
        }


        for (int i = 0; i < Tiles.size(); i++) {
            delete Tiles[i];
            Tiles.erase(Tiles.begin() + i);
            i--;
        }

        for (int i = 0; i < Cards.size(); i++) {
            delete Cards[i];
            Cards.erase(Cards.begin() + i);
            i--;
        }

        delete humanSprite;
        delete machineSprite;
        delete smithSprite;
        delete energySprite;
        delete bulletSprite;

        delete morpheusSprite;
        delete  neoSprite;
        delete  neoSprite2;


        return true;
    }
    //Deletings

    //Exit game if pressed E or any zombie passes the left line

    return true;
}
