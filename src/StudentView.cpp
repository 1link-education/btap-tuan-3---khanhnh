#include "StudentView.h"
#include "StudentController.h"
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>

string View::getSchoolName() {
	string schoolname;
	cout << "Please enter the school name: ";
	cin >> schoolname;
	return schoolname;
}
void View::modifyMenu() {
	int select;
	cout << "\nDo you want to modify or delete a student? Please remember its id.";
	cout << "\n1. Yes I want to modify a student.";
	cout << "\n2. Yes I want to delete a student.";
//	cout << "\n3. Yes I want to add a student.";
	cout << "\n3. No\n";
	cin >> select;
	if (select <= 4)
		switch (select)
		{
		case 1: a.modify(); mainMenu(); break;
		case 2: a.del(); mainMenu(); break;
	//	case 3: a.add(); mainMenu(); break;
		case 3: mainMenu(); break;
		}
	else {
		cout << "Error. Please try again.";
		modifyMenu();
	}
}



void View::searchMenu() {
	int select;
	int search;
	cout << "\n1. Search by sum grade of 3 subject (mathematic, chemical, physical).";
	cout << "\n2. Search by id.";
	cout << "\n3. Search by name.";
	cout << "\n4. Search by grade of mathematic.";
	cout << "\n5. Search by grade of chemical.";
	cout << "\n6. Search by grade of physical.";
	cout << "\n7. Back.\n";
	cin >> select;
	if (select <= 7)
		switch (select)
		{
		case 1: sortMenu(search = 1); break;
		case 2: a.searchid(); break;
		case 3: a.searchname(); break;
		case 4: sortMenu(search = 4); break;
		case 5: sortMenu(search = 5); break;
		case 6: sortMenu(search = 6); break;
		case 7: mainMenu(); break;

		}
	else {
		cout << "Error. Please try again.";
		searchMenu();
	}
}

void View::sortMenu(int search) {
	int select;
	cout << "\n1. Sort by id.";
	cout << "\n2. Sort by alphabet.";
	cout << "\n3. Sort by sum of grade.";
	cout << "\n4. Back.\n";
	cin >> select;
	if (select <= 3)
	{
		switch (search)
		{
		case 1: a.searchsum(select); break;
		case 4: a.searchmath(select); break;
		case 5: a.searchchem(select); break;
		case 6: a.searchphys(select); break;
		}
	}
	else
		if (select == 4) searchMenu();
		else
		{
			cout << "Error. Please try again.";
			sortMenu(search);
		}
}


int View::mainMenu()
{
	a.filename = getSchoolName();
	int select;
	cout << "1. Search.\n";
	cout << "2. Modify a student.\n";
	cout << "3. Get student list.\n";
	cout << "4. Exit.\n";
	cin >> select;
	while (select <= 5)
	{
		switch (select)
		{
		case 1: searchMenu(); break;
		case 2: modifyMenu(); break;
		case 3: a.printList(); mainMenu(); break;
		case 4: break;
		}
	}
	return 0;
}
