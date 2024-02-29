#include "Apple.h"
#include <iostream>

using namespace std;

Apple::Apple()
	:m_Sprite(new Sprite(0, 0, 32, 32)) //Random range somewhere within the screen for position
{
}

Apple::~Apple()
{
	if (m_Sprite != nullptr)
	{
		delete m_Sprite;
		m_Sprite = nullptr;
	}
}

pair<float, float> Apple::GetPosition()
{
	return make_pair(m_Sprite->GetPositionX(), m_Sprite->GetPositionY());
}
