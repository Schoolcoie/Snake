#include "Snake.h"
#include "Segment.h"

Snake::Snake()
	:m_Sprite(new Sprite(64, 64, 32, 32))
{
	m_Direction = 1;
	m_Speed = 1;
	m_Segments = vector<Segment*>();
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

void Snake::EatApple()
{
	int PositionX = m_Segments[m_Segments.size()]->GetPosition().first;
	int PositionY = m_Segments[m_Segments.size()]->GetPosition().second;
	vector<int> Direction = m_Segments[m_Segments.size()]->GetDirection();
	m_Segments.push_back(new Segment(PositionX - Direction[0]*32, PositionY - Direction[1]*32, Direction));
}

void Snake::Update()
{
	
}

pair<float, float> Snake::GetPosition()
{
	return make_pair(m_Sprite->GetPositionX(), m_Sprite->GetPositionY());
}

