//--------------------------------------------------------------------
//
//  Laboratory 3                                       
//
//  Class declaration for the array implementation of the List ADT
//
//--------------------------------------------------------------------

#ifndef LIST_03
#define LIST_03

const int defMaxListSize = 10;   // Default maximum list size

template <class T>
class List
{
  public:

    typedef T DataType;

    // Constructor  -- creates a dynamic array of DataType of size maxNumber
    List ( int maxNumber = defMaxListSize );
    //Post: dynamic array of DataType of size maxnumber Number has been created
    //      cursor is set to -1, size to 0, and maxsize to maxNumber

    //Copy Constructor
    List (const List& listc);

    // Destructor -- 
    ~List ();
    // Post: memory for dynamic array is returned to heap

    void operator =(const List& list);

    T& operator [](const int index);

    //const T& operator [](const int index);

    // List manipulation operations
    void insert ( const T &newDataItem );  
      // Pre: List is not full
      // Post: newDataItem has been added at end of list, size increased   
      //       cursor is positioned at newDataItem

    DataType getCursor () const; 
    // Pre: 0<= cursor < size
    // Post: A copy of the data item marked by the cursor is returned.  
    
    // List status operations
    bool isEmpty () const;                    // List is empty
    bool isFull () const;                     // List is full

    // List iteration operations
    void gotoBeginning ();
    //Pre: list is not empty
    //Post. cursor is set to 0
    
    bool gotoNext () ;
    //Post: If the cursor is not at the end of the list, the cursor is
    //      is moved to the next item in the list and true is returned;
    //      else, cursor is unchanged and false is returned.
    
   

  private:

    // Data members
    int maxSize,
        size,             // Actual number of data item in the list
        cursor;           // Cursor array index
    T *dataItems;  // Array containing the list data item
};

#include "lab3imp2.cc"
#endif
