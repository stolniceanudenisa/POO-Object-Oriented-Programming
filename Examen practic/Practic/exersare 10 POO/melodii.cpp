#include "melodii.h"

/// <summary>
/// Constructor fara parametrii
/// </summary> creaza o melodie cu toate campurile goale
Melodie::Melodie()
{
	this->denumire = "";
	this->cantaret = "";
	this->gen = "";
	this->durata = 0;

}

/// <summary>
/// Constructor cu parametrii
/// </summary>creeaza o melodie cu parametrii dati
/// <param name="denumire"></param> denumirea melodiei
/// <param name="cantaret"></param>cantaretul melodiei
/// <param name="gen"></param>genul melodiei
/// <param name="durata"></param>durata melodiei
Melodie::Melodie(string denumire, string cantaret, string gen, int durata)
{
	this->denumire = denumire;
	this->cantaret = cantaret;
	this->gen = gen;
	this->durata = durata;
}

/// <summary>
/// Copy constructor
/// </summary>creeaza o melodie cu parametrii unei alte melodii
/// <param name="m"></param> copiaza melodia m
Melodie::Melodie(const Melodie&m)
{
	this->denumire = m.denumire;
	this->cantaret = m.cantaret;
	this->gen = m.gen;
	this->durata = m.durata;
}

/// <summary>
/// Destructor
/// </summary>
Melodie::~Melodie()
{
}

/// <summary>
/// Getter pentru cantaret
/// </summary>
/// <returns></returns>	cantaret
string Melodie::getCantaret()
{
	return this->cantaret;
}

/// <summary>
/// Getter pentru gen
/// </summary>	
/// <returns></returns> gen
string Melodie::getGen()
{
	return this->gen;
}

/// <summary>
/// Getter pentru denumire
/// </summary>
/// <returns></returns>	denumire
string Melodie::getDenumire()
{
	return this->denumire;
}

/// <summary>
/// Getter pentru durata
/// </summary> 
/// <returns></returns> durata
int Melodie::getDurata()
{
	return this->durata;
}

void Melodie::setCantaret(string cantaret)
{
	this->cantaret = cantaret;
}

void Melodie::setGen(string gen)
{
	this->gen = gen;
}

void Melodie::setDenumire(string denumire)
{
	this->denumire = denumire;
}

void Melodie::setDurata(int durata)
{
	this->durata = durata;
}

/// <summary>
/// Operatorul egal
/// </summary>
/// <param name="m"></param> melodia cu care comparam
/// <returns></returns> true daca sunt egale, false altfel
bool Melodie::operator==(const Melodie&m)
{
	return this->denumire == m.denumire && this->cantaret == m.cantaret && 
		this->gen == m.gen && this->durata == m.durata;
}

 
