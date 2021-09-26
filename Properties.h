#pragma once

#include <string>
#include "NursingHome.h"
#include "Instrumentor.h"

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
	void RunSimulation(int days = Constants::days);
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