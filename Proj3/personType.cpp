#include <iostream>
#include "personType.h"

using namespace std;

void personType::print() const
{
	cout << firstName << " " << lastName;
}

void personType::setName(string first, string last)
{
	firstName = first;
	lastName = last;
}

string personType::getFirstName()
{
	return firstName;
}

string personType::getLastName()
{
	return lastName;
}

personType::personType(string first, string last)
{ 
	firstName = first;
	lastName = last;
}

bool personType::operator== (personType person1)
{
	return (firstName == person1.firstName && lastName == person1.lastName);
}

bool personType::operator!=(personType person1)
{
	return (firstName != person1.firstName || lastName != person1.lastName);
}

ostream& operator<<(ostream& outs, const personType &name)
{
	outs << name.firstName << " " << name.lastName;
	return outs;
}
