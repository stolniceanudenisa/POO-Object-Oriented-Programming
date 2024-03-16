#pragma once
#include "electronice.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Tranzactie* creazaTranzactie(int ziua, int suma, char* tip, char* descriere)
{
	Tranzactie* e = malloc(sizeof(Tranzactie));
	 
	int nrC = (int)strlen(tip) + 1;
	e->tip = malloc(nrC * sizeof(char));
	strcpy_s(e->tip, nrC, tip);

	nrC = (int)strlen(descriere) + 1;
	e->descriere = malloc(nrC * sizeof(char));
	strcpy_s(e->descriere, nrC, descriere);


	e->ziua = ziua;
	e->suma = suma;
	return e;
}

void distrugeTranzactie(Tranzactie* e)
{
	 
	free(e->tip);
	free(e->descriere);
	free(e);
}

Tranzactie* copiazaTranzactie(Tranzactie* e)
{
	return creeazaElectronic(e->ziua, e->suma, e->tip, e->descriere);
}

int valideazaTranzactie(Tranzactie e)
{
	if (e.ziua < 0)
		return 0;
	if (e.suma < 0)
		return 0;

	if (strlen(e.tip) == 0)
		return 0;

	if (strlen(e.descriere) == 0)
		return 0;

	return 1;
}

void testCreateDestroy() {
	Tranzactie* e = creeazaTranzactie(1,1,"iesire","aa");
	 
	assert(strcmp(e->tip, "iesire") == 0);
	assert(strcmp(e->descriere, "aa") == 0);

	assert(e->ziua == 3500.0);
	assert(e->suma == 4);

	distrugeTranzactie(e);

}

void testValideaza()
{
	Tranzactie* e_corect = creeazaTranzactie(1, 1, "iesire", "aa");
	assert(valideazaTranzactie(*e_corect) == 1);

	Tranzactie* e_gresit1 = creeazaElectronic(-1, -1, "iesire", "aa");
	Tranzactie* e_gresit2 = creeazaElectronic("", "", "iesire", "aa");

	assert(valideazaElectronic(*e_gresit1) == 0);
	assert(valideazaElectronic(*e_gresit2) == 0);
	

	distrugeElectronic(e_corect);
	distrugeElectronic(e_gresit1);
	distrugeElectronic(e_gresit2);

}