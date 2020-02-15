#pragma once

#include "Game.hpp"

#ifndef GameObject_HPP
#define GameObject_HPP

class GameObject {

public:
	GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:

	//position of this bad boy on screen.
	int xpos;
	int ypos;

	SDL_Texture* objTex;
	SDL_Rect srcRect, dstRect;
	SDL_Renderer* renderer;

};

#endif