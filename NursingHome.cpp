#include "NursingHome.h"


/// <summary>
/// Default NursingHome constructor.
/// </summary>
NursingHome::NursingHome()
{
	//workers.reserve(Constants::numOfWorkers);
	//residents.reserve(Constants::numOfResidents);

	for (int i = 0; i < Constants::numOfWorkers; i++)
	{
		//workers.emplace_back();
		//residents.emplace_back();
	}
}


/// <summary>
/// NursingHome destructor.
/// </summary>
NursingHome::~NursingHome()
{
}
