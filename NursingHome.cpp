#include "NursingHome.h"


/// <summary>
/// Default NursingHome constructor.
/// </summary>
NursingHome::NursingHome()
{
	this->nh_name = "";
	this->numOfWorkers = Constants::numOfWorkers;
	this->numOfResidents = Constants::numOfResidents;

	// Initialize the workers vector.
	for (int i = 0; i < Constants::numOfWorkers; i++)
	{
		this->workers.push_back(new Worker());
	}

	// Initialize the residents vector.
	for (int i = 0; i < Constants::numOfResidents; i++)
	{
		this->residents.push_back(new Resident());
	}

	// Initialize the resident-to-resident contact matrix.
	for (int i = 0; i < sizeof(this->res_res) / sizeof(this->res_res[0]); i++)
	{
		for (int j = 0; j < sizeof(this->res_res[i]) / sizeof(this->res_res[i][0]); j++)
		{
			this->res_res[i][j] = 0;
		}
	}

	// Initialize the worker-to-resident contact matrix.
	for (int i = 0; i < sizeof(this->wor_res) / sizeof(this->wor_res[0]); i++)
	{
		for (int j = 0; j < sizeof(this->wor_res[i]) / sizeof(this->wor_res[i][0]); j++)
		{
			this->wor_res[i][j] = 0;
		}
	}

	// Initialize the worker-to-worker contact matrix.
	for (int i = 0; i < sizeof(this->wor_wor) / sizeof(this->wor_wor[0]); i++)
	{
		for (int j = 0; j < sizeof(this->wor_wor[i]) / sizeof(this->wor_wor[i][0]); j++)
		{
			this->wor_wor[i][j] = 0;
		}
	}
}


/// <summary>
/// NursingHome constructor.
/// </summary>
/// <param name="workers"></param>
/// <param name="residents"></param>
NursingHome::NursingHome(int workers, int residents) : NursingHome()
{
	this->numOfWorkers = workers;
	this->numOfResidents = residents;
}


/// <summary>
/// NursingHome destructor.
/// </summary>
NursingHome::~NursingHome()
{
	for (int i = 0; i < this->numOfWorkers; i++)
	{
		delete workers[i];
	}
}
