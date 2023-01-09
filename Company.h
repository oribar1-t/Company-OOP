
#pragma once

#include <map>
#include "Employee.h"
using std::endl;
using std::map;
using std::ostream;
class Company
{
public:
	Company();								  // default constructor
	Company(const Company &other);			  // copy constructor
	Company &operator=(const Company &other); // assingment operator
	Company &operator+=(const Employee *emp); // adding element to map
	Company &operator-=(int emp);			  // deleting element
	Employee *operator[](int index);
	bool contains(int exist) const;									 // if the emloyee exist by id
	Employee *find(int index);										 // find and create new employee
	friend ostream &operator<<(ostream &output, const Company &emp); // printing company details
	~Company();														 // destructor

private:
	map<int, Employee *> employees; // efficent way to store the employees
};
