#pragma once
#include "Student.h"
#include <vector>

using namespace std;

class Repo {
private:
	vector<Student> studenti;
	char* fileName;
public:
	Repo();
	Repo(const char* fileName);
	~Repo();
	vector<Student> getAll();
	int getLength();

	void addElem(const Student& st);
	void updateElem(const Student& oldSt, const Student& newSt);
	void deleteElem(const Student& st);
private:
	void loadFromFile();
	void saveToFile();
};