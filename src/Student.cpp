#include "Student.h"
#include<iostream>
#include<string>
#include<fstream>
#include<ostream>

using namespace std;

std::string filename = ".input";
void Student::setS(int _id, string _name, string _address, string _gender, float _math, float _chem, float _phys, int _schoolid) {

	id = _id;
	name = _name;
	address = _address;
	gender = _gender;
	math = _math;
	chem = _chem;
	phys = _phys;
	schoolid = _schoolid;
}

void Student::getS() {
	cout << "School id: " << schoolid << endl;
	cout << "Id: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Gender: " << gender << endl;
	cout << "Mathematic: " << math << endl;
	cout << "Chemical: " << chem << endl;
	cout << "Physical: " << phys << endl;
	saveS(filename);
}

void Student::saveS(string filename) {
	fstream file;
	file.open(filename, ios::out|ios::app);
	file << schoolid << id << name << address << gender << math << chem << phys << endl;
	file.close();

}

Student::~Student() {
	cout << "Delete success! \n";
}