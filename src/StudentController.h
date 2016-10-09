#pragma once
#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H
#include "Student.h"

class StudentController
{
public:
	string filename;

	int *n;

	int m;

	Student *st[]; // mảng sinh viên 

	void readfile(string); // đọc danh sách từ file

	void searchsum(int); // tìm kiếm theo tổng điểm

	void searchid(); // tìm kiếm theo sbd

	void searchname(); // tìm kiếm theo tên

	void searchmath(int); // tìm kiếm theo điểm toán

	void searchchem(int); // tìm kiếm theo điểm hóa

	void searchphys(int); // tìm kiếm theo điểm lý

	void modify(); // sửa thông tin sinh viên

	void del(); // xóa sinh viên

	void printList(); // in danh sách sinh viên

	void sortid(int*[]); // sắp xếp theo danh sách

	void sortal(string*[]); // sắp xếp theo alphabel

	void sortsum(float*[]); // sắp xếp theo tổng điểm


};

#endif // !STUDENTCONTROLLER_H


