/*
 * SimLedBar.cpp
 *
 *  Created on: 2 mars 2016
 *      Author: pmx
 */

#include "SimLedBar.hpp"

#include <cstdio>

#include "../Common/Action.Driver/ALedDriver.hpp"
#include "LTexture.hpp"

struct SDL_Renderer;

SimLedBar::SimLedBar(int x, int y, int w, int h, int nb) :
		Panel(x, y, w, h) //on appelle le constructeur pere
{
	nb_ = nb;

	currentTexture_ = new LTexture[nb_];
}

void SimLedBar::setBit(int i, LedColor color)
{
	if (i < 0 || i >= nb_)
	{
		printf("Error SimLedBar::setBit invalid i= %d", i);
		exit(0);
	}

	switch (color)
	{
	case LED_OFF:
		currentTexture_[i] = offTexture_;
		break;
	case LED_GREEN:
		currentTexture_[i] = greenTexture_;
		break;
	case LED_ORANGE:
		currentTexture_[i] = orangeTexture_;
		break;
	case LED_RED:
		currentTexture_[i] = redTexture_;
		break;
	default:
		printf("Error SimLedBar::setBit no color %d", i);
		exit(0);
	}
}

void SimLedBar::setBytes(uint hex, LedColor color)
{

	for (int i = 0; i < nb_; i++)
	{
		if (((hex >> i) & 0x01) == 1)
		{
			switch (color)
			{

			case LED_GREEN:
				currentTexture_[i] = greenTexture_;
				break;
			case LED_ORANGE:
				currentTexture_[i] = orangeTexture_;
				break;
			case LED_RED:
				currentTexture_[i] = redTexture_;
				break;
			case LED_OFF:
				currentTexture_[i] = offTexture_;
				break;
			default:
				printf("Error SimLedBar::setBytes no color %d\n", i);
				exit(0);
			}
		}
		else
		{
			currentTexture_[i] = offTexture_;
		}
	}
}

void SimLedBar::handleEvent(SDL_Event& e, int xMouse, int yMouse)
{
}

void SimLedBar::render(SDL_Renderer * renderer)
{
	for (int i = 0; i < nb_; ++i)
	{
		currentTexture_[i].render(renderer, x_ + (i * 20), y_, &spriteClip_);
	}
}

bool SimLedBar::loadMedia(SDL_Renderer * renderer, std::string pathOff, std::string pathGreen,
		std::string pathRed, std::string pathOrange)
{
	//Loading success flag
	bool success = true;

	if (!offTexture_.load(renderer, pathOff))
	{
		printf("Error : Failed to load offTexture_ !\n");
		success = false;
	}
	if (!greenTexture_.load(renderer, pathGreen))
	{
		printf("Error : Failed to load greenTexture_ !\n");
		success = false;
	}
	if (!orangeTexture_.load(renderer, pathOrange))
	{
		printf("Error : Failed to load orangeTexture_ !\n");
		success = false;
	}
	if (!redTexture_.load(renderer, pathRed))
	{
		printf("Error : Failed to load redTexture_ !\n");
		success = false;
	}

	//Load sprites
	for (int i = 0; i < nb_; ++i)
	{
		currentTexture_[i] = offTexture_;
	}

	//Set sprites
	spriteClip_.x = 0;
	spriteClip_.y = 0;
	spriteClip_.w = w_;
	spriteClip_.h = h_;

	return success;
}
