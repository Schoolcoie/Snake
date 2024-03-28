#include "Segment.h"

Segment::Segment(SDL_Renderer* graphics, int _posx, int _posy, vector<int> _direction)
	:m_Direction(_direction)
{
	m_Sprite = new Sprite(_posx, _posy, 32, 32); // Location of new segment at the end of the other segments
	m_Sprite->LoadTexture(graphics, "assets/segment.png");
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

void Segment::SetDirection(vector<int> direction)
{
	m_Direction = direction;
}

void Segment::MovePosition(float _posx, float _posy)
{
	m_Sprite->MovePosition(_posx, _posy);
}

pair<float, float> Segment::GetPosition()
{
	return make_pair(m_Sprite->GetPositionX(), m_Sprite->GetPositionY());
}

void Segment::Update()
{
}

void Segment::Draw(SDL_Renderer* graphics)
{
	m_Sprite->Draw(graphics);
}
