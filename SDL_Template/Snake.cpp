#include "Snake.h"
#include "Segment.h"
#include <Windows.h>

Snake::Snake(SDL_Renderer* graphics)
	:m_Sprite(new Sprite(64, 64, 32, 32))
{
	m_Direction = {1, 0};
	m_Delay = 30;
	m_Segments = vector<Segment*>();
	m_Sprite->LoadTexture(graphics, "assets/snake.png");
}

Snake::~Snake()
{
	if (m_Sprite != nullptr)
	{
		delete m_Sprite;
		m_Sprite = nullptr;
	}

	for (int i = 0; i < m_Segments.size(); i++)
	{
		if (m_Segments[i] != nullptr)
		{
			delete m_Segments[i];
			m_Segments[i] = nullptr;
		}
	}
}

void Snake::EatApple(SDL_Renderer* graphics)
{
	int PositionX = m_Segments[m_Segments.size()]->GetPosition().first;
	int PositionY = m_Segments[m_Segments.size()]->GetPosition().second;
	vector<int> Direction = m_Segments[m_Segments.size()]->GetDirection();
	m_Segments.push_back(new Segment(graphics, PositionX - Direction[0]*32, PositionY - Direction[1]*32, Direction));
}

pair<float, float> Snake::GetPosition()
{
	return make_pair(m_Sprite->GetPositionX(), m_Sprite->GetPositionY());
}

void Snake::SetPosition(float _posx, float _posy)
{
	m_Sprite->SetPosition(_posx, _posy);
}

void Snake::SetDirection(vector<int> _direction)
{
	m_Direction = _direction;
}

void Snake::Update()
{
	//Sleep(m_Delay);
	SetPosition(m_Direction[0], m_Direction[1]);
}

void Snake::Draw(SDL_Renderer* graphics)
{
	m_Sprite->Draw(graphics);
}

