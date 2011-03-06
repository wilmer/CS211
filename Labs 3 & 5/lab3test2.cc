//--------------------------------------------------------------------
//
//  Laboratory 3                                       lab03test.cc
//
//  Copy of example problem in prelab section (step 2) that demonstrates
//  using a list to read in a set of numbers and then traverse the list
//  calculating the sum of the numbers in the list
//
//--------------------------------------------------------------------

// For this example, set DataType to "int" in listarr.h,

#include <iostream>
#include "lab3listp2.h"   // Include the class declaration file
#include <vector>

using namespace std;

int main ()
{

// Original

    List<int> samples(7);        // Set of samples
    List<int> test(8);
    int change;
    int newSample,            // Input sample
        total = 0;            // Sum of the input samples

    // Read in a set of samples from the keyboard.

    cout << "Enter list of 7 samples" << endl;
    for (int i =0; i< 7; ++i)
      {  cin >> newSample;
         samples.insert(newSample);
      }

    // Sum the samples and output the result.

    if ( !samples.isEmpty() )            // Verify that list has data
    {
       samples.gotoBeginning();          // Go to beginning of list
       do
         total += samples.getCursor();   // Add element to running sum
       while ( samples.gotoNext() );     // Go to next element (if any)
    }

    cout << "Sum is " << total << endl;

// Use STL vector class
    
    total = 0;
    vector<int> v1(7);

    cout << "Enter list of 7 new samples (using vector class)" << endl;
    for (int i =0; i< 7; ++i)
      {  cin >> newSample;
         v1.push_back(newSample);
      }

    // Sum the samples and output the result.

    if ( !v1.empty() )            // Verify that list has data
    {
       for (int i=0; i<v1.size(); i++)
         {total += v1[i];}   // Add element to running sum
    }

    cout << "Sum is " << total << endl;
    

// Test overloaded = operator

    cout << "Enter one more sample to test = operator" << endl;
    cin >> newSample;
    test = samples;
    test.insert(newSample);
    cout << endl << "Original List" << endl;
    samples.gotoBeginning();
    test.gotoBeginning();
    do
        cout << samples.getCursor() << endl;
    while ( samples.gotoNext() );
    cout << endl << "Test List" << endl;
    do
        cout << test.getCursor() << endl;
    while ( test.gotoNext() );

/*/ Test Copy Constructor

    cout << endl << "Enter one more sample to test copy constructor" << endl;
    cin >> newSample;
    List<int> testc = samples;
    testc.insert(newSample);
    cout << endl << "Original List" << endl;
    samples.gotoBeginning();
    testc.gotoBeginning();
    do
        cout << samples.getCursor();
    while ( samples.gotoNext() );
    
    cout << endl << "List made by copy constructor:" << endl;
    do
        cout << testc.getCursor();
    while ( testc.gotoNext() );      */

// Test overloaded [] operator

    cout << endl << "Choose the number of the element in the list you'd like to change:";
    cin >> newSample;
    cout << endl << "This element is currently: " << samples[newSample];
    cout << endl << "What would you like to change it to: ";
    cin >> change;
    samples[newSample] = change;
    cout << endl << "The list is now: ";
    samples.gotoBeginning();
    do
        cout << samples.getCursor();
    while(samples.gotoNext());     

//Use string List    

    List<string> strings(7);        // Set of strings
    string newString;            // Input string

    // Read in a set of stings from the keyboard.

    cout << endl << "Enter list of  7 strings" << endl;
    for (int i =0; i< 7; ++i)
      {  cin >> newString;
         strings.insert(newString);
      }

    // Output the result.

    if ( !strings.isEmpty() )            // Verify that list has data
    {
       strings.gotoBeginning();          // Go to beginning of list
       cout << endl << "The strings entered were:" << endl;
       do
         cout << strings.getCursor() << endl;   // Add element to running sum
       while ( strings.gotoNext() );     // Go to next element (if any)
    }

    return 0;
} 


