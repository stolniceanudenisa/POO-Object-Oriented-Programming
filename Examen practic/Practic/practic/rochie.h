#pragma once
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Rochie {
private:
	int id;
	string denumire;
	string marime;
	string culoare;
	int nr_disponibile;
	int pret;
	string personalizare;
public:
	Rochie();
	Rochie(int id, string denumire, string marime, string culoare, int nr_disponibile, int pret, string personalizare);
	Rochie(const Rochie& r);
	~Rochie();
	int get_id();
	string get_denumire();
	string get_marime();
	string get_culoare();
	int get_nr_disponibile();
	int get_pret();
	string get_personalizare();
	//void set_id(int id);
	//void set_denumire(string denumire);
	//void set_marime(string marime);
	//void set_culoare(string culoare);
	void set_nr_disponibile(int nr_disponibile);
	//void set_pret(int pret);
	void set_personalizare(string personalizare);
	 
	bool operator==(const Rochie& r);
 

	string toString()  const
	{
		stringstream ss;
		ss << "Id: " << this->id << " " << " | Denumire: " << this->denumire << " " << " | Marime: " << this->marime << " " << " | Culoare: " << this->culoare << " | Nr disponibil: " << this->nr_disponibile << " | pret: " << this->pret << " | personalizare: " << this->personalizare;
		return ss.str();
	}

};