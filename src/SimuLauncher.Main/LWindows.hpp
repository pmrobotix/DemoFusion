#ifndef SIMULAUNCHER_MAIN_LWINDOWS_HPP_
#define SIMULAUNCHER_MAIN_LWINDOWS_HPP_

#include "IWindow.hpp"
#include "LTexture.hpp"

class BotManager;
class DemoButtons;


class MainWindow: public IWindow
{

public:

	bool loadContent(BotManager *botm);
	virtual void render();

private:

	LTexture gBackgroundTextureSvg;
	LTexture gBackgroundTexturePng;
	LTexture gBackgroundTextureMain;

};

class SecondWindow: public IWindow
{

public:

	DemoButtons * dbuttons;

	void buttonHandleEvent(SDL_Event& e);
	bool loadContent(BotManager *botm);

	virtual void render();


private:


	LTexture gBackgroundTextureMainWin1;
};

class ThirdWindow: public IWindow
{

public:

	bool loadContent(BotManager *botm);
	virtual void render();

private:

};

#endif /* SIMULAUNCHER_MAIN_LWINDOWS_HPP_ */
