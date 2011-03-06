#include<iostream>
#include<cassert>
#include<algorithm>

template <class T>
// Constructor  -- creates a dynamic array of DataType of size maxNumber
List<T>::List ( int maxNumber )
//Post: dynamic array of DataType of size maxnumber Number has been created
//      cursor is set to -1, size to 0, and maxsize to maxNumber
{
    dataItems = new T[maxNumber];
    size = 0;
    cursor = -1;
    maxSize = maxNumber; 
}

/*template <class T>
const T& List<T>::operator [](const int index)
{
    return dataItems[index-1];        
} */

template <class T>
T& List<T>::operator [](const int index)
{   
    return dataItems[index-1];    
} 

template <class T>
// Copy Constructor
List<T>::List(const List<T>& listc)
{
    dataItems = new T[listc.maxSize];
    size = listc.size;
    std::copy(listc.dataItems, listc.dataItems + size, dataItems);
}

template <class T>
void List<T>::operator =(const List<T>& list)
{
    T *newlist;

    if (this == &list)
        return;
                        
    if (maxSize != list.maxSize)
      {
        newlist = new T[list.maxSize];
        delete [] dataItems;
        dataItems = newlist;
      }

    size = list.size;
    std::copy(list.dataItems, list.dataItems + size, dataItems);
}

template <class T>
// Destructor -- 
List<T>::~List ()
// Post: memory for dynamic array is returned to heap
{
    delete [] dataItems;
}

template <class T>
// List manipulation operations
void List<T>::insert ( const T &newDataItem )  
// Pre: List is not full
// Post: newDataItem has been added at end of list, size increased   
//       cursor is positioned at newDataItem
{
    if (isFull())
    {
        cout << "List is full!";
        return;
    }    
    dataItems[size] = newDataItem;
    cursor = size;
    ++size;
}

template <class T>
T List<T>::getCursor () const 
// Pre: cursor < size
// Post: A copy of the data item marked by the cursor is returned.  
{
    assert(cursor < size);
    return dataItems[cursor];
}

    
template <class T>
// List status operations
bool List<T>::isEmpty () const                    // List is empty
{
    if (size == 0) return true;
    return false;
}

template <class T>
bool List<T>::isFull () const                     // List is full
{
    if (size == maxSize) return true;
    return false;
}

template <class T>
// List iteration operations
void List<T>::gotoBeginning ()
//Pre: list is not empty
//Post: cursor is set to 0
{
    assert(!isEmpty());
    cursor = 0;
}
    
template <class T>
bool List<T>::gotoNext ()
//Post: If the cursor is not at the end of the list, the cursor is
//      is moved to the next item in the list and true is returned;
//      else, cursor is unchanged and false is returned.
{    
    if (cursor == size - 1) return false;

    cursor++;
    return true;
}   
