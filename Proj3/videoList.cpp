#include <iostream>
#include <string>
#include "videoList.h"

using namespace std;

bool videoList::isVideoAvailable(string title) 
{
	bool found;
	nodeType<videoType> *location;

	searchVideoList(title,found,location);

	if(found)
		found = (location->info.getNoOfCopiesInStock() > 0);
	else 
		found = false;

	return found;
}

void videoList::videoCheckIn(string title)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(title,found,location);

	if(found)
		location->info.checkIn();
	else
		cout<<"The store does not carry this video."<<endl;
}

void videoList::videoCheckOut(string title)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(title,found,location);

	if(found)
		location->info.checkOut();
	else
		cout<<"The store does not carry this video."<<endl;
}

bool videoList::videoCheckTitle(string title)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(title,found,location);

	return found;
}

void videoList::videoUpdateInStock(string title, int num)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(title,found,location);

	if(found)
		location->info.updateInStock(num);
	else
		cout<<"The store does not carry this video."<<endl;
}

void videoList::videoSetCopiesInStock(string title, int num)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(title,found,location);

	if(found)
		location->info.setCopiesInStock(num);
	else
		cout<<"The store does not carry this video."<<endl;
}

bool videoList::videoSearch(string title)
{
	bool found = false;
	nodeType<videoType> *location;

	searchVideoList(title,found,location);

	return found;
}

void videoList::searchVideoList(string title, bool& found, nodeType<videoType>* &current)
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
		if(current->info.checkTitle( title))  
       			found = true;
		else
			current = current->link; 
	}
}

void videoList::videoPrintTitle()
{
	nodeType<videoType>* current;

	current = first;
	while(current != NULL)
	{
		current->info.printTitle();
		current = current->link;
	}
}
