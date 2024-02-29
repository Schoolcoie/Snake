#pragma once
#include "Sprite.h"
#include <iostream>
#include <vector>

class Segment;

using namespace std;

class Snake
{
public:
    Snake();
    ~Snake();
    void EatApple();
    void Update();
    pair<float, float> GetPosition();


private:
    int m_Direction;
    float m_Speed;
    vector<Segment*> m_Segments;
    Sprite* m_Sprite;
};

