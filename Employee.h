
#pragma once
#include <iostream>
#include <string>
using std::ostream;
using std::string;

class Employee
{
private:
	string _description;
	int _id;
	static int index_employee; // way to create counter of the employees added by static int
public:
	Employee(string);
	virtual Employee *clone() const = 0; // pure virtual clone
	int getID() const;
	string getDescription() const;
	void setDescription(string descryption);
	friend ostream &operator<<(ostream &output, const Employee &rhs);
	virtual ostream &print(ostream &) const = 0; // pure virtual print function because we depend how to print by the chosen class,now the "sons" must create print fuction
	virtual ~Employee()							 // virtual destructor because this is the base class
	{
	}
};
