#pragma once

#include <sstream>
#include <string>
#include <stdexcept>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>


/// <summary>
/// A Person is either a healthcare worker or resident. This is a super class
/// for both of those types because they both have things like age, name, 
/// infected status, and a unique ID.
/// </summary>
class Person
{

public:
	Person();
	Person(std::string s, unsigned int& n);
	~Person();

	unsigned int GetAge();
	void SetAge(unsigned int& n);

	std::string GetName();
	void SetName(std::string s);

	const std::string GetID();

	bool GetStatus();

	void SetStatus(bool b);


private:
	std::string name;
	unsigned int age;
	bool infected;
	std::stringstream ID;

};
