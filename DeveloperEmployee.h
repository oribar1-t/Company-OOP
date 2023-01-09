
#pragma once
#include "Employee.h"
using std::endl;
class DeveloperEmployee : public Employee
{
public:
	DeveloperEmployee(string descryption = "???", string project = "???"); // constructor
	void setProject(string project = "???");
	DeveloperEmployee *clone() const;	   // clone function making new object of this class
	ostream &print(ostream &output) const; // prints the actual details of this class

private:
	string _project;
};
