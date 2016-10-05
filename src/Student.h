#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<string>

	using namespace std;

class Student
	//Student Management Model
{
public:
	int id;
	string name;
	string address;
	string gender;
	float math;
	float chem;
	float phys;
	float sum = math + chem + phys;
	int schoolid;
	string filename;

	void setS(int, string, string, string, float, float, float, int); // lưu sinh viên vào mảng sinh viên

	void getS(); // in thông tin sinh viên ra màn hình

	void saveS(string); // lưu thông tin sinh viên vào file

	~Student();
};
#endif // !STUDENT_H