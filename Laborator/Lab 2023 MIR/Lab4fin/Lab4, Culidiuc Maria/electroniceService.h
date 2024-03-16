#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "Lista.h"

/*
* Adauga un electronic
*/
int adaugaTranzactie(Lista* v, Lista* lista_undo, int ziua, int suma, char* tip, char* descriere);

/*
Sterge un electronic in magazin
*/
int stergeTranzactie(Lista* v, Lista* lista_undo, int ziua, int suma);

/*
* Modifica un pret al unui electronic in magazin
*/
int modificaTranzactie(Lista* v, Lista* lista_undo, int ziua, int suma, char* tip, char* descriere);


/*
* Gaseste un electronic dupa id-ul sau
*/
int findTranzactie(Lista* v, char* tip);
//
///*
//* Filtreaza lista de Tranzactie dupa un producator dat
//*/
//Lista* filterTranzactie(Lista* v, char* producator);
//
///*
//* Filtreaza lista de Tranzactie dupa un tip de Tranzactie dat
//*/
//Lista* new_filter(Lista* v, char* tip);

// Face undo la ultima operatie efectuata
int undo(Lista* v, Lista* lista_undo);

void testAddService();
void testModifyService();
void testDeleteService();
void testFindService();
void testFilterService();
void testUndo();
