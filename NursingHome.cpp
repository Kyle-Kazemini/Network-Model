#include "NursingHome.h"
#include "Instrumentor.h"
#include "Constants.h"


void NursingHome::RunSimulation()
{
	Instrumentor::Get().BeginSession("RunSimulation");
	{
		InstrumentationTimer timer("RunSimulation scope");




		// Output summary statistics to a text file

		std::ofstream file;
		file.open("output.csv");

		file.close();

	}
	Instrumentor::Get().EndSession();
}




