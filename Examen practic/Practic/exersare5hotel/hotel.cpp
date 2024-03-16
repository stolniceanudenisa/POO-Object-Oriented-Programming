#include "hotel.h"

/// <summary>
/// Constructor implicit
/// </summary>
Hotel::Hotel()
{
	this->camerasingle = 5;
	this->cameradubla = 7;
	this->apartament = 2;
	this->checkindate = 0;
	this->nrzile = 0;
}

/// <summary>
/// Constructor cu parametrii
/// </summary>
/// <param name="camerasingle"></param>
/// <param name="cameradubla"></param>
/// <param name="apartament"></param>
/// <param name="checkindate"></param>
/// <param name="nrzile"></param>
Hotel::Hotel(int camerasingle, int cameradubla, int apartament, int checkindate, int nrzile)
{
	this->camerasingle = camerasingle;
	this->cameradubla = cameradubla;
	this->apartament = apartament;
	this->checkindate = checkindate;
	this->nrzile = nrzile;

}

/// <summary>
/// Constructor de copiere
/// </summary>
/// <param name="h"></param>
Hotel::Hotel(const Hotel&h)
{
	this->camerasingle = h.camerasingle;
	this->cameradubla = h.cameradubla;
	this->apartament = h.apartament;
	this->checkindate = h.checkindate;
	this->nrzile = h.nrzile;
}


/// <summary>
/// Getter pentru numarul de zile
/// </summary>
/// <returns></returns>
int Hotel::getnrzile()
{
	return this->nrzile;
	 
}

/// <summary>
/// Setter pentru numarul de zile
/// </summary>
/// <param name="camerasingle"></param>
void Hotel::setcamerasingle(int camerasingle)
{
	this->camerasingle = camerasingle;

}

void Hotel::setcameradubla(int cameradubla)
{
	this->cameradubla = cameradubla;
}

void Hotel::setapartament(int apartament)
{
	this->apartament = apartament;
}

void Hotel::setcheckindate(int checkindate)
{
	this->checkindate = checkindate;
}

void Hotel::setnrzile(int nrzile)
{
	this->nrzile = nrzile;
}


int Hotel::getcamerasingle()
{
	return this->camerasingle;
}

int Hotel::getcameradubla()
{
	return this->cameradubla;
}

int Hotel::getapartament()
{
	return this->apartament;
}

int Hotel::getcheckindate()
{
	return this->checkindate;
}

 