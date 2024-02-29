#pragma once
#include "Sprite.h"
class Apple
{
public:
	Apple();
	~Apple();
	pair<float, float> GetPosition();

private:
	Sprite* m_Sprite;
};

