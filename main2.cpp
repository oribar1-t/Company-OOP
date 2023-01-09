#include <iostream>
#include "Definitions.h"
#include <iostream>


using namespace std;

int main()
{
	/*** First part ***/

	cout << "*****	C'tor's TEST	*****" << endl << endl;
	DeveloperEmployee* test_a1 = new DeveloperEmployee();
	TesterEmployee* test_a2 = new TesterEmployee();
	cout << *test_a1 << *test_a2;

	// the next ID should be 3

	DeveloperEmployee* test_b1 = new DeveloperEmployee( "c_dev",  "matam");
	TesterEmployee* test_b2 = new TesterEmployee( "qa_rules",  "noobie");
	cout << *test_b1 << *test_b2;

	test_b1->setProject();
	test_b2->setLevel();
	cout << *test_b1 << *test_b2;

	// the next ID should be 5

	DeveloperEmployee* test_b3 = new DeveloperEmployee( "c_dev");
	TesterEmployee* test_b4 = new TesterEmployee( "qa_rules");
	cout << *test_b3 << *test_b4;

	cout << endl << "*****	setProject && setLevel TEST	*****" << endl << endl;
	test_b3->setProject( "oop");
	test_b4->setLevel( "senior");
	cout << *test_b3 << *test_b4;

	// the next ID should be 7

	cout << endl << "*****	getID TEST	*****" << endl << endl;
	cout << test_a1->getID() << " " << test_a2->getID() << " " << test_b1->getID() << " ";
	cout << test_b2->getID() << " " << test_b3->getID() << " " << test_b4->getID() << endl;

	delete(test_a1);
	delete(test_a2);
	delete(test_b1);
	delete(test_b2);

	cout << endl << "*****	clone TEST	******" << endl << endl;
	DeveloperEmployee* test_b3_copy = test_b3->clone();
	TesterEmployee* test_b4_copy = test_b4->clone();

	cout << *test_b3_copy << *test_b4_copy;
	cout << test_b3_copy->getID() << "  " << test_b4_copy->getID() << endl;
	delete (test_b3);
	delete (test_b4);
	cout << *test_b3_copy << *test_b4_copy;

	DeveloperEmployee* test_b3_copy_copy = test_b3_copy->clone();
	TesterEmployee* test_b4_copy_copy = test_b4_copy->clone();

	cout << *test_b3_copy_copy << *test_b4_copy_copy;
	delete (test_b3_copy);
	delete (test_b4_copy);
	cout << *test_b3_copy_copy << *test_b4_copy_copy;

	delete (test_b3_copy_copy);
	delete (test_b4_copy_copy);

	for (int i=0; i<3; i++)
	{
		DeveloperEmployee* test_c1 = new DeveloperEmployee( "linus is my best friend",  "Windows7");
		TesterEmployee* test_c2 = new TesterEmployee( "misrat student",  "drinks coffee mainly");

		DeveloperEmployee* test_c1_copy = test_c1->clone();
		TesterEmployee* test_c2_copy = test_c2->clone();

		delete(test_c1);
		delete(test_c2);
		cout << *test_c1_copy << *test_c2_copy;
		delete(test_c1_copy);
		delete(test_c2_copy);
	}

	// the next ID should be 13

	cout << endl << "*****	getDescription TEST	******" << endl << endl;

	DeveloperEmployee* test_d1 = new DeveloperEmployee( "Dire",  "Straits");
	TesterEmployee* test_d2 = new TesterEmployee( "Sarit",  "Hadad");

	string test_d1_desc = test_d1->getDescription();
	string test_d2_desc = test_d2->getDescription();

	cout << "description = " << test_d1_desc << ", " << *test_d1;
	cout << "description = " << test_d2_desc << ", " << *test_d2;

	delete(test_d1);
	delete(test_d2);

	// the next ID should be 15

	cout << endl << "*****	Company TEST	******" << endl << endl;

	Company* company = new Company();

	cout << endl << "*****	add element TEST	******" << endl << endl;

	DeveloperEmployee* test_e1 = new DeveloperEmployee( "Dire",  "Straits");
	TesterEmployee* test_e2 = new TesterEmployee( "Sarit",  "Hadad");
	DeveloperEmployee* test_e3 = new DeveloperEmployee( "Bob",  "Dylan");
	TesterEmployee* test_e4 = new TesterEmployee( "Itsik",  "Kala");
	DeveloperEmployee* test_e5 = new DeveloperEmployee( "Simply",  "Red");
	TesterEmployee* test_e6 = new TesterEmployee( "Avi",  "Bitter");

	DeveloperEmployee* test_e5_copy = test_e5->clone();
	TesterEmployee* test_e6_copy = test_e6->clone();

	*company += test_e1;
	*company += test_e2;
	*company += test_e3;
	*company += test_e4;
	*company += test_e5;
	*company += test_e6;

	int emp_id[8] = {test_e1->getID(), test_e2->getID(), test_e3->getID(), test_e4->getID(), test_e5->getID(), test_e6->getID(), 0, 0};

	// add the same element twice !!
	*company += test_e5;
	*company += test_e6;

	delete(test_e1);
	delete(test_e2);
	delete(test_e3);
	delete(test_e4);
	delete(test_e5);
	delete(test_e6);

	cout << *company << endl;

	*company += test_e5_copy;
	*company += test_e6_copy;

	cout << *company << endl;

	delete(test_e5_copy);
	delete(test_e6_copy);

	try {
		*company += NULL;
	}
	catch (IllegalArguments exp) {
		cout << "IllegalArguments exception was thrown !!" << endl;
	}

	// the next ID should be 21

	cout << endl << "*****	remove element TEST	******" << endl << endl;

	DeveloperEmployee* test_f1 = new DeveloperEmployee( "Only",  "Java");
	TesterEmployee* test_f2 = new TesterEmployee( "Just",  "QA");

	*company += test_f1;
	*company += test_f2;

	cout << *company << endl;
	*company -= test_f1->getID();
	*company -= test_f2->getID();
	cout << *company << endl;

	delete(test_f1);
	delete(test_f2);

	// the next ID should be 23

	cout << *company << endl;
	*company -= (int) 23;
	cout << *company << endl;

	cout << endl << "*****	get element TEST	******" << endl << endl;

	DeveloperEmployee* test_f3 = new DeveloperEmployee( "Soldier",  "Atudai");
	TesterEmployee* test_f4 = new TesterEmployee( "Reserve",  "Golani");

	*company += test_f3;
	*company += test_f4;

	emp_id[6] = test_f3->getID();
	emp_id[7] = test_f4->getID();

	DeveloperEmployee* test_f3_copy = (DeveloperEmployee*)(*company)[test_f3->getID()];
	TesterEmployee* test_f4_copy = (TesterEmployee*)(*company)[test_f4->getID()];

	cout << *test_f3_copy << *test_f4_copy;

	cout << *company << endl;
	delete(test_f3_copy);
	delete(test_f4_copy);
	cout << *company << endl;

	// the next ID should be 25

	DeveloperEmployee* test_f5 = (DeveloperEmployee*)(*company)[(int) 25];
	TesterEmployee* test_f6 = (TesterEmployee*)(*company)[(int) 26];

	if ((NULL == test_f5) && (NULL == test_f6)) {
		cout << "NULL pointers were returned from Company as should" << endl;
	}

	cout << endl << "*****	existence of element TEST	******" << endl << endl;

	if (company->contains(test_f3->getID())) {
		cout << "an employee with id: " << test_f3->getID() << " is in the company" << endl;
	}
	if (company->contains(test_f4->getID())) {
		cout << "an employee with id: " << test_f4->getID() << " is in the company" << endl;
	}
	if (!company->contains((int) 25)) {
		cout << "an employee with id: " << (int) 25 << " isn't in the company !!" << endl;
	}

	delete(test_f3);
	delete(test_f4);
	delete(test_f5);
	delete(test_f6);

	cout << endl << "*****	print company TEST	******" << endl << endl;

	cout << *company << endl;

	for (int i=0; i<8; i++) {
		*company -= emp_id[i];
	}

	cout << *company << endl;

	// the next ID should be 25


	/*** Second part ***/

	cout << endl << "*****	print description TEST	******" << endl << endl;

	PrintableDeveloper* test_g1 = new PrintableDeveloper();
	PrintableTester* test_g2 = new PrintableTester();

	cout << *test_g1 << *test_g2;

	cout << "description of test_g1 : ";
	test_g1->printDescription();
	cout << "description of test_g2 : ";
	test_g2->printDescription();

	test_g1->setDescription("Will make the first million when I am 18");
	test_g2->setDescription("Will find million bugs when I am 18");

	cout << "description of test_g1 : ";
	test_g1->printDescription();
	cout << "description of test_g2 : ";
	test_g2->printDescription();

	delete(test_g1);
	delete(test_g2);
	delete company;
	
	return 0;
}
