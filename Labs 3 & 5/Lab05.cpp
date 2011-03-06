#include <iostream>
#include "Lab05.h"

using namespace std;

LinkedList::LinkedList()
{
	// Place implementation for constructor here.
}

LinkedList::~LinkedList()
{
	// Place implementation for destructor here.
}

void LinkedList::AddStudents()
{
	unsigned int dNumStudents;

	cout << "How many students are in the group? ";
	cin >> dNumStudents;

	for (int i = 0; i < dNumStudents; i++)
	{
		Node *tmpNode;

		tmpNode = new(Node);
		cout << "Enter first name of student #" << i << ": ";
		cin >> tmpNode->StudentName;
		tmpNode->next = NULL;

		AddNodeToList(tmpNode);
	}
}

void LinkedList::ChooseStudent()
{
	unsigned int dSkipVal;
	

	cout << "Enter a non-negative integer: ";
	cin >> dSkipVal;

	// insert code here to randomly select starting place

	while (m_dNumNodes > 1 && m_Head != NULL)
	{
		int i = dSkipVal;
		Node *nodePtr = m_Head;

		while (i > 0)
		{
			nodePtr = nodePtr->next;
			i--;
		}
		
		cout << "Removing " << nodePtr->StudentName << " from the group." << endl;
		DeleteNodeFromList(nodePtr);
		cout << "The current group contains:" << endl;
		PrintList();
	}

	cout << endl << "The unlucky student is: ";
	PrintList();
	cout << endl;
}

void LinkedList::PrintList()
{
	// Place implementation of PrintList here.
}

void LinkedList::AddNodeToEmptyList(Node *newNode)
	// Precondition: The linked list is empty.
	// Postcondition: The linked list contains only newNode; newNode->next
	//                points to itself; head and tail point to newNode,
	//				  numNodes == 1
{
	// Place implementation of AddNodeToEmptyList here.
}

void LinkedList::AddNodeToList(Node *newNode)
	// Precondition: newNode is a node to add to the circularly
	//               linked list.
	// Poscondition: newNode has been added to the list.
{
	// Place implementation of AddNodeToList here.
}

void LinkedList::DeleteNodeFromList(Node *nodePtr)
	// Precondition: nodePtr points to a node in the linked list.
	// Postcondition: The node pointed to by nodePtr is no longer
	//                in the linked list, and its memory has been
	//				  returned to the heap.
{
	// Place implementation of DeleteNodeFromList here.
}
