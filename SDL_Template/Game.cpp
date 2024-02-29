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
	m_Snake = new Snake(graphics);
	m_Apple = new Apple(graphics);
}

void Game::Update()
{
	m_Snake->Update();
}

void Game::Draw(SDL_Renderer* graphics)
{
	m_Snake->Draw(graphics);
	m_Apple->Draw(graphics);

}

void Game::HandleKeys(SDL_Keycode keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
	case SDLK_w:
		m_Snake->SetDirection({0, -1});
		break;
	case SDLK_DOWN:
	case SDLK_s:
		m_Snake->SetDirection({0, 1});
		break;
	case SDLK_LEFT:
	case SDLK_a:
		m_Snake->SetDirection({-1, 0});
		break;
	case SDLK_RIGHT:
	case SDLK_d:
		m_Snake->SetDirection({1, 0});
		break;
	}
}
