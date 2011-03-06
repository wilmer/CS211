#include "circularList.h"

using namespace std;

void testCopyConstructor(circularList<int> List);

int main()
{
	circularList<int> list1, list2;			
	int num, i;										

	cout << "Enter five numbers:" << endl;										

	for(i=1; i <= 5; i++)								
	{
		cin >> num;									
		list1.insertNode(num);						
	}

	cout << endl;										

	cout << "List 1: " << endl << list1 << endl;			

	cout << "List 1 length is: " << list1.length() << endl;			

	cout << "Enter a number to search for: ";
	
	cin >> num;										
	
	cout << endl;										

	if(list1.search(num))
	{							
		cout << num << " is in the list." << endl;									
	}
	else											
	{
		cout << num << " is not in the list." << endl;	
	}

	cout << "Enter a number to delete: ";								

	cin >> num;										

	cout << endl;										

	list1.deleteNode(num);							
	
	cout << "After deletion List 1 is: " << list1 << endl;					

	cout << "List 1 length is now " << list1.length() << endl;						

	list2 = list1;	   

	cout << "List 2 is: " << list2 << endl;			
	
	cout << "Length of List 2 is " << list2.length() << endl;									

	testCopyConstructor(list1);						

	cout << "List 1: " << list1 << endl;			

	return 0;			 							
}

void testCopyConstructor(circularList<int> List)
{
}
