#ifndef SIMULAUNCHER_LEDDRIVER_HPP_
#define SIMULAUNCHER_LEDDRIVER_HPP_

#include <iostream>
#include <string>

#include "../Common/Action.Driver/ALedDriver.hpp"
#include "../Common/Utils/Macro.hpp"
#include "../SimuLauncher.Main/SDLTask.hpp"

class SimLedBar;

int nb_leddriver = 0;

class LedDriver: public ALedDriver
{

public:

	virtual void setBit(int position, LedColor color);

	virtual void setBytes(uint hexPosition, LedColor color);

	void load();

	/*!
	 * \brief Constructor.
	 */
	LedDriver(std::string botname, int nb);

	/*!
	 * \brief Destructor.
	 */
	virtual ~LedDriver();

private:
	//id of the current robot
	std::string botId_;

	int height_display_;

	SimLedBar * ledbar_;

	int nb_;

	std::string text_;
};

class LedDriverSDLTask : public SDLTask
{
public:
	LedDriverSDLTask(LedDriver *leddriver);

	void run();

	LedDriver *leddriver_;
};


#endif
