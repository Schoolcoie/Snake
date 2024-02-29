#pragma once
#include "Sprite.h"
#include <iostream>
#include <vector>

using namespace std;
class Segment
{
public:
	Segment(int _posx, int _posy, vector<int> _direction);
	~Segment();
	vector<int> GetDirection();
	pair<float, float> GetPosition();
	Sprite* GetSprite();

private:
	vector<int> m_Direction;
	Sprite* m_Sprite;
};

