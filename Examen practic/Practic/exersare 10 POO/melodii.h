#pragma once
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class Melodie {
	string denumire;
	string cantaret;
	string gen;
	int durata;
public:
	Melodie();
	Melodie(string denumire, string cantaret, string gen, int durata);
	Melodie(const Melodie&m);
	~Melodie();
	string getCantaret();
	string getGen();
	string getDenumire();
	int getDurata();
	void setCantaret(string cantaret);
	void setGen(string gen);
	void setDenumire(string denumire);
	void setDurata(int durata);
	//Melodie& operator=(const Melodie&);
	bool operator==(const Melodie&m);
	//friend ostream& operator<<(ostream&, const Melodie&);
	//friend istream& operator>>(istream&, Melodie&);
	string toString()  const
	{
		stringstream ss;
		ss<< "Denumire: " << this->denumire<<" " << " | Cantaret: " <<this->cantaret<<" "<< " | Gen: "<<this->gen<<" " << " | Durata: " <<this->durata;
		return ss.str();
	}
};