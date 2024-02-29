#pragma once
#include "SDL.h"
#include "Snake.h"
#include "Apple.h"

class Sprite;

class Game
{

public:
	Game();
	~Game();

	void Init(SDL_Renderer* graphics);

	void Update();
	void Draw(SDL_Renderer* graphics);
	void HandleKeys(SDL_Keycode keyCode);

private:
	Snake* m_Snake;
	Apple* m_Apple;
};

