#pragma once

#include "Person.h"

/// <summary>
/// A worker IS A person. 
/// </summary>
class Worker : Person
{
private:
	bool fullTime;
	std::string position;

public:
	Worker() : Person()
	{}
};

