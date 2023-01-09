
#include "Company.h"
#include "IllegalArguments .h"

Company::Company() {}				   // using default constrctor
Company::Company(const Company &other) // copy constructor ,coping the indexes and elements
{

	for (map<int, Employee *>::const_iterator p = other.employees.begin(); p != other.employees.end(); p++)
	{
		this->employees[p->first] = p->second->clone();
	}
}
Company &Company::operator=(const Company &other) // assinment operator,first deletes elements and then clear the map..using the copy constructor
{
	if (&other != this)
	{
		for (map<int, Employee *>::iterator p = this->employees.begin(); p != this->employees.end(); ++p)
		{
			delete p->second;
		}
		this->employees.clear();
		*this = Company(other);
	}
	return *this;
}

Company &Company::operator+=(const Employee *emp) // adds employee if its a new one
{
	if (!emp)
		throw IllegalArguments();

	if (!contains(emp->getID()))
	{
		employees[emp->getID()] = emp->clone();
	}
	return *this;
}

Company &Company::operator-=(int emp) // deletes employee if exists
{

	if (contains(emp))
	{
		delete employees[emp];
		employees.erase(emp);
	}
	return *this;
}

Employee *Company::operator[](int index) // we need it for a check in the main
{
	if (!contains(index))
		return NULL;
	return employees[index]->clone();
}

bool Company::contains(int exist) const // if contains
{
	if (employees.find(exist) == employees.end())
		return false;
	return true;
}

Employee *Company::find(int index) // if employee is in the map create deep copy and return it
{
	if (!contains(index))
		throw IllegalArguments();

	Employee *deep_copy = employees[index]->clone();
	return deep_copy;
}

ostream &operator<<(ostream &output, const Company &company)
{
	if (company.employees.begin() == company.employees.end()) // that means the map is empty
		output << "Company is empty" << endl;
	else
	{
		output << "Company employees:" << endl;
		for (map<int, Employee *>::const_iterator p = company.employees.begin(); p != company.employees.end(); ++p)
		{
			output << " " << *(p->second);
		}
	}
	return output;
}
Company::~Company()
{
	for (map<int, Employee *>::iterator p = employees.begin(); p != employees.end(); ++p)
	{
		delete p->second;
	}
	employees.clear();
}
