#include "Game.h"
#include "Sprite.h"
#include <iostream>
#include <windows.h>

const int Game::SCREEN_WIDTH = 1024;
const int Game::SCREEN_HEIGHT = 1024;

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
	m_OldTime = 0;
	m_NewTime = 0;
	m_MoveDelay = 250;
}

void Game::Update(SDL_Renderer* graphics)
{
	m_NewTime = SDL_GetTicks();

	float delta = m_NewTime - m_OldTime;


	if (m_DelayTimer > m_MoveDelay)
	{
		m_Snake->Update();

		if (SDL_HasIntersection(m_Snake->GetRect(), m_Apple->GetRect()))
		{
			m_Snake->EatApple(graphics);
			m_Apple->Spawn();
			m_MoveDelay *= 0.9;
		}

		// calculate collisions between the snake and its segments

		if (m_Snake->GetPosition().first >= SCREEN_WIDTH || m_Snake->GetPosition().first < 0) //replace hardcoded values with screen size
		{
			std::cout << "You lose";
		}

		if (m_Snake->GetPosition().second >= SCREEN_HEIGHT || m_Snake->GetPosition().second < 0)
		{
			std::cout << "You lose";
		}

		m_DelayTimer = 0;
	}
	else
	{
		m_DelayTimer += delta;
	}

	SDL_Delay(1);

	m_OldTime = m_NewTime;
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
		m_Snake->SetDirection({0, -32});
		break;
	case SDLK_DOWN:
	case SDLK_s:
		m_Snake->SetDirection({0, 32});
		break;
	case SDLK_LEFT:
	case SDLK_a:
		m_Snake->SetDirection({-32, 0});
		break;
	case SDLK_RIGHT:
	case SDLK_d:
		m_Snake->SetDirection({32, 0});
		break;
	}
}
