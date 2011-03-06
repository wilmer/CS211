#ifndef H_orderedCircularList
#define H_orderedCircularList

#include "circularList.h"

using namespace std;

template<class Type>
class orderedCircularList:public circularList<Type>
{

public:

    orderedCircularList(); 

    bool search(const Type& searchItem);
		//Function to determine whether searchItem is in 
		//the list.
		//Postcondition: Returns true if searchItem is found
		//               in the list; otherwise, it returns
		//               false.

    void insertNode(const Type& newItem);

    void deleteNode(const Type& deleteItem);
  		//Function to delete deleteItem from the list.
 		//Postcondition: If found, the node containing 
   		//               deleteItem is deleted from the 
		//                list and count is decremented by 1. 
};

template<class Type>
bool orderedCircularList<Type>::search(const Type& searchItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found;

    found = false;

	if(first != NULL)
	{
        current = first->link;		

		while(current != first && !found)		
			if(current->info >= searchItem)			
				found = true;
			else
				current = current->link;  
		if(found)
			found = (current->info == searchItem); 						
	}

    return found;
}//end search

template<class Type>
void orderedCircularList<Type>::insertNode(const Type& newItem)
{
	nodeType<Type> *current;
	nodeType<Type> *beforeCurrent;
	nodeType<Type> *newNode;

	bool found;

	newNode = new nodeType<Type>; 
 	assert(newNode != NULL);

	newNode->info = newItem;  
	newNode->link = NULL;     
                              

	if(first == NULL) 
	{	
	   first = newNode;
	   first->link = newNode;//?
	   count++;
 	}
	else
	{
		if(newItem >= first->info)
		{
			newNode->link = first->link;
			first->link = newNode;
			first = newNode;
		}
		else
		{
			beforeCurrent = first;
			current = first->link;
			found = false;

			while(current != first && !found)		
				if(current->info >= newItem)			
					found = true;
				else
				{
					beforeCurrent = current;
					current = current->link;
				}
	   		  
			beforeCurrent->link = newNode;
			newNode->link = current;
		}
		count++;
	}
}

template<class Type>
void orderedCircularList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; 
	nodeType<Type> *beforeCurrent; 
	bool found;

	if(first == NULL)   
		cout << "Empty list.\n";
	else
	{
		found = false;
		beforeCurrent = first;   
		current = first->link;  
	
		while(current != first && !found)
  			if(current->info >= deleteItem) 
				found = true;
			else
			{
				beforeCurrent = current;
				current = current->link;
			}
	
		if(current == first)
		{
			if(first->info == deleteItem)
			{
				if(first == first->link)
					first = NULL;
				else
				{
					beforeCurrent->link = current->link;
					first = beforeCurrent;
				}
				delete current;

				count--;
			}
			else
				cout << "The item is not in the list." << endl;
		}
		else
			if(current->info == deleteItem) 
			{
				beforeCurrent->link = current->link;
				count--;
				delete current;  
			}
			else
				cout << "Item is not in the list." << endl;
	} 
} 

#endif 
