#ifndef H_circularList
#define H_circularList

#include <iostream>
#include <cassert>

template<class Type>
struct nodeType
{
	Type info;
	nodeType<Type> *link;
};

template<class Type>
class circularList
{
public:

    template<class TypeT>
    friend std::ostream& operator<<(std::ostream& outs, const circularList<TypeT>& list);

    const circularList<Type>& operator=(const circularList<Type>&); 
		//Overloads the assignment operator.

    void initializeList(); 
 		//Initializes the list to an empty state.
	      //Postcondition: first = NULL, count = 0

    bool isEmptyList();
 		//Function to determine whether the list is empty. 
		//Postcondition: Returns true if the list is empty;
		//               otherwise, returns false.

    int length();
		//Function to return the number of nodes in the 
		//list.
		//Postcondition: The value of count is returned.

    void destroyList();
 		//Function to delete all the nodes from the list.
  		//Postcondition: first = NULL, count = 0

    Type front(); 
 		//Function to return the first element of the list.
 		//Precondition: The list must exist and must not be
		//empty.
  		//Postcondition: If the list is empty, then the 
 		//               program terminates; otherwise, 
	        //               the first element of the list is 
		//               returned.

    Type back(); 
       //Function to return the last element of the
       //list.
		//Precondition: The list must exist and must not
		//be empty.
		//Postcondition: If the list is empty, then the 
		//               program terminates; otherwise,
		//               the last element of the list is 
		//               returned.

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

    circularList(); 
   		//default constructor
 		//Initializes the list to an empty state.
 		//Postcondition: first = NULL, count = 0 

    circularList(const circularList<Type>& otherList); 
         //copy constructor

    ~circularList();   
    	//destructor
   	//Deletes all the nodes from the list.
    	//Postcondition: The list object is destroyed. 

protected:

    int count;		//variable to store the number of 
 					//elements in the list

    nodeType<Type> *first; //pointer to the first node of 
                           //the list
private:

    void copyList(const circularList<Type>& otherList); 
		//Function to make a copy of otherList.
		//Postcondition: A copy of otherList is created 
		//               and assigned to this list.
};

template<class Type>
bool circularList<Type>::isEmptyList()
{
	return(first == NULL);
}

template<class Type>
circularList<Type>::circularList() // default constructor
{
	first = NULL;
	count = 0;
}

template<class Type>
void circularList<Type>::destroyList()
{
	nodeType<Type> *temp;    
	nodeType<Type> *current = first; 
						
	if(first != NULL)
	{
		current = first->link;
		first->link = NULL;
	}

	while(current != NULL)    
	{
	   temp = current;        
	   current = current->link; 
	   delete temp;         
	}

	first = NULL;	

 	count = 0;
}
	
template<class Type>
void circularList<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

template<class Type>
int circularList<Type>::length()
{
 	return count;
}  // end length

template<class Type>
Type circularList<Type>::front()
{   
    assert(first != NULL);

	if(first->link == first)
		return first->info;
	else
   		return first->link->info; //return the info of the first node	
}//end front

template<class Type>
Type circularList<Type>::back()
{   
	 assert(first != NULL);
   	 return first->info; //return the info of the last node	
}//end back

template<class Type>
bool circularList<Type>::search(const Type& searchItem)
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

		found = (current->info == searchItem); 						
	}

    return found;
}//end search

template<class Type>
void circularList<Type>::insertNode(const Type& newItem)
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
	   first->link = newNode;
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
void circularList<Type>::deleteNode(const Type& deleteItem)
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

//Overloading the stream insertion operator
template<class TypeT>
std::ostream& operator<< (std::ostream& outs, const circularList<TypeT>& list)
{
	nodeType<TypeT> *current; //pointer to traverse the list
	
	if(list.first != NULL)
	{
		current = list.first->link;    
					   
		while(current != list.first) //while more data to print
		{
			outs << current->info << " ";
			current = current->link;
		}

		outs << list.first->info << " ";
	}

	return outs;
}

template<class Type>
circularList<Type>::~circularList() // destructor
{
	destroyList(); 
}//end destructor

template<class Type>
void circularList<Type>::copyList(const circularList<Type>& otherList) 
{
   nodeType<Type> *newNode; 
   nodeType<Type> *current; 
   nodeType<Type> *temp; 

   if(first != NULL)	
	  destroyList();

   if(otherList.first == NULL) 
   {
		first = NULL;
 		count = 0;
   }
   else
   {
		current = otherList.first->link;  
									
		count = otherList.count;
	
		temp = new nodeType<Type>; 

 		assert(temp != NULL);

		temp->info = current->info; 
		first = temp;    		     
            						   
		current = current->link;     

		while(current != otherList.first)
		{
			newNode = new nodeType<Type>; 
			assert(newNode!= NULL);

			newNode->info = current->info;	
	
			first->link = newNode; 		
			first = newNode;   			
										
			current = current->link;	
       		}							
		
	
		if(temp == first)
			first->link = first;
		else
		{
			newNode = new nodeType<Type>; 
			assert(newNode!= NULL);
			newNode->info = current->info;	
			first->link = newNode; 		
			first = newNode;   		
			first->link = temp;
		}

	}
}

//copy constructor
template<class Type>
circularList<Type>::circularList(const circularList<Type>& otherList) 
{
	first = NULL;

	copyList(otherList);
	
}//end copy constructor

//overload the assignment operator
template<class Type>
const circularList<Type>& circularList<Type>::operator=(const circularList<Type>& otherList)
{ 
	if(this != &otherList) 
	{
		copyList(otherList);
	}

	return *this; 
}

#endif
