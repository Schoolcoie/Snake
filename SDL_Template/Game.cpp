#include "Game.h"
#include "Sprite.h"
#include <iostream>

Game::Game()
	: m_Sprite(new Sprite(60, 60, 100, 100))
{
}

Game::~Game()
{
	if (m_Sprite != nullptr)
	{
		delete m_Sprite;
		m_Sprite = nullptr;
	}
}

void Game::Init(SDL_Renderer* graphics)
{
	m_Sprite->LoadTexture(graphics, "assets/enemy.png");
}

void Game::Update()
{

}

void Game::Draw(SDL_Renderer* graphics)
{
	m_Sprite->Draw(graphics);
}

void Game::HandleKeys(SDL_Keycode keyCode)
{
	switch (keyCode)
	{
	case SDLK_UP:
	case SDLK_w:
		m_Sprite->SetPosition(0, -5);
		break;
	case SDLK_DOWN:
	case SDLK_s:
		m_Sprite->SetPosition(0, 5);
		break;
	case SDLK_LEFT:
	case SDLK_a:
		m_Sprite->SetPosition(-5, 0);
		break;
	case SDLK_RIGHT:
	case SDLK_d:
		m_Sprite->SetPosition(5, 0);
		break;
	}
}
