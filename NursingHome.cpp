#include "NursingHome.h"


/// <summary>
/// Default NursingHome constructor.
/// </summary>
NursingHome::NursingHome()
{
	for (int i = 0; i < Constants::numOfWorkers; i++)
	{
		workers.push_back(Worker());
	}

	for (int i = 0; i < Constants::numOfResidents; i++)
	{
		residents.push_back(Resident());
	}
}


/// <summary>
/// NursingHome destructor.
/// </summary>
NursingHome::~NursingHome()
{
}
