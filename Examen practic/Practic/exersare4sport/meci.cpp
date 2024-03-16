#include "meci.h"

Meci::Meci()
{
	this->numeechipa1 = "";
	this->numeechipa2 = "";
	this->scor1 = 0;
	this->scor2 = 0;

}

Meci::Meci(string numeechipa1, string numeechipa2, int scor1, int scor2)
{
	this->numeechipa1 = numeechipa1;
	this->numeechipa2 = numeechipa2;
	this->scor1 = scor1;
	this->scor2 = scor2;
}

Meci::Meci(const Meci& m)
{
	this->numeechipa1 = m.numeechipa1;
	this->numeechipa2 = m.numeechipa2;
	this->scor1 = m.scor1;
	this->scor2 = m.scor2;
}

int Meci::get_scor1()
{
	return this->scor1;
}

int Meci::get_scor2()
{
	return this->scor2;
}

string Meci::get_echipa1()
{
	return this->numeechipa1;
}

string Meci::get_echipa2()
{
	return this->numeechipa2;
}

bool Meci::operator==(const Meci& m)
{
	return this->numeechipa1 == m.numeechipa1 && this->numeechipa2 == m.numeechipa2 && this->scor1 == m.scor1 && this->scor2 == m.scor2;
}


