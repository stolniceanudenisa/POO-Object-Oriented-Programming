#include "sortare.h"
#include <assert.h>

/**
* Sorteaza in place
* cmpf - relatia dupa care se sorteaza
*/
void sort(Lista* l, FunctieComparare cmpF) {
	int i, j;
	for (i = 0; i < nrElem(l); i++) {
		for (j = i + 1; j < nrElem(l); j++) {
			Tranzactie* e1 = getElem(l, i);
			Tranzactie* e2 = getElem(l, j);
			if (cmpF(e1, e2) > 0) 
			{
				//interschimbam
				setElem(l, i, e2);
				setElem(l, j, e1);
			}
		}
	}
}

int cmpPret(Tranzactie* e1, Tranzactie* e2)
{
	return (e1->pret > e2->pret);
}

Lista* sortByPret(Lista* v) {
	Lista* sortedList = copiazaLista(v);
	sort(sortedList, cmpPret);
	return sortedList;
}

void testSort()
{
	Lista* v = createEmpty();
	Lista* undo_list = createEmpty();
	int successful1 = adaugaElectronic(v, undo_list, 113, "Telefon", "Apple", "Iphone 13", 3500, 4);
	assert(successful1 == 1);

	int successful2 = adaugaElectronic(v, undo_list, 112, "Laptop", "Apple", "Macbook Air", 6000, 2);
	assert(successful2 == 1);

	int succesful3 = adaugaElectronic(v, undo_list, 111, "Laptop", "Asus", "VivoBook", 3000, 2);
	assert(succesful3 == 1);

	Lista* sortedList = sortByPret(v);
	assert(nrElem(v) == 3);

	Tranzactie* p1 = sortedList->elems[0];
	Tranzactie* p2 = sortedList->elems[1];
	Tranzactie* p3 = sortedList->elems[2];
	assert((p1->pret - 3000) < 0.0001);
	assert((p2->pret - 3500) < 0.0001);
	assert((p3->pret - 6000) < 0.0001);

	destroy(sortedList, distrugeElectronic);
	destroy(v, distrugeElectronic);
	destroy(undo_list, destroy_lista);
}