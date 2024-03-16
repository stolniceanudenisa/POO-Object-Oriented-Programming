#pragma once
#include <iostream>

using namespace std;

template <typename T>
class SmartPointerTemplate
{

public:
	SmartPointerTemplate(T* ptr);
	~SmartPointerTemplate();

	// overload pointer operators
	T& operator*();
	T* operator->();

private:
	T* m_resource;

	// other necesary functions!
};

template <typename T>
SmartPointerTemplate<T>::SmartPointerTemplate(T* ptr) : m_resource{ ptr }
{
	cout << "Resource was acquired.\n";
}

template <typename T>
SmartPointerTemplate<T>::~SmartPointerTemplate()
{
	delete this->m_resource;
	this->m_resource = nullptr;
	cout << "Resource was deallocated.\n";
}

template <typename T>
T& SmartPointerTemplate<T>::operator*()
{
	return *this->m_resource;
}

template <typename T>
T* SmartPointerTemplate<T>::operator->()
{
	return this->m_resource;
}