#pragma once

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
 
class Meci {

private:
	string numeechipa1, numeechipa2;
	int scor1, scor2;
public:
	Meci();
	Meci(string numeechipa1, string numeechipa2, int scor1, int scor2);
	Meci(const Meci& m);


	int get_scor1();
	int get_scor2();
	string get_echipa1();
	string get_echipa2();

	string to_string() const
	{
		stringstream ss;
		ss << "Nume echipa 1: " << this->numeechipa1 << " | Nume echipa 2: " << this->numeechipa2 << " | Scor echipa1: " << this->scor1 << " | Scor echipa 2: " << this->scor2;
		return ss.str();
	}

	bool operator == (const Meci& m);
};
