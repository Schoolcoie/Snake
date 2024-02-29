#pragma once
#include "Sprite.h"
#include <iostream>
#include <vector>

using namespace std;
class Segment
{
public:
	Segment(SDL_Renderer* graphics, int _posx, int _posy, vector<int> _direction);
	~Segment();
	vector<int> GetDirection();
	pair<float, float> GetPosition();
	void Update();
	void Draw(SDL_Renderer* graphics);

private:
	vector<int> m_Direction;
	Sprite* m_Sprite;
};

