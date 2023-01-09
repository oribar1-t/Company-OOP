
#pragma once
#include "DeveloperEmployee.h"
#include "TesterEmployee.h"
#include <string>
using std::cout;
using std::endl;

template <class origin>			// this is a template class because we depend on the users chioce of creation
class Printable : public origin // inherits from the origin , in our case PrintableDeveloper or  PrintableTester
{
public:
	Printable(string descrypction = "???") : origin(descrypction) {} // just in case needed
	Printable(const origin &origin) : origin(origin) {}				 // just in case needed
	void printDescription() const
	{
		cout << origin::getDescription() << endl; // calls the origin object for printing
	}
	Printable<origin> *clone() const
	{ // clone function making new object of this class
		Printable<origin> *ret = new Printable<origin>(*this);
		return ret;
	}
};
typedef Printable<DeveloperEmployee> PrintableDeveloper; // in here we will recognize the kind of object used in the main by using typdef
typedef Printable<TesterEmployee> PrintableTester;