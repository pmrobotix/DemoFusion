#ifndef SIMULAUNCHER_MAIN_SIMULATOR_HPP_
#define SIMULAUNCHER_MAIN_SIMULATOR_HPP_

#include "LWindows.hpp"

//Total number of windows
const int TOTAL_WINDOWS = 3;

class Simulator
{
public:

	static Simulator & instance()
	{
		static Simulator instance;
		return instance;
	}

	//Starts up SDL and creates window
	bool initSDL();

	//create windows
	bool createWindows();

	//Frees media and shuts down SDL
	void closeSDL();

	void execute();

	~Simulator();

	MainWindow *mainWindow;
	SecondWindow *secondWindow;
	ThirdWindow *thirdWindow;

private:

	Simulator();

};

#endif /* SIMULAUNCHER_MAIN_SIMULATOR_HPP_ */
