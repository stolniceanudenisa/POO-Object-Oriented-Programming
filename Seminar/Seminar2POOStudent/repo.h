#pragma once
#include "student.h"
using namespace std;


class Repo {
private:
	Student students[10];
	int noStudents;
public:
	Repo();
	~Repo();
	void addItem(Student& s);
	Student getItemFromPos(int pos);
	int getSize();
};