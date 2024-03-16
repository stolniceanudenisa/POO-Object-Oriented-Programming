#pragma once
// RAII
class SmartPointer
{
public:
	SmartPointer(int val = 0);
	SmartPointer(int* ptr);
	SmartPointer(const SmartPointer& ptr) = delete;
	~SmartPointer();

	// overload dereferencing operator
	int& operator*();

private:
	int* m_resource;
};

