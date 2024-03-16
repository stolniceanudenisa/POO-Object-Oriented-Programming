#pragma once
#include "repofile.h"
class Service {

private:
	Repofile& repofile;
public:
	Service(Repofile& repofile);
	
	vector<Meci> get_all();


	void addmecis(string numeechipa1, string numeechipa2, int scor1, int scor2);
	void deletemecis(string numeechipa1);

	void updatemecis(string numeechipa1, string numeechipa2, int scor1, int scor2);
			

	vector<Meci> sortare_scor1();
	vector<Meci> clasament2();
};