#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

typedef struct {
	int ziua;
	int suma;
	char* tip;
	char* descriere;
} Tranzactie;

/*
Creeaza un nou electronic
*/

Tranzactie* creazaTranzactie(int ziua, int suma, char* tip, char* descriere);

/*
* Distruge electronic
*/
void distrugeTranzactie(Tranzactie* e);

int valideazaTranzactie(Tranzactie e);

/*
* Creeaza o copie a electronicului dat (similar cu Python "deepcopy")
*/
Tranzactie* copiazaTranzactie(Tranzactie* e);

void testCreateDestroy();
void testValideaza();
