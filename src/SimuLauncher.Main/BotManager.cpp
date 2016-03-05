/*
 * BotManager.cpp
 *
 *  Created on: 31 janv. 2016
 *      Author: pmx
 */

#include "BotManager.hpp"

#include <SDL2/SDL_thread.h>
#include <unistd.h>
#include <cstdio>
#include <string>

#include "../Bot-APF9328/APF9328LedBarTest.hpp"
#include "../Bot-APF9328/APF9328RobotExtended.hpp"
#include "../Bot-LegoEV3/LegoEV3LedBarTest.hpp"
#include "../Bot-LegoEV3/LegoEV3RobotExtended.hpp"
#include "../Common/Arguments.hpp"
#include "../Common/ConsoleManager.hpp"
#include "../Common/Robot.hpp"
#include "../Log/Logger.hpp"
#include "SDLTool.hpp"

int threadLegoEV3RobotExtended(void* data)
{

	BotManager* botm = (BotManager*) data;
//sleep(1);
	LegoEV3RobotExtended &robotlegoev3 = LegoEV3RobotExtended::instance();
	APF9328RobotExtended &robotapf = APF9328RobotExtended::instance();

	botm->logger().info() << "Starting threadLegoEV3RobotExtended... " << botm->start()
			<< logs::end;

	while (!botm->start())
	{
		usleep(100000);
	}

	botm->logger().info() << "Running threadLegoEV3RobotExtended " << botm->start() << logs::end;

	//add specific tests for this robot
	robotlegoev3.getConsoleManager().add(new LegoEV3LedBarTest());

	Arguments &args = robotlegoev3.getArgs();

	args["type"] = "m";
	//args['n'].set(true);
	//args['n']["num"] = "1"; //LegoEV3LedBarTest

	//launch automate
	robotlegoev3.begin();

	while (!botm->stop())
	{
		//DO something
		usleep(100000);
	}

	printf("End threadFunctionLegoEV3RobotExtended.\n");
	return 0;
}

int threadAPF9328RobotExtended(void* data)
{
	BotManager* botm = (BotManager*) data;

	botm->logger().info() << "Starting threadAPF9328RobotExtended... " << botm->start()
			<< logs::end;
	while (!botm->start())
	{
		usleep(100000);
	}
	//printf("Running threadFunctionBRobotExtended with value = %d\n", botm->start());

	while (!botm->stop())
	{
		//DO something
		usleep(100000);
	}
	//printf("End threadFunctionBRobotExtended.\n");
	return 0;
}

int threadLedBarTest(void* data)
{
	BotManager* botm = (BotManager*) data;
	LegoEV3RobotExtended &robotlegoev3 = LegoEV3RobotExtended::instance();
	APF9328RobotExtended &robotapf = APF9328RobotExtended::instance();

	botm->logger().info() << "Starting threadLedBarTest... " << botm->start() << logs::end;

	//add specific tests for this robot
	robotlegoev3.getConsoleManager().add(new LegoEV3LedBarTest());
	{
		Arguments &args = robotlegoev3.getArgs();
		args["type"] = "t";
		args['n'].set(true);
		args['n']["num"] = "1"; //LegoEV3LedBarTest
	}
	//launch automate
	botm->logger().info() << "robotlegoev3.begin() "  << logs::end;
	robotlegoev3.begin();



	robotapf.getConsoleManager().add(new APF9328LedBarTest());
	{
		Arguments &args = robotapf.getArgs();
		args["type"] = "t";
		args['n'].set(true);
		args['n']["num"] = "1"; //APF9328LedBarTest
	}
	//launch automate
	botm->logger().info() << "robotapf.begin() "  << logs::end;
	robotapf.begin();

	botm->logger().info() << "End threadLedBarTest. "  << logs::end;
	return 0;
}

void BotManager::reset()
{
	printf("reset\n");
}

BotManager::BotManager()
{
	logger().debug() << "BotManager" << logs::end;

	start_ = false;
	stop_ = false;

	thread = NULL;
	thread1 = NULL;
	threadledbartest = NULL;
}

BotManager::~BotManager()
{
	SDLTool::checkThread(__PRETTY_FUNCTION__);
	SDL_WaitThread(thread, NULL);
	SDL_WaitThread(thread1, NULL);
	SDL_WaitThread(threadledbartest, NULL);

}

void BotManager::launchRobotThreads()
{
	SDLTool::checkThread(__PRETTY_FUNCTION__);
	//Run the threads with different robots
	thread = SDL_CreateThread(&threadLegoEV3RobotExtended, "threadLegoEV3RobotExtended",
			(void*) this);

	thread1 = SDL_CreateThread(&threadAPF9328RobotExtended, "threadAPF9328RobotExtended",
			(void*) this);
}

void BotManager::launchLedBarTest()
{
	SDLTool::checkThread(__PRETTY_FUNCTION__);

	threadledbartest = SDL_CreateThread(&threadLedBarTest, "threadLedBarTest", (void*) this);
}
