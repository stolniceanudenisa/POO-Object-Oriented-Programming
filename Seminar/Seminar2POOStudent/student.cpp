#include "student.h"
#include <iostream>
#include <cstring>
using namespace std;



// Constructor
// In: -
// Out: an empty object of type Student
int pin_unic = 0;
Student::Student()
{
	pin_unic++;
	this->pin = pin_unic;
	this->name = NULL;
	this->age = 0;
}


// Constructor with parameters
// In: a name (string) and an age (integer)
// Out: an object of type Student that contains the given info
Student::Student(const char* n, int age)
{
	this->pin = pin_unic;
	this->name = new char[strlen(n) + 1];
	strcpy_s(this->name, strlen(n) + 1, n);
	this->age = age;
}

// Copy constructor
// In: an object s of type Student
// Out: another object of type Student that contains the same info as s
Student::Student(const Student& st)
{
	this->pin = st.pin;
	this->name = new char[strlen(st.name) + 1];
	strcpy_s(this->name, strlen(st.name) + 1, st.name);
	this->age = st.age;
}


// Destructor
// In: an object of type Student
// Out: -
Student::~Student()
{
	if (this->name != NULL)
	{
		delete[] this->name;
		this->name = NULL;
	}
	//cout << "Nume sters.\n";
}

// getter
// In: an object of type Student
// Out: pin of the student
int Student::get_pin()
{
	return this->pin;
}

// getter
// In: an object of type Student
// Out: name of the student
char* Student::get_name()
{
	return this->name;
}

// getter
// In: an object of type Student
// Out: age of the student
int Student::get_age()
{
	return this->age;
}


void Student::set_pin(int new_pin)
{
	this->pin = new_pin;
}


// setter
// In: an object of type Student and a name (string)
// Out: the same object with a new name
void Student::set_name(char* new_name)
{
	if (this->name != NULL)
	{
		delete[] this->name;
	}
	this->name = new char[strlen(new_name) + 1];
	strcpy_s(this->name, strlen(new_name + 1), new_name);
}


// setter
// In: an object of type Student and an age (integer)
// Out: the same object with a new age
void Student::set_age(int new_age)
{
	this->age = new_age;
}


// assignment operator
// In: two objects of type Student (the current one, this, and s)
// Out: the new state of the current object (this)
Student& Student::operator=(const Student& st)
{
	this->set_pin(st.pin);
	this->set_name(st.name);
	this->set_age(st.age);
	return *this;
}


// comparator
// In: two objects of type Student (this and s)
// Out: true or false
bool Student::operator==(const Student& st) {
	return ((strcmp(this->name, st.name) == 0) && (this->age == st.age));
}

Student& Student::operator++(int n) {
	this->set_age(this->get_age() + 1);
	return *this;
}
//
////IO operators
////Descr: load a rational no from an input stream
////In: an input stream
////Out: a new Ratioanal number
//istream& operator>>(istream& is, Student& s) {
//	cout << "Citim studentul";
//	char* name = new char[10];
//	is >> name;
//	s.set_name(name);
//	is >> s.age;
//	cout << "Student citit: " << s.name << " " << s.age << endl;
//	return is;
//}
//
//
////IO operators
////Descr: save a rational no into an output stream
////In: an output stream, a Rational no
////Out: the output stream (loaded by info about Rational no)
//ostream& operator<<(ostream& os, Student& st) {
//	os << "Student: " << st.name << " " << st.age << endl;
//	return os;
//}