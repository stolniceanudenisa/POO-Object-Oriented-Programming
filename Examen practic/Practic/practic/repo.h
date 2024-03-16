#pragma once
#include <fstream>
#include <vector>
#include "rochie.h"
#include "validator.h"

class RepoFile {
protected:
	vector<Rochie> rochii;
	string filename;
	Validator validator;
	void loadfromfile();
	
public:
	RepoFile(string filename, Validator validator);
	~RepoFile();
	vector<Rochie> getAll();
	int find(int id);
	void savetofile();
};
