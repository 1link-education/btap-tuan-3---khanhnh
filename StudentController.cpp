#include "StudentController.h"
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
using namespace std;


void  StudentController::readfile(string filename) {
	int m = 0;
	int i = 0;
	int id = 0;
	string name;
	string address;
	string gender;
	float math = 0.0;
	float phys = 0.0;
	float chem = 0.0;
	string schoolid;

	//ifstream file(filename);
	ifstream file;
	file.open(filename, ios::in);
	bool checkfile = file.fail();
	if (checkfile == true)
	{
		cout << "No file be found.\n";
	}
	else
	{
		while (!file.eof()) {
			st[i] = new Student;
			file >> schoolid >> id >> name >> address >> gender >> math >> phys >> chem;
			st[i]->setS(id, name, address, gender, math, chem, phys, schoolid);
			i++;
			cout << "ID: " << id << "   Name: " << name << "    Address: " <<
				address << "   Gender: " << gender << "   Math: " << math
				<< "   Chemical: " << chem << "   Physical: " << phys << endl;
			m++;
		}
		if (file.eof())
		{
			cout << "Read file successful, all data from file has already been here.";
		}
		*n = m;
	}
	file.close();
}

void  StudentController::sortid(int*K[]) {
	int *x;
	for (int j = 0; j < sizeof(K) / sizeof(int); j++)
	{
		int m = j;
		for (int t = j + 1; t < sizeof(K) / sizeof(int); t++)
		{
			if (*K[t] < *K[m]) m = j;
			if (j < m)
			{
				x = K[j];
				K[j] = K[m];
				K[m] = x;
			}
		}
	}
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < sizeof(K); j++)
			if (StudentController::st[i]->id = *K[j])
				StudentController::st[i]->getS();
}

void  StudentController::sortal(string *A[]) {
	string *y;
	for (int j = 0; j < sizeof(A)/sizeof(A[0]); j++)
	{
		int m = j;
		for (int t = j + 1; t < sizeof(A)/sizeof(A[0]); t++)
		{
			if (*A[t] < *A[m]) m = j;
			if (j < m)
			{
				y = A[j];
				A[j] = A[m];
				A[m] = y;
			}
		}
	}
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < sizeof(A)/sizeof(A[0]); j++)
			if (StudentController::st[i]->name.compare(*A[j]))
				StudentController::st[i]->getS();
}
void  StudentController::sortsum(float *S[]) {
	float *z;
	for (int j = 0; j < sizeof(S)/sizeof(S[0]); j++)
	{
		int m = j;
		for (int t = j + 1; t < sizeof(S)/sizeof(S[0]); t++)
		{
			if (*S[t] < *S[m]) m = j;
			if (j < m)
			{
				z = S[j];
				S[j] = S[m];
				S[m] = z;
			}
		}
	}
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < sizeof(S)/sizeof(S[0]); j++)
			if (StudentController::st[i]->sum = *S[j])
				st[i]->getS();
}
void  StudentController::searchsum(int k) {
	int j = 0;
	int **K = new int *[50]; // lưu sbd sinh viên K = key ~ id
	string  **A = new string *[50]; // lưu tên sinh viên A = ABC ~ name
	float **S = new float*[50]; // lưu tổng điểm sinh viên S = sum
	float key;
	cout << "\n Enter sum: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
		{
			if (key = st[i]->sum) {
				st[i]->id = *K[j];
				st[i]->name = *A[j];
				st[i]->sum = *S[j];
				j++;
				check = 0;
			}
		}
	else
	{
		cout << "\nNo student found. Please try again!";
		searchsum(k);
	}
	switch (k)
	{
	case 1:
		sortid(K);
		break;
	case 2:
		sortal(A);
		break;
	case 3:
		sortsum(S);
		break;
	}
}

void  StudentController::searchid() {
	int key;
	cout << "\nEnter id: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
		{
			if (key = st[i]->id) {
				st[i]->getS();
				check = 0;
			}
		}
	else
	{
		cout << "\nNo student found. Please try again!";
		searchid();
	}
}

