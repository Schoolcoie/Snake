#pragma once
#include "Sprite.h"
#include <iostream>
#include <vector>

class Segment;

using namespace std;

class Snake
{
public:
    Snake(SDL_Renderer* graphics);
    ~Snake();
    void EatApple(SDL_Renderer* graphics);
    pair<float, float> GetPosition();
    void SetPosition(float _posx, float _posy);
    void SetDirection(vector<int> _direction);
    void Update();
    void Draw(SDL_Renderer* graphics);


private:
    vector<int> m_Direction;
    float m_Delay;
    vector<Segment*> m_Segments;
    Sprite* m_Sprite;
};

