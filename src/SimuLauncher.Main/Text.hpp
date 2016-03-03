#ifndef SIMULAUNCHER_TEXT_HPP_
#define SIMULAUNCHER_TEXT_HPP_

#include <SDL2/SDL_ttf.h>

#include "LTexture.hpp"
#include "Panel.hpp"

class IButtonListener;
union SDL_Event;
struct SDL_Renderer;

class Text: public Panel
{
public:

	Text(int x, int y, int w, int h);

	void handleEvent(SDL_Event& e, int xMouse, int yMouse);

	void render(SDL_Renderer * renderer);

	bool loadMedia(SDL_Renderer * renderer, std::string ttf_path, std::string text, int ptsize, SDL_Color textColor);

	void setButtonListener(IButtonListener * l)
	{
		listener_ = l;
	}

private:
	IButtonListener* listener_;

	//Globally used font
	TTF_Font *gFont;
	LTexture texture_;

	bool pressleft_;
	bool pressright_;

};

#endif
