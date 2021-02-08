//olcPixelGameEngine is being developed and shared for education purposes by javidx9 in OneLoneCoder Youtube Channel:
//https://www.youtube.com/channel/UC-yuWVUplUJZvieEligKBkA/about
//olcSimpleEngine is based on olcPixelGameEngine and simplified and modified by Bahadir Pamuk for IE201 course in Industrial Engineering Department of Bogazici University
//olcSimpleEngine.cpp is created in order to resolve object orientation issues, from now on sprites (from olc::Sprite) can be created inside other classes, independently
//olcSimpleEngine.cpp is updated so that they are compatible with shared_ptr's.
//Last Edit Date: 03.02.2020

#include "PlantsGame.h"

int main()
{
    PlantsGame demo;
    if (demo.Construct(300, 250, 3, 3))
        demo.Start();

    return 0;
}