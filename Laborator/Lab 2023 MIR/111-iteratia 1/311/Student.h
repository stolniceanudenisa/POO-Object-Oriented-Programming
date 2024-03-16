#pragma once
#include <ostream>

using namespace std;

class Student {
private:
	char* nume;
	int varsta;
public:
	Student();
	Student(const char* nume, int varsta);
	Student(const Student& st);
	~Student();

	char* getNume();
	int getVarsta();
	void setNume(const char* nume);
	void setVarsta(int varsta);

	Student& operator=(const Student& st);
	bool operator==(const Student& st);
	friend ostream& operator<<(ostream& os, const Student& st);
};