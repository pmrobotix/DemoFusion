#ifndef SIMULAUNCHER_MAIN_SIMULATOR_HPP_
#define SIMULAUNCHER_MAIN_SIMULATOR_HPP_


class BotManager;
class MainWindow;
class SecondWindow;
class ThirdWindow;



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

	void enableLedDriver();


	MainWindow *mainWindow;
	SecondWindow *secondWindow;
	ThirdWindow *thirdWindow;
	BotManager *botm;

private:

	Simulator();

};

#endif /* SIMULAUNCHER_MAIN_SIMULATOR_HPP_ */
