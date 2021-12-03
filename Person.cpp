#include "Person.h"


/// <summary>
/// Default Person constructor.
/// </summary>
Person::Person()
	: name(""), age(0), ID(generator()()),
	start_day(0), end_day(0), duration(0),
	infected(false), state(State::Susceptible)
{}


/// <summary>
/// Person constructor that takes a name and age.
/// </summary>
/// <param name="s"></param>
/// <param name="n"></param>
Person::Person(std::string s, unsigned int& n)
	: name(s), age(n), ID(generator()()),
	start_day(0), end_day(0), duration(0),
	infected(false), state(State::Susceptible)
{}


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
const boost::uuids::uuid Person::GetID()
{
	return this->ID;
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


/// <summary>
/// Get this Person's infected duration.
/// </summary>
/// <returns></returns>
int Person::GetDuration()
{
	return this->duration;
}


/// <summary>
/// Method for initializing the static member object that generates unique IDs.
/// </summary>
/// <returns></returns>
boost::uuids::random_generator& Person::generator()
{
	static boost::uuids::random_generator gen = boost::uuids::random_generator();
	return gen;
}



