#include <Windows.h>
#include <exception>
#include <iostream>
#include "SmartPointer.h"
#include "SmartPointerTemplate.h"
#include <vector>
#include <string>

using namespace std;

void fp() {
	throw std::exception{ "Oops! An exception has occured!\n" };
}

void dumbPointer()
{
	int* a = nullptr;
	try
	{
		a = new int{ 2 };
		fp();
		delete a;
	}
	catch (std::exception& e)
	{
		delete a;
		cout << e.what();
	}
	
}

void testSmartPointer()
{
	try
	{
		int* x = new int{ 3 };
		SmartPointer a{ x };
		
		throw std::exception{ "Oops! An exception has occured, but all the resources were properly managed :) \n" };
		// no need to delete + no more leaks
	}
	catch (std::exception& e)
	{
		cout << e.what();
	}
}

void f()
{
	SmartPointer p{ new int{16} };
	cout << "The value of the integer stored in SmartPointer is "<< *p <<'\n';
	SmartPointer p2{};
	cout << "The value of the integer stored in SmartPointer p2 is " << *p2 << '\n';

}

void testSmartPointerTemplate()
{
	try
	{
		SmartPointerTemplate<int> a{ new int{3} };
		cout << "Created an int with value: " << *a << endl;

		SmartPointerTemplate<string> str{ new string{"Hello, you brilliant students!"} };
		cout << "Created a string with value: " << *str << endl;

		SmartPointerTemplate<vector<double>> v{ new vector<double>{ 2.5, 6.1, -5.3, 10 } };
		cout << "Created a vector, values: " << v->at(0) << ", " << v->at(1) << ", " << v->at(2) << ", " << v->at(3) << endl;

		throw std::exception{ "Oops! An exception has occured, but all the resources were properly managed :) \n" };
		// no need to delete + no more leaks
	}
	catch (std::exception& e)
	{
		cout << e.what();
	}
}

int main()
{
	//dumbPointer();
	testSmartPointer();
	
	
	//testSmartPointerTemplate();
	_CrtDumpMemoryLeaks();

	
	//f();
	system("pause");

	return 0;
}