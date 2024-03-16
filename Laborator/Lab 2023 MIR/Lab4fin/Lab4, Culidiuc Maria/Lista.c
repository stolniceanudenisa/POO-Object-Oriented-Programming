#pragma once
#include "Lista.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

Lista* createEmpty() 
{
	Lista* v = malloc(sizeof(Lista));
	v->capacitate = 2;
	v->lungime = 0;
	v->elems = malloc(sizeof(ElemType) * v->capacitate);
	return v;
}

void destroy(Lista* v,DestroyFunction destroy_function) {
	for (int i = 0; i < v->lungime; i++) {
		ElemType el = getElem(v, i);
		destroy_function(el);
	}
	v->lungime = 0;
	free(v->elems);
	free(v);
}

void destroy_lista(Lista* v)
{
	destroy(v, distrugeTranzactie);
}

ElemType getElem(Lista* v, int poz) {
	return v->elems[poz];
}
ElemType setElem(Lista* v, int poz, ElemType el) {
	ElemType replacedElement = v->elems[poz];
	v->elems[poz] = el;
	return replacedElement;
}


int nrElem(Lista* v) {
	return v->lungime;
}

void adauga(Lista* v, ElemType el) {
	//pt. vector dinamic - se face resize
	if (v->lungime == v->capacitate) 
	{
		int newCapacitate = v->capacitate * 2;
		ElemType* aux_elems = malloc(sizeof(ElemType) * newCapacitate);
		for (int i = 0; i < v->lungime; i++) {
			aux_elems[i] = v->elems[i];
		}
		free(v->elems);
		v->elems = aux_elems;
		v->capacitate = newCapacitate;
	}

	v->elems[v->lungime] = el;
	v->lungime++;
}
ElemType sterge(Lista* v, int poz) {
	ElemType el = v->elems[poz];
	for (int i = poz; i < v->lungime - 1; i++) {
		v->elems[i] = v->elems[i + 1];
	}
	v->lungime--;
	return el;
}

Lista* copiazaLista(Lista* v) 
{
	Lista* v_copy = createEmpty();
	for (int i = 0; i < v->lungime; i++) {
		ElemType el = getElem(v, i);
		adauga(v_copy, copiazaElectronic(el));
	}
	return v_copy;
}


void testIterate() {
	Lista* v = createEmpty();
	Tranzactie* e1 = creeazaTranzactie(1, 1, "iesire", "aa");
	 
	
	Tranzactie* e2 = creeazaTranzactie(2, 2, "intrare", "bb");

	adauga(v, e1);
	adauga(v, e2);

	assert(nrElem(v) == 2);
	Tranzactie* e = getElem(v, 0);

	assert(e->suma == 1);
	assert(e->ziua == 1);
	assert(strcmp(e->descriere, "aa") == 0);
	assert(strcmp(e->tip, "iesire") == 0);

	destroy(v,distrugeTranzactie);

}

void testCopy() {
	Lista* v1 = createEmpty();
	adauga(v1, creeazaTranzactie(1, 1, "iesire", "aa"));
	adauga(v1, creeazaTranzactie(2, 2, "intrare", "bb"));

	assert(nrElem(v1) == 2);
	Lista* v2 = copiazaLista(v1);
	assert(nrElem(v2) == 2);

	destroy(v1, distrugeTranzactie);
	destroy(v2, distrugeTranzactie);

}

void liste_de_liste()
{
	Lista* Tranzactie = createEmpty();
	adauga(Tranzactie, creeazaTranzactie(3, 3, "iesire", "aa"));
	adauga(Tranzactie, creeazaTranzactie(4, 4, "intrare", "bb"));

	Lista* Tranzactie2 = createEmpty();
	Lista* undo_list = createEmpty();
	adauga(undo_list, Tranzactie);
	assert(nrElem(undo_list) == 1);
	adauga(undo_list, Tranzactie2);
	assert(nrElem(undo_list) == 2);
	destroy(undo_list, destroy_lista);
}