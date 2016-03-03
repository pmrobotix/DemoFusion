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

#include "../Bot-LegoEV3/LegoEV3LedBarTest.hpp"
#include "../Bot-LegoEV3/LegoEV3RobotExtended.hpp"
#include "../Common/Arguments.hpp"
#include "../Common/ConsoleManager.hpp"
#include "../Common/Robot.hpp"
#include "../Log/Logger.hpp"

int threadFunctionLegoEV3RobotExtended(void* data)
{
	BotManager* botm = (BotManager*) data;
	while (!botm->start())
	{
		usleep(100000);
	}

	botm->logger().info() << "Running threadFunctionLegoEV3RobotExtended " << botm->start()
			<< logs::end;
	//printf("Running threadFunctionLegoEV3RobotExtended with value = %d\n", botm->start());

	LegoEV3RobotExtended &robot = LegoEV3RobotExtended::instance();

	//add specific tests for this robot
	robot.getConsoleManager().add(new LegoEV3LedBarTest());

	Arguments &args = robot.getArgs();

	args["type"] = "t";
	args['n'].set(true);
	args['n']["num"] = "1"; //LegoEV3LedBarTest

	//launch automate
	robot.begin();

	while (!botm->stop())
	{
		//DO something
		usleep(100000);
	}

	printf("End threadFunctionLegoEV3RobotExtended.\n");
	return 0;
}

int threadFunctionBRobotExtended(void* data)
{
	BotManager* botm = (BotManager*) data;
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

int threadFunctionSRobotExtended(void* data)
{
	BotManager* botm = (BotManager*) data;
	while (!botm->start())
	{
		usleep(100000);
	}

	//printf("Running threadFunctionSRobotExtended with value = %d\n", botm->start());

	while (!botm->stop())
	{
		//DO something
		usleep(100000);
	}
	//printf("End threadFunctionSRobotExtended.\n");
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

	//Run the threads with different robots
	thread = SDL_CreateThread(&threadFunctionLegoEV3RobotExtended, "LegoEV3RobotExtended",
			(void*) this);

	//int data1 = 102;
	thread1 = SDL_CreateThread(&threadFunctionBRobotExtended, "BRobotExtended", (void*) this);

	//int data2 = 103;
	thread2 = SDL_CreateThread(&threadFunctionSRobotExtended, "SRobotExtended", (void*) this);

}

BotManager::~BotManager()
{

	SDL_WaitThread(thread, NULL);
	SDL_WaitThread(thread1, NULL);
	SDL_WaitThread(thread2, NULL);

}

