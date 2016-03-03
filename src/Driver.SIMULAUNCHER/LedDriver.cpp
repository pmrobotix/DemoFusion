//drivers...SIMULAUNCHER

#include "LedDriver.hpp"

#include <SDL2/SDL_pixels.h>
#include <sstream>

#include "../SimuLauncher.Main/IWindow.hpp"
#include "../SimuLauncher.Main/LWindows.hpp"
#include "../SimuLauncher.Main/SimLedBar.hpp"
#include "../SimuLauncher.Main/Simulator.hpp"
#include "../SimuLauncher.Main/Text.hpp"

ALedDriver * ALedDriver::create(std::string botName, int nb)
{
	return new LedDriver(botName, nb);
}

LedDriver::LedDriver(std::string botname, int nb)
{
	botId_ = botname;

	std::stringstream stext;
	stext << botId_ << "LED " << nb;

	Simulator &sim = Simulator::instance();

	Text * text = new Text(0, 50, 0, 0);
	SDL_Color textColor =
	{ 100, 100, 100, 0 };
	text->loadMedia(sim.thirdWindow->mRenderer, "./resources/ttf/Verdana/verdanab.ttf", stext.str(),
			28, textColor);
	sim.thirdWindow->addPanel(text);

	SimLedBar * ledbar = new SimLedBar(0, 20, 64, 64);
	ledbar->loadMedia(sim.thirdWindow->mRenderer, "./resources/IHM/play-button4_64_green.svg"
			, ""
			, ""
			, ""
			);

	sim.thirdWindow->addPanel(ledbar);



}

LedDriver::~LedDriver()
{
}

void LedDriver::setBit(int index, int color)
{
	Simulator &sim = Simulator::instance();

}

void LedDriver::setBytes(uint hex, int color)
{
	Simulator &sim = Simulator::instance();

}
