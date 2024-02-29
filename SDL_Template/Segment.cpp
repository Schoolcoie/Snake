#include "Segment.h"

Segment::Segment(int _posx, int _posy, vector<int> _direction)
	:m_Direction(_direction)
{
	m_Sprite = new Sprite(_posx, _posy, 32, 32); // Location of new segment at the end of the other segments
}

Segment::~Segment()
{
	if (m_Sprite != nullptr)
	{
		delete m_Sprite;
		m_Sprite = nullptr;
	}
}

vector<int> Segment::GetDirection()
{
	return m_Direction;
}

pair<float, float> Segment::GetPosition()
{
	return make_pair(m_Sprite->GetPositionX(), m_Sprite->GetPositionY());
}

Sprite* Segment::GetSprite()
{
	return m_Sprite;
}
