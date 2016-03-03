/*
 * SimLedBar.hpp
 *
 *  Created on: 2 mars 2016
 *      Author: pmx
 */

#ifndef SIMULAUNCHER_MAIN_SIMLEDBAR_HPP_
#define SIMULAUNCHER_MAIN_SIMLEDBAR_HPP_

#include <SDL2/SDL_rect.h>
#include <string>

#include "LTexture.hpp"
#include "Panel.hpp"

class SimLedBar: public Panel
{

public:

	SimLedBar(int x, int y, int w, int h);

	void handleEvent(SDL_Event& e, int xMouse, int yMouse);

	void render(SDL_Renderer * renderer);

	bool loadMedia(SDL_Renderer * renderer, std::string pathOff, std::string pathGreen, std::string pathRed,
			std::string pathOrange);

private:
	LTexture offTexture_;
	SDL_Rect spriteClip_;

};

#endif
