
#include "Employee.h"
#include "DeveloperEmployee.h"

DeveloperEmployee::DeveloperEmployee(string descryption, string project) : Employee(descryption)
{
	_project = project;
}

void DeveloperEmployee::setProject(string project)
{
	_project = project;
}

DeveloperEmployee *DeveloperEmployee::clone() const
{
	DeveloperEmployee *ptr = new DeveloperEmployee(*this);
	return ptr;
}
ostream &DeveloperEmployee::print(ostream &output) const
{
	output << "Developer ID = " << getID() << ", project = " << _project << endl;
	return output;
}
