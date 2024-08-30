#include "phonelist.h"

/*
 This is the client file. Here the code creates an instance of the PhoneList
 class. All functions of the class will be tested out in the client code.
*/
//By Dhanan Thannoo
int main() {

	PhoneList* phoneBook = new PhoneList("Yellow Pages");
	assert(phoneBook);

	cout << "Testing getTitle: " << phoneBook->getTitle() << endl;
	cout << "Testing getNoDirectories: " << 
		phoneBook->getNoDirectories() << endl << endl;

	phoneBook->removeDirectory("Alice");

	phoneBook->addDirectory("Zoey", 987, 8879568);
	phoneBook->addDirectory("Jack", 909, 7324011);
	phoneBook->addDirectory("Saitama", 737, 3825633);
	phoneBook->addDirectory("Zoey", 323, 7659808);
	phoneBook->addDirectory("Mark", 123, 3384214);
	phoneBook->removeDirectory("Alice");
	phoneBook->addDirectory("Ollie", 451, 3335121);

	cout << endl;
	phoneBook->showList(cout);
	phoneBook->removeDirectory("Saitama");

	cout << endl;
	phoneBook->showList(cout);
	phoneBook->removeDirectory("Zoey");

	cout << endl;
	phoneBook->showList(cout);
	phoneBook->removeDirectory("Jack");

	cout << endl;
	phoneBook->showList(cout);

	delete phoneBook;
}

/* Output Testing

Testing getTitle: Yellow Pages
Testing getNoDirectories: 0

Nothing to remove. List is empty!!!
Added direcotory to phone list.
Added direcotory to phone list.
Added direcotory to phone list.
That name is already in the phone list.
Added direcotory to phone list.
The Directory to remove was not found. :(
Added direcotory to phone list.

Yellow Pages

Name           Area Code      Phone Number
Jack           909            7324011
Mark           123            3384214
Ollie          451            3335121
Saitama        737            3825633
Zoey           987            8879568

Number of Directories: 5
The direcotry was found and removed.

Yellow Pages

Name           Area Code      Phone Number
Jack           909            7324011
Mark           123            3384214
Ollie          451            3335121
Zoey           987            8879568

Number of Directories: 4
The direcotry was found and removed.

Yellow Pages

Name           Area Code      Phone Number
Jack           909            7324011
Mark           123            3384214
Ollie          451            3335121

Number of Directories: 3
The direcotry was found and removed.

Yellow Pages

Name           Area Code      Phone Number
Mark           123            3384214
Ollie          451            3335121

Number of Directories: 2
*/