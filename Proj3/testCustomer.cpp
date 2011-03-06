#include <iostream>
#include <string>
#include "customer.h"

using namespace std;

void Menu();

int main()
{
	int choice;
	string video, fname, lname;

        cout << "Enter customer first name: ";
        cin >> fname;
        cout << "Enter customer last name: ";
        cin >> lname;
        cout << endl;

	Menu();

	cout << "Enter choice: ";
	cin >> choice;
	cout << endl;

	customer one (fname, lname);

	while(choice != 4)
	{
		switch(choice)
		{
		case 1:   one.print();
			  break;
		
		case 2:   cout << "Enter name of video: ";
			  cin >> video;
			  one.rentVideo(video);
			  break;

		case 3:   cout << "Enter name of video:";
			  cin >> video;
			  one.returnVideo(video);
			  break;

		default:  cout << "Pick Again!" << endl;
		}

		Menu();
		cout << "Enter choice: ";
		cin >> choice;
		cout << endl;
	}

	return 0;
}

void Menu()
{
	cout << "1. Print customer." << endl;
	cout << "2. Customer rents video." << endl;
	cout << "3. Customer returns video." << endl;
	cout << "4. Quit" << endl;
}
