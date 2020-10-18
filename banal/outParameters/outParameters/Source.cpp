#include "Header.h"

void methodPointer(MyClass* arg);
void methodRefference(MyClass& arg);

int main(int argc, char** argv)
{
	MyClass val;

	val.fieldDouble = rand() / 100.00;
	val.fieldInt = rand();
	strcpy(val.fieldWord, "");

	MyClass* pom1 = &val;
	MyClass& pom2 = val;

	methodPointer(pom1);
	std::cout << val;
	std::cout << *pom1;
	methodRefference(pom2);

	std::cout << val;
	std::cout << *pom1;
	std::cout << pom2;

	char a[10];
	std::cin >> *a;
	return 0;
}

void methodPointer(MyClass* arg)
{
	/*
	arg = new MyClass() // važi do kraja bloka
	*/
	*arg = *new MyClass();
}

void methodRefference(MyClass& arg)
{
	arg = *new MyClass();
	arg.fieldDouble = -258;
}
