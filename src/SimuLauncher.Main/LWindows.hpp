#ifndef SIMULAUNCHER_MAIN_LWINDOWS_HPP_
#define SIMULAUNCHER_MAIN_LWINDOWS_HPP_

#include "IWindow.hpp"
#include "LTexture.hpp"

class BotManager;
class DemoButtons;


class MainWindow: public IWindow
{
private:

	LTexture gBackgroundTextureSvg;
	LTexture gBackgroundTexturePng;
	LTexture gBackgroundTextureMain;

public:

	bool loadContent(BotManager *botm);
	virtual void render();


};

class SecondWindow: public IWindow
{

private:

	LTexture gBackgroundTextureMainWin1;

public:

	DemoButtons * dbuttons;

	void buttonHandleEvent(SDL_Event& e);
	bool loadContent(BotManager *botm);

	virtual void render();



};

class ThirdWindow: public IWindow
{
private:

public:

	bool loadContent(BotManager *botm);
	virtual void render();



};

#endif /* SIMULAUNCHER_MAIN_LWINDOWS_HPP_ */
