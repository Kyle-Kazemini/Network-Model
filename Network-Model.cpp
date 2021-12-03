/**
 * @remarks
 * This project is an epidemiological network model
 * for COVID-19 in long term care facilities. Its purpose is to be
 * efficient and adaptable for future use. This may include experiments for
 * COVID-19 or other infectious diseases.
 *
 * @note
 * The terms "graph" and "network" are used
 * interchangeably throughout this project.
 *
 * @date September 2021
 * @authors Kyle Kazemini, Jay Love
 *
 */


#include <iostream>
#include "Constants.h"
#include "Properties.h" 
#include "NursingHome.h"
#include "Instrumentor.h"


 /**
  * Application entry point.
  * @return 0 - if the application completed successfully.
  */
int main(int argc, char* argv[])
{
	Instrumentor::Get().BeginSession("Main");
	{
		InstrumentationTimer timer("Main scope");

		// Create a graph of numOfFacilties vertices.
		GraphType graph(Constants::numOfFacilities);

		// Run an outbreak simulation on the network.
		// RunSimulation() will write summary statistics to a file.
		graph[boost::graph_bundle_t::graph_bundle].RunSimulation(graph);

	}
	Instrumentor::Get().EndSession();

	std::cout << "Done\n";

	return 0;
}