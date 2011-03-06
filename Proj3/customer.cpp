#include <iostream>
#include "customer.h"

using namespace std;

void customer::print()
{
	personType::print();
	cout << endl << "Videos rented:" << endl;
	printRentedVideo();
	cout << endl << "Number rented:" << getRentals() << endl;
}

void customer::custInfo(string first, string last)
{
	personType::setName(first,last);
}
 
void customer::rentVideo(string title)
{
	rentedVideoList.insertNode(title);
}

void customer::returnVideo(string title)
{
	rentedVideoList.deleteNode(title);
}

int customer::getRentals()
{
	return rentedVideoList.length();
}

void customer::printRentedVideo()
{
	cout << rentedVideoList << endl;
}

customer::customer(string first, string last):personType(first, last)
{
}

bool customer::operator==(customer cust)
{
	string fname = cust.getFirstName();
	string lname = cust.getLastName();

	return(firstName == fname && lastName == lname);
}

bool customer::operator!=(customer cust)
{
	string fname = cust.getFirstName();
	string lname = cust.getLastName();

	return(firstName != fname && lastName != lname);
}

ostream& operator<<(ostream& outs,  customer& cust)
{
	string fname = cust.getFirstName();
	string lname = cust.getLastName();

	outs << fname << " " << lname << " " << cust.rentedVideoList.length() << endl;
	
	return outs;
}
