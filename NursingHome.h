#pragma once

#include "Constants.h"
#include "Worker.h"
#include "Resident.h"
#include <vector>


class NursingHome {
public:

	void RunSimulation();

private:

	std::string name;

	std::vector<Worker> workers(unsigned int&);
	std::vector<Resident> residents(unsigned int&);
};