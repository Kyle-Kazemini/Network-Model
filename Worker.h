#pragma once

#include "Person.h"

/// <summary>
/// A worker IS A person. 
/// </summary>
class Worker : public Person
{
private:
	bool fullTime;
	std::string position;

public:
	Worker() : Person()
	{
		this->fullTime = true;
		this->position = "Unkown";
	}
};

