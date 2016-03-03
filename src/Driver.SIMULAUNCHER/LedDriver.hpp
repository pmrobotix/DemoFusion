#ifndef SIMULAUNCHER_LEDDRIVER_HPP_
#define SIMULAUNCHER_LEDDRIVER_HPP_

#include <string>

#include "../Common/Action.Driver/ALedDriver.hpp"
#include "../Common/Utils/Macro.hpp"

class LedDriver: public ALedDriver
{

public:



	virtual void setBit(int position, int color);

	virtual void setBytes(uint hexPosition, int color);

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


};

#endif
