#ifndef H_customer
#define H_customer

#include <iostream>
#include <string>
#include "circularList.h"
#include "personType.h"

using namespace std;

class customer:public personType
{
        friend ostream& operator<<(ostream&,  customer&);

public:

	void print();

	void custInfo(string first, string last);

	void rentVideo(string);

	void returnVideo(string);

	int getRentals();

	void printRentedVideo();

	customer(string first = "", string last = "");

	bool operator==(customer);

	bool operator!=(customer);

private:

	circularList<string> rentedVideoList;
};

#endif
 
