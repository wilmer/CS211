#include <stdlib.h> // or <cstdlib>
#include "Lab05.h"

int main()
{
	LinkedList objLL;

	objLL.AddStudents();
	objLL.PrintList();
	objLL.ChooseStudent();

	return EXIT_SUCCESS;
}
