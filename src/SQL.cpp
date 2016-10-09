/*
	before using, run these query on your SQL server
		Create Table Student
		(
		 ID int primary key not null,
		 Name varchar(20),
		 Gender bit,
		 Math float,
		 Physic float,
		 Chemsistry float,
		 Total float,
		 SchoolID int
		)	
	*/

#using <mscorlib.dll>
#using <System.dll>
#using <System.Data.dll>
#using <System.Xml.dll>
#include <iostream>
#include "Student.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

ref class SQL {
	SqlConnection ^cn = gcnew SqlConnection();
	// SqlDataAdapter: truy vấn dữ liệu
	SqlDataAdapter ^da;
	//Student student;
	void CreateConnection() // mở kết nối tới CSDL
	{
		// remember to create table before :v also remember to edit server name, base on every machine
		// if a specific username and password is installed, use this
			// cn->ConnectionString = "Server=Apollo;Database=Student;UID=login;PWD=password;";
		// else this, simple solution for lazy one who only knows to click next and next :v

		cn->ConnectionString = "Server=Apollo;Database=Student;Integrated Security = SSPI";
		cn->Open();

	}

	void GetDataFromDB()
	{
		da = gcnew SqlDataAdapter("select * from Student order by ID", cn);
	}

	void InsertDataToDB()
	{
		// sorry dude, i forgot how to insert data to table :'(
		//da = gcnew SqlDataAdapter("insert into Student value('" + id + "'" +, cn);
	}
	void CloseConnection()
	{
		// Đóng kết nối tới SQL
		cn->Close();
	}
};