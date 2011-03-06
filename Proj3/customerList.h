#ifndef H_customerList
#define H_customerList

#include <iostream>
#include <string>
#include "circularList.h"
#include "orderedCircularList.h"
#include "customer.h"

using namespace std;

template <class Type>
class customerList:public orderedCircularList<Type>
{
public:

	bool custSearch(customer& cust);

	void custReturnVideo(customer& cust, string title);

	void custRentVideo(customer& cust, string title);

	int  custNoOfRentals(customer& cust);

	void rentedVideosInfo();

private:

	void searchCust(customer& cust, bool& found, nodeType<Type>* &current);

};

#endif
