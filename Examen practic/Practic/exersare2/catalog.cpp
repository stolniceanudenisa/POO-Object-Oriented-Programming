#include "catalog.h"

Catalog::Catalog()
{
	this->nota = 0;
	this->nume_elev = "";
	this->nume_materie = "";
	this->data = "";
}

Catalog::Catalog(int nota, string nume_elev, string nume_materie, string data)
{
	this->nota = nota;
	this->nume_elev = nume_elev;
	this->nume_materie = nume_materie;
	this->data = data;
}

int Catalog::get_nota()
{
	return this->nota;
}

string Catalog::get_nume_elev()
{
	return this->nume_elev;
}

string Catalog::get_nume_materie()
{
	return this->nume_materie;
}

string Catalog::get_data()
{
	return this->data;
}

Catalog::Catalog(const Catalog& c)
{
	this->nota = c.nota;
	this->nume_elev = c.nume_elev;
	this->nume_materie = c.nume_materie;
	this->data = c.data;
}

Catalog::~Catalog()
{
}


Catalog& Catalog::operator==(const Catalog& c)
{
	if (this == &c)
		return *this;
	this->nota = c.nota;
	this->nume_elev = c.nume_elev;
	this->nume_materie = c.nume_materie;
	this->data = c.data;
	return *this;
}

//bool Catalog::operator==(const Catalog& c) {
//	return this->nota == c.nota && this->nume_elev == c.nume_elev && this->nume_materie == c.nume_materie && this->data == c.data;
//}


ostream& operator<<(ostream& os, const Catalog& c)
{
	os << "Nota: " << c.nota << " | Nume elev: " << c.nume_elev << " | Materie: " << c.nume_materie << " | Data: " << c.data;
	return os;
}
