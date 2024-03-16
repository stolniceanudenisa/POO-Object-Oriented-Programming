#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "electronice.h"

typedef void* ElemType;
typedef void (*DestroyFunction)(ElemType);
typedef struct {
	ElemType* elems;
	int lungime;
	int capacitate;
} Lista;

/*
* Creeaza o lista goala
*/
Lista* createEmpty();

/*
* Distruge lista data si elementele sale
*/
void destroy(Lista* v, DestroyFunction destroy_function);

//Criteriul pentru functia destroy in cazul listelor de liste
void destroy_lista(Lista* v);

/*
* Returneaza elementul de pe pozitia poz din lista data
*/
ElemType getElem(Lista* v, int poz);

/*
* Pune elementul el pe pozitia poz din lista v
*/
ElemType setElem(Lista* v, int poz, ElemType el);

/*
* Returneaza numarul de elemente in lista
*/
int nrElem(Lista* v);

/*
* Adauga un element in lista
*/
void adauga(Lista* v, ElemType el);

/*
* Sterge un element din lista
*/
ElemType sterge(Lista* v, int poz);

/*
* Face o copie a listei date (similar cu Python deepcopy)
*/
Lista* copiazaLista(Lista* v);

void testCreate();
void testIterate();
void testCopy();
void liste_de_liste();

