
#pragma once
#include "Employee.h"
using std::endl;
using std::string;
class TesterEmployee : public Employee
{
public:
	TesterEmployee(string descryption = "???", string level = "???"); // constructor
	void setLevel(string level = "???");
	TesterEmployee *clone() const;		   // clone function making new object of this class
	ostream &print(ostream &output) const; // prints the actual details of this class
private:
	string _level;
};
