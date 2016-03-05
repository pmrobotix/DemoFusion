

#ifndef SIMULAUNCHER_MAIN_SDLTOOL_HPP_
#define SIMULAUNCHER_MAIN_SDLTOOL_HPP_

#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <string>

#include "SDLTask.hpp"



class SDLTool
{
public:

	static pthread_t sdlThread;

	static std::list<SDLTask*> *listSDLTask;


	static void checkThread(std::string str);

	static void initSDLThread();

	static void addSDLTask(SDLTask *task);

	static void processSDLTasks();

};



#endif /* SIMULAUNCHER_MAIN_SDLTOOL_HPP_ */
