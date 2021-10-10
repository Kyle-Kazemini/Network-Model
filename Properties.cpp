#include "Properties.h"
#include <iostream>


/// <summary>
/// This method starts an outbreak by selecting an individual randomly
/// from a random facility. Movement around the network will then cause more infections.
/// Probabilities are specified in the code.
/// </summary>
void GraphProperties::RunSimulation(GraphType& graph, Level level, int average_duration, std::string file_name, int days)
{
	Instrumentor::Get().BeginSession("RunSimulation");
	{
		InstrumentationTimer timer("RunSimulation scope");

		// Output summary statistics to a text file
		std::ofstream file;
		file.open(file_name);
		file << "Day" << "Facility Number" << "Unique ID" << "Role" << "Infected Status" << "Infected Duration";

		// Randomly select someone to be the first infected person.

		for (int i = 0; i < days; i++)
		{
			auto vpair = vertices(graph);
			for (auto iter = vpair.first; iter != vpair.second; iter++) {
				std::cout << "vertex " << *iter << std::endl;
			}

			// If a transfer needs to take place between two facilities, do that here.

			// Check the number of infections for this day. Do any need to end?
			// Write the info for this day into the output file.
			file << i;
		}

		file.close();

	}
	Instrumentor::Get().EndSession();
}
