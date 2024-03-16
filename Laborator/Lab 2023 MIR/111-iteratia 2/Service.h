#pragma once
#include "Repo.h"
class Service {
private:
	Repo& repo;
public:
	Service(Repo& repo);
	~Service();

	vector<Student> getAll();

	void addStudent(const char* nume, int varsta);
	void updateVarstaDupaNume(const char* nume, int varstaNoua);
	void deleteBetweenAges(int varstaMin, int varstaMax);
};