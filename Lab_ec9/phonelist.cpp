//By Dhanan Thannoo
/*
This file implements all functions prototyped in the specificaiton
file. See comments above each funtion for more detail.
*/
#include "phonelist.h"

//non-default constructor of phone list.
//sets number of directories to zero and the first pointer points to null
//sets the title of the phonelist
PhoneList::PhoneList(string phonelistName) {
	title = phonelistName;
	noDirectories = 0;
	firstPtr = NULL;
}

//This is the destructor of the phoneList class.
//When a phonelist is deleted all the directories in the linked
//list will be deleted.
PhoneList::~PhoneList() {
	Directory* walker = firstPtr;

	while (walker != NULL)
	{
		walker = walker->link;
		delete firstPtr;
		firstPtr = walker;
	}

	noDirectories = 0;
}

//will output the information of the phone list and connections
//also outputs the number of directories to a console or a file.
//does nothing when the list is empty
void PhoneList::showList(ostream& out) const {

	if (firstPtr == NULL)
		out << "The Phone List is empty!!!" << endl;
	else {
		Directory* walker = firstPtr;
		out << title << endl << endl <<
			setw(15) << left << "Name" << setw(15) << "Area Code" <<
			setw(18) << "Phone Number" << endl;
		
		while (walker != NULL) {
			out << setw(15) << walker->name << setw(15) << walker->areaCode <<
				setw(18) << walker->phoneNo << endl;
			walker = walker->link;
		}

		out <<endl << "Number of Directories: " << noDirectories << endl;
	}
}

//This function will create a new directory to be added to the linked list
//The function will also ensure that the new directory will be added 
//in alphabetical order.
void PhoneList::addDirectory(string newName, int newACode, int newPhoneNum) {
	
	Directory* walker = firstPtr, * stalker = NULL;
	
	while (walker != NULL) {
		if (walker->name >= newName)
			break;
		stalker = walker;
		walker = walker->link;
	}
	if (walker != NULL && walker->name == newName)
		cout << "That name is already in the phone list." << endl;
	else {
		Directory* builder = new Directory;
		assert(builder);
		builder->name = newName;
		builder->areaCode = newACode;
		builder->phoneNo = newPhoneNum;

		builder->link = walker;
		
		if (walker == firstPtr)
			firstPtr = builder;
		else
			stalker->link = builder;
		
		noDirectories++;
		cout << "Added direcotory to phone list." << endl;
	}
}

//Removes a directory in the linked list
//handles removing the first , middle/last, not found and empty list cases 
void PhoneList::removeDirectory(string toRemove) {
	if (firstPtr == NULL)
		cout << "Nothing to remove. List is empty!!!" << endl;
	else {
		Directory* walker = firstPtr;
		Directory* stalker = NULL;
		while (walker != NULL && walker->name != toRemove) {
			stalker = walker;
			walker = walker->link;
		}
		if (walker == NULL)
			cout << "The Directory to remove was not found. :(" << endl;
		else {
			if (walker == firstPtr)
				firstPtr = firstPtr -> link;
			else
				stalker->link = walker->link;

			cout << "The direcotry was found and removed." << endl;
			delete walker;
			noDirectories--;
		}
	}
}