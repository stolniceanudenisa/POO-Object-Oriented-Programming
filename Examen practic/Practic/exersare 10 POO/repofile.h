#pragma once
#include <fstream>
#include <vector>
#include "melodii.h"
#include "validator.h"

class RepoFile {
private:
		vector<Melodie> melodii;
		string filename;
		Validator validator;
		void loadfromfile();
		void savetofile();
public:
		RepoFile(string filename, Validator validator);
		~RepoFile();
		vector<Melodie> getAll();
		void addmelodie(Melodie m);
		void insertmelodie(Melodie m, int pos);
		void updatemelodie(Melodie m);
		void update_anumit(Melodie m);
		void deletemelodie(Melodie m);
		void delete_between(int start, int end);
		int find(string denumire);
		int find_melodie(Melodie melodie);
		  
};

 