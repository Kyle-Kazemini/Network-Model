/**
 * @remarks
 * This project is an epidemiological network model
 * for COVID-19 in long term care facilities.
 *
 * @note
 * The terms "graph" and "network" are used
 * interchangeably throughout this project.
 *
 * @date May 2021
 * @authors Kyle Kazemini, Jay Love
 *
 */


#include <iostream>
#include <fstream>
#include <boost/graph/adjacency_list.hpp>

#include "Constants.h"
#include "NursingHome.h"
#include "Instrumentor.h"
#include "Properties.cpp" 


 /**
 *  Create a "Graph" type that encapsulates
 *  edges, vertices, directedness, vertex attributes,
 *  edge attributes, and graph properties.
 */
typedef boost::adjacency_list<boost::vecS,
	boost::vecS,
	boost::undirectedS,
	VertexProperties,
	EdgeProperties,
	GraphProperties>
	Graph;


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
		Graph graph(Constants::numOfFacilities);

		// Run an outbreak simulation on the network by selecting a random vertex.
		graph[rand() % Constants::numOfFacilities].facility.RunSimulation();

	}
	Instrumentor::Get().EndSession();
	return 0;
}