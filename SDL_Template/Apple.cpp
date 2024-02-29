#include "Apple.h"


Apple::Apple(SDL_Renderer* graphics)
	:m_Sprite(new Sprite(0, 0, 32, 32)) //Random range somewhere within the screen for position
{
	m_Sprite->LoadTexture(graphics, "assets/apple.png");
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


void Apple::Draw(SDL_Renderer* graphics)
{
	m_Sprite->Draw(graphics);
}
