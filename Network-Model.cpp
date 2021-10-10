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


#include <fstream>
#include <boost/graph/adjacency_list.hpp>

#include "Constants.h"
#include "Properties.h" 
#include "NursingHome.h"
#include "Instrumentor.h"


 /**
  *  Create a Graph type that encapsulates
  *  edges, vertices, directedness, vertex attributes,
  *  edge attributes, and graph properties.
  */
typedef boost::adjacency_list
<boost::vecS,
	boost::vecS,
	boost::undirectedS,
	VertexProperties,
	EdgeProperties,
	GraphProperties>
	GraphType;


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
		// The RunSimulation() method will write summary statistics to a file.
		graph[boost::graph_bundle_t::graph_bundle].RunSimulation();

	}
	Instrumentor::Get().EndSession();

	return 0;
}