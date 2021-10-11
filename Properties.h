#pragma once

#include <string>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/properties.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/named_function_params.hpp>
#include "NursingHome.h"
#include "Instrumentor.h"


// Forward declare these structs so that GraphType knows they exist.
struct VertexProperties;
struct EdgeProperties;
struct GraphProperties;

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


/// <summary>
/// This struct encapsulates everything that a vertex in the network contains.
/// Default privacy for a struct is public.
/// </summary>
struct VertexProperties
{
	NursingHome facility;
};


/// <summary>
/// This struct encapsulates everything that the network itself contains.
/// Default privacy for a struct is public.
/// </summary>
struct GraphProperties
{
	std::string network_name;
	enum Level : char
	{
		None = 0, Low = 1, Medium = 2, High = 3
	};

	void RunSimulation(GraphType& graph, Level level = None, int average_duration = Constants::averageDuration, std::string file_name = "output.csv", int days = Constants::days);
};


/// <summary>
/// This struct encapsulates everything that an edge in the network contains.
/// Default privacy for a struct is public.
/// </summary>
struct EdgeProperties
{
	std::string edge_name;
	double weight;
};

