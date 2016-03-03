/*
 * SimLedBar.cpp
 *
 *  Created on: 2 mars 2016
 *      Author: pmx
 */

#include "SimLedBar.hpp"

#include <cstdio>
#include <string>

struct SDL_Renderer;


SimLedBar::SimLedBar(int x, int y, int w, int h) :
		Panel(x, y, w, h) //on appelle le constructeur pere
{

}

void SimLedBar::handleEvent(SDL_Event& e, int xMouse, int yMouse)
{

}

void SimLedBar::render(SDL_Renderer * renderer)
{
	offTexture_.render(renderer, x_, y_, &spriteClip_);

}

bool SimLedBar::loadMedia(SDL_Renderer * renderer, std::string pathOff, std::string pathGreen,
		std::string pathRed, std::string pathOrange)
{
	//Loading success flag
	bool success = true;

	//Load sprites
	if (!offTexture_.load(renderer, pathOff))
	{
		printf("Error : Failed to load offTexture_ !\n");
		success = false;
	}

	//Set sprites
	spriteClip_.x = 0;
	spriteClip_.y = 0;
	spriteClip_.w = w_;
	spriteClip_.h = h_;

	return success;
}
