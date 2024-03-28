#include "Snake.h"
#include "Segment.h"
#include <Windows.h>

Snake::Snake(SDL_Renderer* graphics)
	:m_Sprite(new Sprite(64, 64, 32, 32))
{
	m_Direction = {0, 0};
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
	if (m_Segments.size() == 0)
	{
		int PositionX = GetPosition().first - m_Direction[0];
		int PositionY = GetPosition().second - m_Direction[1];
		m_Segments.push_back(new Segment(graphics, PositionX, PositionY, m_Direction));
	}
	else
	{
		int PositionX = m_Segments[m_Segments.size()-1]->GetPosition().first - m_Segments[m_Segments.size()-1]->GetDirection()[0];
		int PositionY = m_Segments[m_Segments.size()-1]->GetPosition().second - m_Segments[m_Segments.size()-1]->GetDirection()[1];
		vector<int> Direction = m_Segments[m_Segments.size()-1]->GetDirection();
		m_Segments.push_back(new Segment(graphics, PositionX, PositionY, Direction));
	}

}

pair<float, float> Snake::GetPosition()
{
	return make_pair(m_Sprite->GetPositionX(), m_Sprite->GetPositionY());
}

void Snake::MovePosition(float _posx, float _posy)
{
	m_Sprite->MovePosition(_posx, _posy);
}

void Snake::SetDirection(vector<int> _direction)
{
	m_Direction = _direction;
}

void Snake::Update()
{
	MovePosition(m_Direction[0], m_Direction[1]);

	for (int i = 0; i < m_Segments.size(); i++)
	{
		if (m_Segments.size() == 0)
		{
			m_Segments[i]->SetDirection(m_Direction);
			
		}
		else
		{
			m_Segments[i]->MovePosition(m_Direction[0], m_Direction[1]);
		}

		//m_Segments[i]->MovePosition(m_Segments[i]->GetDirection()[0], m_Segments[i]->GetDirection()[1]);
	}
	//Set direction of segments
	//Move segments
}

void Snake::Draw(SDL_Renderer* graphics)
{
	m_Sprite->Draw(graphics);
	for (int i = 0; i < m_Segments.size(); i++)
	{
		m_Segments[i]->Draw(graphics);
	}
}

SDL_Rect* Snake::GetRect()
{
	return m_Sprite->GetRect();
}

