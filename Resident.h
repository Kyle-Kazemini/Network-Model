#pragma once

#include "Person.h"


/// <summary>
/// A resident IS A person.
/// </summary>
class Resident : public Person
{
public:
	Resident() : Person()
	{
	}
};

