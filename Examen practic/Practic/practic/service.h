#pragma once

#include "repo.h"

class Service {
private:
	RepoFile& repofile;
	Validator validator;
public:
	Service(RepoFile& repofile, Validator validator);
	vector<Rochie> getAll();
	void find_rochie(int id);



	vector<Rochie> afisare_rochii_marime(string marime, string personalizar);
	void find(int id);


	//cumparare rochie. Se va modifica cantitatea rochiei, se afiseaza rochia cu id-ul nu exista daca nu exista, sau "ne pare rau nu mai e in stoc" daca nu mai e in stoc
	vector<Rochie> cumparare_rochie(int id);
	void savetofileservice();

	
	//afisarea celor mai ieftine 3 rochii disponibile (True), daca nu exista se afiseaza mesaj
	vector<pair<string, string>> top_3_rochii_ieftine();
 

};