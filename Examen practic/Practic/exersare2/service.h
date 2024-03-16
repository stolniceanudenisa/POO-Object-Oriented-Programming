#pragma once
#include "repofile.h"
class Service {

private:
	RepoFile& repo;
public:
	Service(RepoFile& repo);
	~Service();

	vector<Catalog*> get_all();
	void adds(int nota, string nume, string materie, string data);
	vector<Catalog*>filter_interval(string ziuai, string ziuaf);

};