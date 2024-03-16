#pragma once

#include "profesor.h"
#include "validator.h"
#include <vector>
#include <fstream>

class RepoFile {
private:
	vector<Profesor> profesori;
	string filename;
	Validator validator;
	void loadfromfile();
	void savetofile();
public:
	RepoFile(string filename, Validator validator);
	~RepoFile();
	vector<Profesor> getAll();
	void addProfesor(Profesor p);
	int find(string nume);
	int findProfesor(Profesor p);
};