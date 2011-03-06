#ifndef person_H
#define person_H

#include <iostream>
#include <string>

using namespace std;

class personType
{
   friend ostream& operator<<(ostream&, const personType&);

public:
	void print() const;

	void setName(string first, string last);

	string getFirstName();

	string getLastName();

	personType(string first = "", string last = "");

	bool operator==(personType);

	bool operator!=(personType);

protected:

	string firstName;

	string lastName;
};

#endif
 
