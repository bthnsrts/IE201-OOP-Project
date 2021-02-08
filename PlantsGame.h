#pragma once
#include "olcSimpleEngine.h"
#include "vector"



using namespace std;

double distance(double x1, double y1, double x2, double y2);

class DynamicObject;
class Human;
class Tile;
class Card;
class Energy;
class Bullet;

class PlantsGame : public olc::PixelGameEngine {
private:
    double gameTime;
    bool gameEnd;
    bool gamePause;

    bool AnyCardSelected;
    int CurrentEnergy;

    olc::Sprite* humanSprite;
    olc::Sprite* machineSprite;
    olc::Sprite* smithSprite;
    olc::Sprite* energySprite;
    olc::Sprite* bulletSprite;
    olc::Sprite* morpheusSprite;
    olc::Sprite* neoSprite;
    olc::Sprite* neoSprite2;

    vector<DynamicObject*> Plants;          //Sunflowers and Peashooters

    vector<Energy*> Energies;
    vector<Bullet*> Bullets;
    
    vector<Human*> Humans;

    vector<Tile*> Tiles;
    vector<Card*> Cards;

    

    float spawnCD, spawnRate;               //Human spawn timers
    float NeospawnCD, NeospawnRate;         //Neo spawn timers
    float MspawnCD, MspawnRate;         //Morpheus spawn timers
    void ObjectUpdate(float fElapsedTime);
    void DrawFrame();
    void MouseOperate();
public:
   

    void createEnergy(double x, double y);
    void createBullet(double x, double y);

    void createMachine(double x, double y, Tile* TileIn);
    void createSmith(double x, double y, Tile* TileIn);

    int IsEnoughEnergy(int cost) { return cost <= CurrentEnergy; }
    void addEnergy(int SunIn) { CurrentEnergy += SunIn; }
    
    bool OnUserCreate();
    bool OnUserUpdate(float fElapsedTime);
};