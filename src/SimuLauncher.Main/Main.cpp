#include <cstdio>

#include "Simulator.hpp"


using namespace std;

int main(int, char** )
{
	printf("start\n");

	Simulator &sim = Simulator::instance();

	sim.execute();

	return 0;

}
