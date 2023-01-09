
#include "TesterEmployee.h"

TesterEmployee::TesterEmployee(string descryption, string level) : Employee(descryption)
{
	_level = level;
}

void TesterEmployee::setLevel(string level)
{
	_level = level;
}

TesterEmployee *TesterEmployee::clone() const
{
	TesterEmployee *ptr = new TesterEmployee(*this);
	return ptr;
}

ostream &TesterEmployee::print(ostream &output) const
{
	output << "Tester ID = " << getID() << ", level = " << _level << endl;
	return output;
}
