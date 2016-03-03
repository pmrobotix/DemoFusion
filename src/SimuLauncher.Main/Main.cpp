#include "Simulator.hpp"


using namespace std;

int main(int, char** )
{
	//printf("start");

	Simulator &sim = Simulator::instance();

	sim.execute();

	return 0;

}
