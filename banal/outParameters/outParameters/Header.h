#include<iostream>
#include <string.h>

#pragma once

class MyClass
{
public:
	MyClass();
	~MyClass();

	int fieldInt;
	char* fieldWord;
	double fieldDouble;

	friend std::ostream& operator<<(std::ostream& os, const MyClass& arg);
};

MyClass::MyClass()
{
	fieldInt = 0;
	fieldWord = new char[strlen("First")];
	strcpy(fieldWord, "First");
	fieldDouble = 0;
}

MyClass::~MyClass()
{
	delete[] fieldWord;
	fieldWord = 0;
}

std::ostream& operator<<(std::ostream& os, const MyClass& arg)
{
	os << "Integer: " << arg.fieldInt << "; \t Double: " << arg.fieldDouble << "; \t Word: " << arg.fieldWord << "\n";
	return os;
}