void  StudentController::searchname() {
	string key;
	fflush(stdin);
	getline(std::cin, key);
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
		{
			if (key.compare(st[i]->name)) {
				st[i]->getS();
				check = 0;
			}
		}
	else
	{
		cout << "\nNo student found. Please try again!";
		searchname();
	}
}

void  StudentController::searchmath(int k) {
	int j = 0;
	int **K = new int *[50];
	string  **A = new string *[50];
	float **S = new float*[50];
	float key;
	cout << "\nEnter math grade: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
			if (key = st[i]->math) {
				st[i]->id = *K[j];
				st[i]->name = *A[j];
				st[i]->sum = *S[j];
				j++;
				check = 0;
			}
			else
			{
				cout << "\nNo student found. Please try again!";
				searchmath(k);
			}
	switch (k)
	{
	case 1:
		sortid(K);
		break;
	case 2:
		sortal(A);
		break;
	case 3:
		sortsum(S);
		break;
	}
}

void  StudentController::searchchem(int k) {
	int j = 0;
	int **K = new int *[50];
	string  **A = new string *[50];
	float **S = new float*[50];
	float key;
	cout << "\nEnter chemical grade: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
			if (key = st[i]->chem) {
				st[i]->id = *K[j];
				st[i]->name = *A[j];
				st[i]->sum = *S[j];
				j++;
				check = 0;
			}
			else
			{
				cout << "\nNo student found. Please try again!";
				searchchem(k);
			}
	switch (k)
	{
	case 1:
		sortid(K);
		break;
	case 2:
		sortal(A);
		break;
	case 3:
		sortsum(S);
		break;
	}
}

void  StudentController::searchphys(int k) {
	int j = 0;
	int **K = new int *[50];
	string  **A = new string *[50];
	float **S = new float*[50];
	float key;
	cout << "\nEnter physical grade: ";
	cin >> key;
	bool check = 1;
	if (check = 1)
		for (int i = 0; i < *n; i++)
			if (key = st[i]->math) {
				st[i]->id = *K[j];
				st[i]->name = *A[j];
				st[i]->sum = *S[j];
				j++;
				check = 0;
			}
			else
			{
				cout << "\nNo student found. Please try again!";
				searchphys(k);
			}
	switch (k)
	{
	case 1:
		sortid(K);
		break;
	case 2:
		sortal(A);
		break;
	case 3:
		sortsum(S);
		break;
	}
}

void  StudentController::modify() {
	cout << "\nChoose id of student who need to modify.\nEnter it: " << endl ;
	int _id;
	cin >> _id;
	int id;
	string name;
	string address;
	string gender;
	float math;
	float chem;
	float phys;
	for (int k = 0; k <= *n; k++)
		if (_id = st[k]->id) {
			cout << "Enter student ip: ";
			cin >> id;
			fflush(stdin);
			getline(std::cin, name);
			cout << "\nEnter student name: ";
			getline(std::cin, name);
			fflush(stdin);
			cout << "\nEnter student address: ";
			getline(std::cin, address);
			fflush(stdin);
			cout << "\nEnter student gender: ";
			getline(std::cin, gender);
			cout << "\nEnter math grade: ";
			cin >> math;
			cout << "\nEnter chemical grade: ";
			cin >> chem;
			cout << "\nEnter physical grade: ";
			cin >> phys;
			st[k]->setS(id, name, address, gender, math, chem, phys, st[k]->schoolid);
		}
	/*for (int i = 0; i < *n; i++)
		if (check(i, st[i]->id, st[i]->name, st[i]->address, st[i]->gender, st[i]->math, st[i]->chem, st[i]->phys) == 0)
		{
			cout << "\nEntered is failed. Please try again!";
			modify();
		}*/
}


void  StudentController::del() {
	cout << "\nEnter an id of student which you want to delete.\nEnter it: ";
	int key;
	cin >> key;
	for (int i = 0; i < *n; i++)
		if (StudentController::st[i]->id = key)
			delete  StudentController::st[i];
}

void  StudentController::printList() {
	for (int i = 0; i < *n; i++)
		st[i]->getS();
	return;
}

