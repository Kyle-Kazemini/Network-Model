#include "Properties.h"


/// <summary>
/// This method starts an outbreak by selecting an individual randomly
/// from a random facility. Movement around the network will then cause more infections.
/// Probabilities are specified in the code.
/// </summary>
void GraphProperties::RunSimulation(int days)
{
	Instrumentor::Get().BeginSession("RunSimulation");
	{
		InstrumentationTimer timer("RunSimulation scope");

		for (int i = 0; i < days; i++)
		{


		}


		// Output summary statistics to a text file

		std::ofstream file;
		file.open("output.csv");
		file << "Day" << "Facility Number" << "Person's ID";

		file.close();

	}
	Instrumentor::Get().EndSession();
}
