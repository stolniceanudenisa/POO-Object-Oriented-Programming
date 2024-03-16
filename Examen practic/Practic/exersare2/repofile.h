#pragma once
#include "catalog.h"
#include <vector>
class RepoFile {

private:
	vector<Catalog*> cataloage;

	string filename;
	void loadfromfile();
	void savetofile();
public:
	RepoFile(string filename);
	~RepoFile();

	int size();
	vector<Catalog*> get_all();
	Catalog* get_at(int pos);

	Catalog* find(string nume_elev);



	void addc(Catalog* c);
	void updatec(Catalog* cvechi, Catalog* cnou);
	void deletec(Catalog* c);
};