#pragma once
#include <SDL_image.h>
#include <iostream>
#include <string>
class Sprite
{
public:
	Sprite(float x, float y, float w, float h);
	~Sprite();

	bool LoadTexture(SDL_Renderer* renderer, const std::string& filename);

	void Draw(SDL_Renderer* renderer);

	void MovePosition(float x, float y);
	void SetPosition(float x, float y);
	float GetPositionX();
	float GetPositionY();
	SDL_Rect* GetRect();


private:
	SDL_Texture* m_Texture;

	SDL_Rect* m_Rect;
};

