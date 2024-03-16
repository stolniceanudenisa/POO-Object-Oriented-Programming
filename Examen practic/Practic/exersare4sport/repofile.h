#pragma once

#include <fstream>
#include "meci.h"
#include "validator.h"
#include <vector>

class Repofile {
private:
	string filename;
	vector<Meci>meciuri;
	Validator validator;

	void load_from_file();
	void save_to_file();

public:

	Repofile(string filename, Validator validator);
	~Repofile();
	vector<Meci> get_all();
	void addmeci(Meci m);
	void deletemeci(Meci m);
	void updatemeci(Meci m);

	int find(string numeechipa1);
	int find_meci(Meci meci);
};