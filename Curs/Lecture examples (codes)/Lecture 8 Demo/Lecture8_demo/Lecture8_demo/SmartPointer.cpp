#include "SmartPointer.h"
#include <iostream>

using namespace std;

SmartPointer::SmartPointer(int val) {
	m_resource = new int{val};
	cout << "Resource was allocated.\n";
}
SmartPointer::SmartPointer(int* ptr): m_resource(ptr)
{
	cout << "Resource was acquired.\n";
}

SmartPointer::~SmartPointer()
{
	delete this->m_resource;
	m_resource = nullptr;
	cout << "Resource was deallocated.\n";
}

int& SmartPointer::operator*()
{
	return *this->m_resource;
}
