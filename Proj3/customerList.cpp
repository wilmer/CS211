#include <iostream>
#include <string>

#include "customerList.h"

using namespace std;

template <class Type>
bool customerList<Type>::custSearch(customer& cust)
{
	bool found;
	nodeType<Type> *current;

	searchCust(cust, found, current);

	return found;
}

template <class Type>
void customerList<Type>::custReturnVideo(customer& cust, string title)
{
	bool found;
	nodeType<Type> *current;

	searchCust(cust, found, current);
	current->info.returnVideo(title);
}

template <class Type>
void customerList<Type>::custRentVideo(customer& cust, string title)
{
	bool found;
	nodeType<Type> *current;

	searchCust(cust, found, current);
	current->info.rentVideo(title);
}

template <class Type>
int customerList<Type>::custNoOfRentals(customer& cust)
{
	bool found;
	nodeType<Type> *current;

	searchCust(cust, found, current);

	return current->info.getNoOfRentals();
}

template <class Type>
void customerList<Type>::rentedVideosInfo()
{
	nodeType<Type> *current;
	current = first;

	cout << "Video Rental Information" << endl << endl;
	while(current != NULL)
	{
		if(current->info.getNoOfRentals() > 0)
		{
			cout << "Customer Name: " << current->info.getLastName() << endl;
			cout << "Videos Rented: " << endl;
			current->info.printRentedVideo();
			cout << endl;
		}

		current = current->link;
	}
}

template <class Type>
void customerList<Type>::searchCust(customer& cust, bool& found, nodeType<Type>* &current)
{
	found = false;
   
   	if(first == NULL)
  	{
	    cout << "List is empty." << endl;
   	}
	else
   	{
		current = first;
		found = false;

		while(!found && current != NULL)
		{
			if(current->info.getLastName() == cust.getLastName())
       			{
				found = true;
			}
			else
			{
				current = current->link;
			}
		}
	}
}

