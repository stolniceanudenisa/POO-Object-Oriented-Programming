#include "profesor.h"

/// <summary>
/// Constructorul fara parametrii
/// </summary>
Profesor::Profesor()
{
	this->nume="";
	this->disciplina="";
	this->clase="";
	this->greva="";

}

/// <summary>
/// Constructor cu parametrii
/// </summary>
/// <param name="nume"></param> Stringul nume
/// <param name="disciplina"></param> Stringul disciplina
/// <param name="clase"></param> Stringul clase
/// <param name="greva"></param> Stringul greva
Profesor::Profesor(string nume, string disciplina, string clase, string greva)
{
	this->nume = nume;
	this->disciplina = disciplina;
	this->clase = clase;
	this->greva = greva;

}

/// <summary>
/// copy constructor
/// </summary> In p avem profesorul pe care il copiem
/// <param name="p"></param> 
Profesor::Profesor(const Profesor& p)
{
	this->nume = p.nume;
	this->disciplina = p.disciplina;
	this->clase = p.clase;
	this->greva = p.greva;
}

/// <summary>
/// Destructorul
/// </summary>
Profesor::~Profesor()
{
}

/// <summary>
///	Geter pentru nume
/// </summary>
/// <returns></returns> Stringul nume
string Profesor::getNume()
{
	return this->nume;
}

/// <summary>
/// Geter pentru disciplina
/// </summary> 
/// <returns></returns> Stringul disciplina
string Profesor::getDisciplina()
{
	return this->disciplina;
}

/// <summary>
///	Geter pentru clase
/// </summary>
/// <returns></returns> Stringul clase
string Profesor::getClase()
{
	return this->clase;
}

/// <summary>
///Getter pentru greva
/// </summary>	
/// <returns></returns> Stringul greva			
string Profesor::getGreva()
{
	return this->greva;
}

/// <summary>
/// Operatorul de egalitate
/// </summary>
/// <param name="p"></param> Profesorul cu care comparam
/// <returns></returns> True daca sunt egale, false altfel
bool Profesor::operator==(const Profesor& p)
{
	return (this->nume == p.nume) && (this->disciplina == p.disciplina) && (this->clase == p.clase) && (this->greva == p.greva);
}
