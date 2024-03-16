#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Profesor {
private:
	string nume;
	string disciplina;
	string clase;
	string greva;
public:
	Profesor();
	Profesor(string nume, string disciplina, string clase, string greva);
	Profesor(const Profesor& p);
	~Profesor();
	string getNume();
	string getDisciplina();
	string getClase();
	string getGreva();
	bool operator==(const Profesor& p);

	string toString()  const
	{
		stringstream ss;
		ss << "Nume: " << this->nume << " " << " | Disciplina: " << this->disciplina << " " << " | Clasa: " << this->clase << " " << " | Greva: " << this->greva;
		return ss.str();
	}

	
};