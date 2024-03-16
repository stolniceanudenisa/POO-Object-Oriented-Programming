#include "Student.h"
#include <stdlib.h>

// Student s1;
// Student s1 = Student();
Student::Student()
{
	this->nume = new char[1];
	strcpy_s(this->nume, 1, ""); 
	this->varsta = 0;
}

//Student s1("ana", 20);
//Student s2 = Student("ana", 20);
Student::Student(const char* nume, int varsta)
{
	if (nume == NULL)
	{
		this->nume = NULL;
	}
	else
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	this->varsta = varsta;
}

//Student st = ..;
//Student st2 = Student(st);
//Student st3 = st2;
// 
//void foo(Student st) {}
//
//Student foo2() {}

Student::Student(const Student& st)
{
	if (st.nume == NULL)
	{
		this->nume = NULL;
	}
	else
	{
		this->nume = new char[strlen(st.nume) + 1];
		strcpy_s(this->nume, strlen(st.nume) + 1, st.nume);
	}
	this->varsta = st.varsta;
}

Student::~Student()
{
	if (this->nume)
	{
		delete[] this->nume;
	}
}

char* Student::getNume()
{
	return this->nume;
}

int Student::getVarsta()
{
	return this->varsta;
}

void Student::setNume(const char* nume)
{
	if (nume == NULL)
	{
		this->nume = NULL;
	}
	else
	{
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
}

void Student::setVarsta(int varsta)
{
	this->varsta = varsta;
}

//Student s1;
//Student s2;
//s2 = s1;
Student& Student::operator=(const Student& st)
{
	if (this != &st)
	{
		this->setNume(st.nume);
		this->setVarsta(st.varsta);
	}
	return *this;
}

bool Student::operator==(const Student& st)
{
	return strcmp(this->nume, st.nume) == 0 && this->varsta == st.varsta;
}

//Student st;
//cout << st;

ostream& operator<<(ostream& os, const Student& st)
{
	if (st.nume == NULL)
	{
		os << "NULL ";
	}
	else
	{
		os << st.nume << " ";
	}
	os << st.varsta;
	return os;
}
