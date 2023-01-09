#include <iostream>
#include "Definitions.h"

//using namespace std;

int main()
{
	char description[] = "Software in C++";
	char project[] = "hw5";

	/*** First part ***/
	/* clone function example */
	DeveloperEmployee* a = new DeveloperEmployee(description, project);
	cout << *a << endl; //Developer ID = 1, project = hw5
	DeveloperEmployee* a_copy = a->clone();
	cout << *a_copy << endl; //Developer ID = 1, project = hw5

	delete a_copy;
	delete a;

	/* data base usage example */
	Company* company = new Company();
	a = new DeveloperEmployee(description, project);
	int id = a->getID();
	cout << *a << endl; //Developer ID = 2, project = hw5

	*company += a;
	if(company->contains(id))
		cout << "true" << endl;
	delete a;

	cout << *company << endl;
	// Company content:
	//  Developer ID = 2, project = hw5

	a_copy = (DeveloperEmployee*)(*company)[id];
	cout << *a_copy << endl; //Developer ID = 2, project = hw5

	delete a_copy;
	delete company;

	/*** Second part ***/
	cout << "******************************" << endl;
	company = new Company();
	PrintableDeveloper* pa = new PrintableDeveloper();
	PrintableDeveloper* p_copy = pa->clone();
	pa->setDescription(description);
	pa->setProject(project);
	cout << *pa << endl;
	*company += pa;
	cout << *company << endl;
	// Company content:
	//  Developer ID = 3, project = hw5
	*company -= pa->getID();
	cout << *company << endl;
	// Company is empty
	pa->printDescription(); // QA

	delete pa;
	delete p_copy;
	delete company;

	return 0;
}
