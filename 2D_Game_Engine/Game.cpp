#include <iostream>

#include "SDL.h"
#include "Game.hpp"
#include "TextureManager.hpp"
#include "GameObject.hpp"

GameObject* player, *playerTwo;

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){

	this->counter = 0;
	int flags = 0;

	if (fullscreen) {

		flags = SDL_WINDOW_FULLSCREEN;

	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Initialized yo..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window) {
			std::cout << "Window, more like shmindow..." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer) {
			//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
			std::cout << "Renderer locked and loaded chief..." << std::endl;
		}

		this->isRunning = true;
	} else {
		isRunning = false;
		std::cout << "Got bad news boss, something went wrong in init..." << std::endl;
	}

	player = new GameObject("assets/player.png", renderer, 0, 0);
	

}

void Game::handleEvents() {
	
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_KEYDOWN:
			std::cout << "Key pressed" << std::endl;
			break;

		default:
			break;

	}

	
}

void Game::update() {
	player->Update();
	
}

void Game::render() {

	SDL_RenderClear(renderer);
	/* Add Stuff to be rendered here lol */

		player->Render();
		

	SDL_RenderPresent(renderer);

}

void Game::clean() {
	/* Clean game and exit */
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Freed everything, Later shawty..." << std::endl;

}

bool Game::running() {
	return this->isRunning;
}