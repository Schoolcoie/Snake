#pragma once
#include "Sprite.h"
#include <iostream>

using namespace std;

class Apple
{
public:
	Apple(SDL_Renderer* graphics);
	~Apple();
	pair<float, float> GetPosition();
	void Draw(SDL_Renderer* graphics);
	SDL_Rect* GetRect();
	void Spawn();

private:
	Sprite* m_Sprite;
};

