#pragma once

#include <string>
#include <iostream>
#include <sstream>
using namespace std;


class Catalog {

private:
	int nota;
	string nume_elev;
	string nume_materie;
	string data;
public:
	Catalog();
	Catalog(int nota, string nume_elev, string nume_materie, string data);

	int get_nota();
	string get_nume_elev();
	string get_nume_materie();
	string get_data();

	Catalog(const Catalog& c);
	~Catalog();

	Catalog& operator == (const Catalog& c);
	//bool operator==(const Catalog& c);

	friend ostream& operator <<(ostream& os, const Catalog& c);

	string to_string() const
	{
		stringstream ss;
		ss << "Nota: " << this->nota << " | Nume elev: " << this->nume_elev << " | Materie: " << this->nume_materie << " | Data: " << this->data;
		return ss.str();
	}


};