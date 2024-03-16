#include "rochie.h"

/// <summary>
/// Constructor implicit
/// </summary>
Rochie::Rochie()
{
	this->id = 0;
	this->denumire = "";
	this->marime = "";
	this->culoare = "";
	this->nr_disponibile = 0;
	this->pret = 0;
	this->personalizare = "";
}

/// <summary>
///	constructor cu parametrii
/// </summary>
/// <param name="id"></param> id-ul rochiei
/// <param name="denumire"></param> denumirea rochiei
/// <param name="marime"></param> marimea rochiei
/// <param name="culoare"></param> culoarea rochiei
/// <param name="nr_disponibile"></param> numarul de rochii disponibile
/// <param name="pret"></param> pretul rochiei
/// <param name="personalizare"></param> personalizarea rochiei
Rochie::Rochie(int id, string denumire, string marime, string culoare, int nr_disponibile, int pret, string personalizare)
{
	this->id = id;
	this->denumire = denumire;
	this->marime = marime;
	this->culoare = culoare;
	this->nr_disponibile = nr_disponibile;
	this->pret = pret;
	this->personalizare = personalizare;
}

/// <summary>
/// Constructor de copiere
/// </summary> 
/// <param name="r"></param>
Rochie::Rochie(const Rochie& r)
{
	this->id = r.id;
	this->denumire = r.denumire;
	this->marime = r.marime;
	this->culoare = r.culoare;
	this->nr_disponibile = r.nr_disponibile;
	this->pret = r.pret;
	this->personalizare = r.personalizare;
}

/// <summary>
/// Destructor
/// </summary>
Rochie::~Rochie()
{
}

/// <summary>
/// Getter pentru id
/// </summary>
/// <returns></returns> id-ul rochiei
int Rochie::get_id()
{
	return this->id;
}

/// <summary>
/// Getter pentru denumire
/// </summary>
/// <returns></returns> denumirea rochiei
string Rochie::get_denumire()
{
	return this->denumire;
}


/// <summary>
/// Getter pentru marime
/// </summary>
/// <returns></returns> marimea rochiei
string Rochie::get_marime()
{
	return this->marime;
}

/// <summary>
/// Getter pentru culoare
/// </summary>
/// <returns></returns> culoarea rochiei
string Rochie::get_culoare()
{
	return this->culoare;
}

/// <summary>
///	getter pentru numarul de rochii disponibile
/// </summary>
/// <returns></returns> numarul de rochii disponibile
int Rochie::get_nr_disponibile()  
{
	return this->nr_disponibile;
}

/// <summary>
/// Getter pentru pret
/// </summary>
/// <returns></returns> pretul rochiei

int Rochie::get_pret()
{
	return this->pret;
}

/// <summary>
/// Getter pentru personalizare
/// </summary>
/// <returns></returns> personalizarea  
string Rochie::get_personalizare()
{
	return this->personalizare;
}


/// <summary>
/// setter pentru nr_disponibile
/// </summary>
/// <param name="nr_disponibile"></param> numarul de rochii disponibile
void Rochie::set_nr_disponibile(int nr_disponibile)
{
	this->nr_disponibile = nr_disponibile;
}

/// <summary>
/// Setter pentru id
/// </summary>
/// <param name="personalizare"></param> personalizarea rochiei
void Rochie::set_personalizare(string personalizare)
{
	this->personalizare = personalizare;
}

/// <summary>
/// Operator de egalitate
/// </summary>
/// <param name="r"></param> rochia cu care se compara
/// <returns></returns>
bool Rochie::operator==(const Rochie& r)
{
	return this->id == r.id && this->denumire == r.denumire && this->marime == r.marime && this->culoare == r.culoare && this->nr_disponibile == r.nr_disponibile && this->pret == r.pret && this->personalizare == r.personalizare;
}
