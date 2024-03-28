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

	void Update(SDL_Renderer* graphics);
	void Draw(SDL_Renderer* graphics);
	void HandleKeys(SDL_Keycode keyCode);

	static const int SCREEN_WIDTH;
	static const int SCREEN_HEIGHT;

private:
	Snake* m_Snake;
	Apple* m_Apple;
	float m_OldTime;
	float m_NewTime;
	float m_DelayTimer;
	float m_MoveDelay;
};

