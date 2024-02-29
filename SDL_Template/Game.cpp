#include "Game.h"
#include "Sprite.h"
#include <iostream>

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(SDL_Renderer* graphics)
{
	m_Snake = new Snake();
	m_Apple = new Apple();
	m_Snake->GetSprite()->LoadTexture(graphics, "assets/snake.png");
	m_Apple->GetSprite()->LoadTexture(graphics, "assets/apple.png");
}

void Game::Update()
{

}

void Game::Draw(SDL_Renderer* graphics)
{
	m_Snake->GetSprite()->Draw(graphics);
	m_Apple->GetSprite()->Draw(graphics);
}

void Game::HandleKeys(SDL_Keycode keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
	case SDLK_w:
		m_Snake->GetSprite()->SetPosition(0, -32);
		break;
	case SDLK_DOWN:
	case SDLK_s:
		m_Snake->GetSprite()->SetPosition(0, 32);
		break;
	case SDLK_LEFT:
	case SDLK_a:
		m_Snake->GetSprite()->SetPosition(-32, 0);
		break;
	case SDLK_RIGHT:
	case SDLK_d:
		m_Snake->GetSprite()->SetPosition(32, 0);
		break;
	}
}
