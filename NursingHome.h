#pragma once

#include "Constants.h"
#include "Worker.h"
#include "Resident.h"
#include <vector>


/// <summary>
/// This class is designed to be used as a vertex attribute in the graph.
/// It represents a nursing home, which encapsulates workers and residents
/// and a few other properties.
/// </summary>
class NursingHome {

private:

	std::string nh_name;

	Worker workers[Constants::numOfWorkers];
	Resident residents[Constants::numOfResidents];
};