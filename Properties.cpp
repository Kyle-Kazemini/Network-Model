#include "Properties.h"


/// <summary>
/// This method starts an outbreak by selecting an individual randomly
/// from a random facility. Movement around the network will then cause more infections.
/// Probabilities are specified in the code.
/// </summary>
void GraphProperties::RunSimulation(Level level, int average_duration, std::string file_name, int days)
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


			// If a transfer needs to take place between two facilities, do that here.

			// Check the number of infections for this day. Do any need to end?
			// Write the info for this day into the output file.
			file << i;
		}

		file.close();

	}
	Instrumentor::Get().EndSession();
}
