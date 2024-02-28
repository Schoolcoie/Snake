#pragma once
#include <SDL_image.h>
#include <string>
class Sprite
{
public:
	Sprite(float x, float y, float w, float h);
	~Sprite();

	bool LoadTexture(SDL_Renderer* renderer, const std::string& filename);

	void Draw(SDL_Renderer* renderer);

	void SetPosition(float x, float y);


private:
	SDL_Texture* m_Texture;

	SDL_Rect* m_Rect;
};
