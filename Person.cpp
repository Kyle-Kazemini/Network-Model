#include "Person.h"


Person::Person()
{
	this->name = "";
	this->age = 0;

	boost::uuids::random_generator generator;
	boost::uuids::uuid uuid = generator();
	this->ID >> uuid;
}

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

Person::~Person()
{
	// I don't use "new" to allocate memory on the heap, 
	// so do I need to do anything here?
}

unsigned int Person::GetAge()
{
	return this->age;
}

void Person::SetAge(unsigned int& n)
{
	if (n >= 0 && n < 125)
		this->age = n;
	else
		throw std::invalid_argument("Invalid Age");
}

std::string Person::GetName()
{
	return this->name;
}

void Person::SetName(std::string s)
{
	this->name = s;
}

const std::string Person::GetID()
{
	return this->ID.str();
}

bool Person::GetStatus()
{
	return this->infected;
}

void Person::SetStatus(bool b)
{
	this->infected = b;
}



