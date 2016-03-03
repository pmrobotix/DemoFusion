/*
 * Text.cpp
 *
 *  Created on: 11 févr. 2016
 *      Author: pmx
 */

#include "Text.hpp"

Text::Text(int x, int y, int w, int h) : Panel(x, y, w, h)
{
	listener_ = NULL;
	pressleft_ = false;
	pressright_ = false;

	gFont = NULL;
}

void Text::handleEvent(SDL_Event& e, int xMouse, int yMouse)
{

}


void Text::render(SDL_Renderer * renderer)
{
	texture_.render(renderer, x_, y_);
}


bool Text::loadMedia(SDL_Renderer * renderer, std::string ttf_path, std::string text, int ptsize, SDL_Color textColor)
{
	//Loading success flag
	bool success = true;

	//Open the font
	gFont = TTF_OpenFont( ttf_path.c_str(), ptsize);
	if( gFont == NULL )
	{
		printf( "Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError() );
		success = false;
	}
	else
	{
		//Render text
		//SDL_Color textColor = { 0, 0, 0 };
		if( !texture_.loadFromRenderedText(renderer, gFont, text, textColor ) )
		{
			printf( "Failed to render text texture!\n" );
			success = false;
		}
	}

	return success;
}
