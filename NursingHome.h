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

public:

	std::string nh_name;

	std::vector<Worker> workers;
	std::vector<Resident> residents;

	int wor_res[Constants::numOfWorkers][Constants::numOfResidents];
	int wor_wor[Constants::numOfWorkers][Constants::numOfWorkers];
	int res_res[Constants::numOfResidents][Constants::numOfResidents];


	NursingHome();
	~NursingHome();
};