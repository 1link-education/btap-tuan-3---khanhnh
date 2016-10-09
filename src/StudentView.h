#pragma once
#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H


#include "StudentController.h"
#include<iostream>
#include<string>
class View
	//Student View
{
public:
	StudentController a;
	
	string getSchoolName(); // nhập tên trường

	int getid();

	void modifyMenu(); // tùy chọn sửa đổi sinh viên

	void searchMenu(); // tùy chọn tìm kiếm sinh viên

	void sortMenu(int); // tùy chọn sắp xếp sinh viên
	
	int mainMenu(); // tùy chọn các chức năng
};

#endif // !STUDENTVIEW_H
