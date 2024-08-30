#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>

using namespace std;

/*a specification file for a phonelist class
holds a custom stucture, Directory and 
has tile and phone number
The Directory structure can behave like a linked list
and holds information, like a name, phone number, and area code
and a pointer to another directory
By: Dhanan Thannoo
*/

struct Directory
{
	string name;
	int areaCode;
	int phoneNo;
	Directory* link;
};

class PhoneList {
protected:
	Directory* firstPtr;
	string title;
	int noDirectories;
public:
	PhoneList(string/*name of phonelist*/);
	~PhoneList();
	void showList(ostream&/*output file stream*/) const;
	void addDirectory(string/*name*/, int/*area code*/ ,int/*phone num*/);
	void removeDirectory(string /*person or buisness*/);
	int getNoDirectories() const { return noDirectories; }
	string getTitle() const { return title; }
};
