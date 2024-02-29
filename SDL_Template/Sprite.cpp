#include "Sprite.h"

Sprite::Sprite(float x, float y, float w, float h)
	: m_Rect(new SDL_Rect())
	, m_Texture(nullptr)
{
	m_Rect->x = x;
	m_Rect->y = y;
	m_Rect->w = w;
	m_Rect->h = h;
}

Sprite::~Sprite()
{
	if (m_Rect != nullptr)
	{
		delete m_Rect;
		m_Rect = nullptr;
	}

	if (m_Texture != nullptr)
	{
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	}
}

bool Sprite::LoadTexture(SDL_Renderer* renderer, const std::string& filename)
{
	m_Texture = IMG_LoadTexture(renderer, filename.c_str());
	if (m_Texture == nullptr)
	{
		SDL_Log("Error loading texture %s", filename.c_str());
		return false;
	}
	return true;
}

void Sprite::Draw(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, m_Texture, nullptr, m_Rect, 0.0, nullptr, SDL_FLIP_NONE);
}

void Sprite::SetPosition(float x, float y)
{
	m_Rect->x = m_Rect->x + x;
	m_Rect->y = m_Rect->y + y;
}

float Sprite::GetPositionX()
{
	return m_Rect->x;
}

float Sprite::GetPositionY()
{
	return m_Rect->y;
}
