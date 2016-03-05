/*
 * SDLTool.cpp
 *
 *  Created on: 5 mars 2016
 *      Author: pmx
 */

#include "SDLTool.hpp"

#include <unistd.h>

pthread_t SDLTool::sdlThread = 0;

std::list<SDLTask*> *SDLTool::listSDLTask = NULL;

void SDLTool::checkThread(std::string str)
{
	pthread_t myThread = pthread_self();
	if (!pthread_equal(myThread, sdlThread))
	{
		printf("Thread error : %s\n", str.c_str());
		exit(0);
	}
	else
	{
		//printf("ok %s\n", str.c_str());
	}
}

void SDLTool::initSDLThread()
{
	sdlThread = pthread_self();

	listSDLTask = new std::list<SDLTask*>();
}

void SDLTool::addSDLTask(SDLTask *task)
{
	listSDLTask->push_back(task);

	while (!listSDLTask->empty())
	{
		usleep(1000);
	}
}

void SDLTool::processSDLTasks()
{
	while (!listSDLTask->empty())
	{
		listSDLTask->front()->run();
		listSDLTask->pop_front();
	}
}
