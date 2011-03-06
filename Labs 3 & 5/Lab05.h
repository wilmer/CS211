#ifndef LAB05_H
#define LAB05_H

struct Node
{
	char StudentName[30];
	Node *next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void AddStudents();
	void ChooseStudent();

	void PrintList();

private:
	void AddNodeToEmptyList(Node *newNode);

	void AddNodeToList(Node *newNode);

	void DeleteNodeFromList(Node *nodePtr);

	Node *m_Head;
	Node *m_Tail;
	unsigned int m_dNumNodes;
};

#endif
