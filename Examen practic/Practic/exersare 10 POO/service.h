#pragma once

#include "repofile.h"

class Service {
private:
	RepoFile& repofile;
public:
	Service(RepoFile& repofile);
	vector<Melodie> getAll();

	void addmelodie(string denumire, string cantaret, string gen, int durata);
	void updatemelodie(string denumire, string cantaret, string gen, int durata);
	void deletemelodie(string denumire);
	void delete_between(int start, int end);
	void insertmelodie(string denumire, string cantaret, string gen, int durata, int pos);
	void update_anumit(string denumire, string cantaret, string gen, int durata);

	vector< Melodie>max_durata();

	vector<Melodie> cautare_melodie(string denumire);

	vector<Melodie> filtrare_gen(string gen);
	vector<Melodie> afisare_melodii_sub_4_minute();

	vector<Melodie> durata_min_max(int min, int max);
	vector<Melodie> sortare_durata();
	vector<Melodie> sortare_denumire(bool ascending);
 
	vector<Melodie> sortare_cantaret_denumire();

	vector<Melodie> numar_de_melodii_cantaret();


	vector<pair<string, string>> vizualizare_per_gen();
	void generare_random(int nr);
 
};