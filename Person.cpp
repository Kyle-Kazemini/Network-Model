#include "Person.h"


/// <summary>
/// Default Person constructor.
/// </summary>
Person::Person()
{
	this->name = "";
	this->age = 0;

	boost::uuids::random_generator generator;
	boost::uuids::uuid uuid = generator();
	this->ID >> uuid;
}


/// <summary>
/// Person constructor that takes a name and age.
/// </summary>
/// <param name="s"></param>
/// <param name="n"></param>
Person::Person(std::string s, unsigned int& n)
{
	this->name = s;

	if (n >= 0 && n < 125)
		this->age = n;
	else
		throw std::invalid_argument("Invalid Age");

	boost::uuids::random_generator generator;
	boost::uuids::uuid uuid = generator();
	this->ID >> uuid;
}


/// <summary>
/// Person destructor.
/// </summary>
Person::~Person()
{
	// I don't use "new" to allocate memory on the heap, 
	// so do I need to do anything here?
}


/// <summary>
/// Get this Person's age.
/// </summary>
/// <returns></returns>
unsigned int Person::GetAge()
{
	return this->age;
}


/// <summary>
/// Set this Person's age.
/// </summary>
/// <param name="n"></param>
void Person::SetAge(unsigned int& n)
{
	if (n >= 0 && n < 125)
		this->age = n;
	else
		throw std::invalid_argument("Invalid Age");
}


/// <summary>
/// Get this Person's name.
/// </summary>
/// <returns></returns>
std::string Person::GetName()
{
	return this->name;
}


/// <summary>
/// Set this Person's name.
/// </summary>
/// <param name="s"></param>
void Person::SetName(std::string s)
{
	this->name = s;
}


/// <summary>
/// Get this Person's unique ID.
/// </summary>
/// <returns></returns>
const std::string Person::GetID()
{
	return this->ID.str();
}


/// <summary>
/// Get this Person's infected status.
/// </summary>
/// <returns> True if this Person is infected </returns>
bool Person::GetStatus()
{
	return this->infected;
}


/// <summary>
/// Set this Person's infected status.
/// </summary>
/// <param name="b"></param>
void Person::SetStatus(bool b)
{
	this->infected = b;
}

int Person::GetDuration()
{
	return this->duration;
}



