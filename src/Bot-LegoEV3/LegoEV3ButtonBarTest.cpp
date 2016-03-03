/*!
 * \file
 * \brief Implémentation de la classe LedBarTest.
 */

#include "LegoEV3ButtonBarTest.hpp"

#include <string>

#include "../Common/Action/ButtonBar.hpp"
#include "../Common/Action.Driver/AButtonDriver.hpp"
#include "../Log/Logger.hpp"
#include "LegoEV3ActionsExtended.hpp"
#include "LegoEV3RobotExtended.hpp"


using namespace std;

void LegoEV3ButtonBarTest::run(Arguments *)
{
	logger().info() << "Executing - " << this->desc() << logs::end;

	LegoEV3RobotExtended &robot = LegoEV3RobotExtended::instance();

	logger().info() << "Please press ENTER" << logs::end;
	robot.actions().buttonBar().waitPressed(BUTTON_ENTER_KEY);

	logger().info() << "Please press BACK" << logs::end;
	robot.actions().buttonBar().waitPressed(BUTTON_BACK_KEY);


	logger().info() << "Happy End." << logs::end;
}

