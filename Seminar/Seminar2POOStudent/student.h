#pragma once

class Student
{
private:
	int pin;
	char* name;
	int age;
public:
	Student();
	Student(const char* n, int age);
	Student(const Student& st);
	~Student();

	int get_pin();
	char* get_name();
	int get_age();

	void set_pin(int new_pin);
	void set_name(char* new_name);
	void set_age(int new_age);

	Student& operator=(const Student& st);

	bool operator==(const Student& st);
	Student& operator++(int);

	//friend istream& operator>>(istream& is, Student& r);
	//friend ostream& operator<<(ostream& os, Student& r);
};