#include <fstream>
#include <iostream>
#include <winsock.h>

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, SDL_Renderer* ren, int x, int y) {

	std::ifstream in(textureSheet);

	unsigned int width, height;

	in.seekg(16);
	in.read((char*)&width, 4);
	in.read((char*)&height, 4);

	width = ntohl(width);
	height = ntohl(height);

	this->xpos = x;
	this->ypos = y;

	srcRect.h = height;
	srcRect.w = width;
	srcRect.x = srcRect.y = 0;

	dstRect.x = xpos;
	dstRect.y = ypos;
	dstRect.w = 128;
	dstRect.h = 128;

	this->renderer = ren;
	this->objTex = TextureManager::loadTexture(textureSheet, ren);

}

void GameObject::Update() {

	this->xpos++;
	this->ypos++;

	dstRect.x = xpos;
	dstRect.y = ypos;

}

void GameObject::Render() {
	SDL_RenderCopy(this->renderer, this->objTex, &this->srcRect, &this->dstRect);
}