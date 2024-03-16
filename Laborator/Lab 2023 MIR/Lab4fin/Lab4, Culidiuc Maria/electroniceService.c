#pragma once
#include "electroniceService.h"
#include "sortare.h"
#include <assert.h>
#include <string.h>

int adaugaTranzactie(Lista* v, Lista* lista_undo, int ziua, int suma, char* tip, char* descriere)
{
	Tranzactie* e = creeazaTranzactie(id, tip, producator, model, pret, cantitate);
	int successful = valideazaTranzactie(*e);
	if (!successful) {
		distrugeTranzactie(e);
		return 0;
	}
	adauga(lista_undo, copiazaLista(v));
	adauga(v, e);
	return 1;
}

int findElectronic(Lista* v, int id) 
{
	int poz_to_delete = -1;
	for (int i = 0; i < v->lungime; i++) 
	{
		Tranzactie* e = getElem(v, i);
		if (e->id == id) 
		{
			poz_to_delete = i;
			break;
		}
	}
	return poz_to_delete;
}

int stergeElectronic(Lista* v, Lista* lista_undo, int id)
{
	int poz_to_delete = findElectronic(v,id);
	if (poz_to_delete != -1) 
	{
		adauga(lista_undo, copiazaLista(v));
		Tranzactie* e = sterge(v, poz_to_delete);
		distrugeElectronic(e);
		return 1;}
	else
		return 0;
}

int modificaElectronic(Lista* v,Lista* lista_undo, int id, char* tip, char* producator, char* model, int cantitate, float pretNou)
{
	int poz_to_delete = findElectronic(v, id);

	if (poz_to_delete != -1) 
	{
		adauga(lista_undo, copiazaLista(v));
		Tranzactie* electronicNou = creeazaElectronic(id, tip, producator, model, pretNou, cantitate);
		Tranzactie* e = getElem(v, poz_to_delete);
		distrugeElectronic(e);
		setElem(v, poz_to_delete, electronicNou);
		return 1;}
	else
		return 0;
}
//
//Lista* filterTranzactie(Lista* v, char* producator)
//{
//
//	if (strcmp(producator, "") != 0) 
//	{
//		Lista* filteredList = createEmpty();
//		for (int i = 0; i < v->lungime; i++) {
//			Tranzactie* e = getElem(v, i);
//			if (strcmp(producator, e->producator) == 0)
//				adauga(filteredList, creeazaElectronic(e->id, e->tip, e->producator,e->model, e->pret, e->cantitate));
//		}
//		return filteredList;}
//	else {
//		return copiazaLista(v);
//	}
//}
//
//Lista* new_filter(Lista* v, char* tip)
//{
//	if (strcmp(tip, "") != 0)
//	{
//		Lista* filteredList = createEmpty();
//		for (int i = 0; i < v->lungime; i++)
//		{
//			Tranzactie* e = getElem(v, i);
//			if (strcmp(tip, e->tip) == 0)
//				adauga(filteredList, creeazaElectronic(e->id, e->tip, e->producator, e->model, e->pret, e->cantitate));
//		}
//		return filteredList;}
//	else return copiazaLista(v);
//}


int undo(Lista* v, Lista* lista_undo)
{
	if (lista_undo->lungime == 0) return 0;
	for (int i = 0; i < v->lungime; i++)
	{
		Tranzactie* element = getElem(v, i);
		distrugeElectronic(element);
	}
	Lista* auxiliar = lista_undo->elems[lista_undo->lungime - 1]; //salvez in auxiliar ultima iteratie a listei
	v->lungime = auxiliar->lungime;
	for (int i = 0; i < auxiliar->lungime; i++)
		setElem(v, i, copiazaElectronic(auxiliar->elems[i]));
	destroy(lista_undo->elems[lista_undo->lungime - 1], distrugeElectronic);
	lista_undo->lungime -= 1;
	return 1;
}


void testAddService() {
	Lista* v = createEmpty();
	Lista* undo_list = createEmpty();
	int successful1 = adaugaElectronic(v,undo_list, 123, "Telefon", "Apple", "Iphone 13", 3500, 4);
	assert(successful1 == 1);

	int successful2 = adaugaElectronic(v, undo_list, 124, "", "", "erfgrfg", 700, 4);
	assert(successful2 == 0);

	assert(nrElem(v) == 1);
	Tranzactie* e = getElem(v, 0);

	assert(e->id == 123);
	assert(strcmp(e->model, "Iphone 13") == 0);
	assert(e->cantitate == 4);
	destroy(v, distrugeElectronic);
	destroy(undo_list, destroy_lista);
}
void testFindService() 
{
	Lista* v = createEmpty();
	Lista* undo_list = createEmpty();
	int successful1 = adaugaElectronic(v, undo_list, 123, "Telefon", "Apple", "Iphone 13", 3500, 4);
	assert(successful1 == 1);

	int successful2 = adaugaElectronic(v, undo_list, 112, "Laptop", "Apple", "Macbook Air", 6000, 2);
	assert(successful2 == 1);

	assert(nrElem(v) == 2);
	int poz = findElectronic(v, 123);

	assert(poz == 0);

	destroy(v,distrugeElectronic);
	destroy(undo_list, destroy_lista);
}

