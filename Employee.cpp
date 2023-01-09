
#include "Employee.h"
int Employee::index_employee = 0; // first time created
Employee::Employee(string descrypction = "???")
{
	_description = descrypction;
	_id = ++index_employee; // increasing the counter as new employees join the company
}

int Employee::getID() const
{
	return _id;
}

string Employee::getDescription() const
{
	return _description;
}

void Employee::setDescription(string descryption)
{
	_description = descryption;
}

ostream &operator<<(ostream &output, const Employee &rhs)
{
	return rhs.print(output); // in this way we use the chosen print function from the correct class
}
