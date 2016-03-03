#ifndef SIMULAUNCHER_MAIN_BUTTON_HPP_
#define SIMULAUNCHER_MAIN_BUTTON_HPP_

#include "LTexture.hpp"
#include "Panel.hpp"

class LTexture;
struct SDL_Rect;
struct SDL_Renderer;

union SDL_Event;

class IButtonListener;

enum ButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT_ = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION_ = 1,
	BUTTON_SPRITE_MOUSE_DOWN_ = 2,
	BUTTON_SPRITE_MOUSE_UP_ = 3
};

class Button: public Panel
{
public:

	Button(int x, int y, int w, int h);

	void handleEvent(SDL_Event& e, int xMouse, int yMouse);

	void render(SDL_Renderer * renderer);

	bool loadMediaButton(SDL_Renderer * renderer, std::string path, std::string pathMouseOut,
			std::string pathMouseDown, std::string pathMouseUp);

	void setButtonListener(IButtonListener * l)
	{
		listener_ = l;
	}

private:
	IButtonListener* listener_;
	LTexture mouseOutSpriteSheetTexture_;
	LTexture mouseOverSpriteSheetTexture_;
	LTexture mouseDownSpriteSheetTexture_;
	LTexture mouseUpSpriteSheetTexture_;
	SDL_Rect spriteClip_;

	ButtonSprite currentSprite_;
	bool pressleft_;
	bool pressright_;

};

#endif /* SIMULAUNCHER_MAIN_BUTTON_HPP_ */