void testModifyService() {
	Lista* v = createEmpty();
	Lista* undo_list = createEmpty();
	int successful1 = adaugaElectronic(v, undo_list, 123, "Telefon", "Apple", "Iphone 13", 3500, 4);
	assert(successful1 == 1);

	int successful2 = adaugaElectronic(v, undo_list, 112, "Laptop", "Apple", "Macbook Air", 6000, 2);
	assert(successful2 == 1);

	assert(nrElem(v) == 2);
	int modify_failure = modificaElectronic(v, undo_list, 100, "Laptop", "Apple", "Macbook Air", 6000, 1);
	assert(modify_failure == 0);

	int modify_success = modificaElectronic(v,undo_list, 123, "Telefon", "Apple", "Iphone 13", 3000, 4);
	assert(modify_success == 1);
	destroy(v, distrugeElectronic);
	destroy(undo_list, destroy_lista);
}

void testDeleteService() {
	Lista* v = createEmpty();
	Lista* undo_list = createEmpty();
	int successful1 = adaugaElectronic(v, undo_list, 123, "Telefon", "Apple", "Iphone 13", 3500, 4);
	assert(successful1 == 1);

	int successful2 = adaugaElectronic(v, undo_list, 112, "Laptop", "Apple", "Macbook Air", 6000, 2);
	assert(successful2 == 1);

	assert(nrElem(v) == 2);
	int unsuccesful_del = stergeElectronic(v, undo_list, 100);
	assert(unsuccesful_del == 0);
	int succesful_del = stergeElectronic(v,undo_list, 123);
	assert(succesful_del == 1);
	destroy(v, distrugeElectronic);
	destroy(undo_list, destroy_lista);
}

void testFilterService() {
	Lista* v = createEmpty();
	Lista* undo_list = createEmpty();
	int successful1 = adaugaElectronic(v, undo_list, 123, "Telefon", "Apple", "Iphone 13", 3500, 4);
	assert(successful1 == 1);

	int successful2 = adaugaElectronic(v, undo_list, 112, "Laptop", "Apple", "Macbook Air", 6000, 2);
	assert(successful2 == 1);

	assert(nrElem(v) == 2);

	Lista* filteredList = filterTranzactie(v, "Apple");
	assert(nrElem(filteredList) == 2);

	Lista* filteredList_gresit = filterTranzactie(v, "");
	assert(nrElem(filteredList_gresit) == 2);

	destroy(filteredList, distrugeElectronic);
	destroy(filteredList_gresit, distrugeElectronic);
	//testint new filter
	int succesful3 = adaugaElectronic(v, undo_list, 112, "Laptop", "Asus", "VivoBook", 3500, 2);
	assert(succesful3 == 1);
	assert(nrElem(v) == 3);

	Lista* new_filteredList = new_filter(v, "Laptop");
	assert(nrElem(new_filteredList) == 2);

	Lista* new_filteredList_gresit = new_filter(v, "");
	assert(nrElem(new_filteredList_gresit) == 3);

	destroy(new_filteredList, distrugeElectronic);
	destroy(new_filteredList_gresit, distrugeElectronic);
	destroy(v, distrugeElectronic);
	destroy(undo_list, destroy_lista);

}

void testUndo()
{
	Lista* v = createEmpty();
	Lista* undo_list = createEmpty();
	int successful1 = adaugaElectronic(v, undo_list, 123, "Telefon", "Apple", "Iphone 13", 3500, 4);
	assert(successful1 == 1);

	int successful2 = adaugaElectronic(v, undo_list, 112, "Laptop", "Apple", "Macbook Air", 6000, 2);
	assert(successful2 == 1);

	assert(nrElem(v) == 2);
	undo(v, undo_list);
	assert(nrElem(v) == 1);

	int succesful_del = stergeElectronic(v, undo_list, 123);
	assert(succesful_del == 1);

	assert(nrElem(v) == 0);
	undo(v, undo_list);
	assert(nrElem(v) == 1);

	destroy(v, distrugeElectronic);
	destroy(undo_list, destroy_lista);
}