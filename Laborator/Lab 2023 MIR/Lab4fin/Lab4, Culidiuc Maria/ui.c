#pragma once
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>

#include "TranzactieService.h"
#include "sortare.h"


void testAll() {
	testCreateDestroy();
	testIterate();
	testCopy();
	testAddService();
	testModifyService();
	testDeleteService();
	testFindService();
	testFilterService();
	liste_de_liste();
	testValideaza();
	testSort();
	testUndo();
}

void printAllTranzactie(Lista* v) 
{
	if (v->lungime == 0)
		printf("Nu exista Tranzactie.\n");
	else
	{
		printf("Tranzactiele din magazin sunt:\n");
		for (int i = 0; i < nrElem(v); i++) {
			Tranzactie* e = getElem(v, i);
			printf("Id:%d | Tip:%s | Producator:%s | Model:%s | Pret:%f | Cantitate:%d\n", e->id, e->tip, e->producator, e->model, e->pret, e->cantitate);
		};
	};
}

void printMenu() {
	printf("1. Adauga electronic\n2. Actualizare pret electronic\n");
	printf("3. Sterge electronic\n4. Vizualizeaza produse din stoc, ordonat dupa pret, crescator\n");
	printf("5. Vizualizeaza lista de produse filtrate dupa producator\n6. Tipareste toate\n\n7. Undo\n8. Filtrare lista de produse dupa tip\n0. Iesire\n");
}
void uiAdd(Lista* v, Lista* lista_undo) {
	printf("Id-ul electronicului:");
	int id;
	scanf_s("%d", &id);
	printf("Tipul:");
	char tip[30];
	scanf_s("%s", tip, 30);
	printf("Producatorul:");
	char producator[30];
	scanf_s("%s", producator, 30);
	printf("Modelul:");
	char model[30];
	scanf_s("%s", model, 30);
	printf("Pretul:");
	float p;
	scanf_s("%f", &p);
	printf("Cantitatea:");
	int cant;
	scanf_s("%d", &cant);

	int error = adaugaElectronic(v, lista_undo, id, tip, producator, model, p, cant);
	if (error != 0) {
		printf("Electronic adaugat.\n");
	}
	else {
		printf("Electronic invalid.\n");
	}

}
void uiModify(Lista* v, Lista* lista_undo) {
	int id, cant;
	char tip[30], producator[30], model[30];
	float pretNou;
	printf("Id-ul electronicului este:");
	scanf_s("%d", &id);
	printf("Tipul electronicului este:");
	scanf_s("%s", tip, 30);
	printf("Producatorul electronicului este:");
	scanf_s("%s", producator, 30);
	printf("Modelul este:");
	scanf_s("%s", model, 30);
	printf("Cantitatea este:");
	scanf_s("%d", &cant);
	printf("Pretul nou al electronicului:");
	scanf_s("%f", &pretNou);

	int successful = modificaElectronic(v, lista_undo, id, tip, producator, model, cant,pretNou);
	if (successful)
	{
		printf("Electronic modificat cu succes.\n");
		//printf("Id:%d Tip:%s Producator:%s Model:%s Pret:%f Cantitate:%d\n", id, tip, producator, model, pretNou, cant);
	}
	else
		printf("Nu exista electronic cu datele date.\n");

}

void uiDelete(Lista* v, Lista* lista_undo) {
	int id;
	printf("Id-ul electronicului este:");
	scanf_s("%d", &id);

	int successful = stergeElectronic(v,lista_undo, id);
	if (successful)
		printf("Electronic sters cu succes.\n");
	else
		printf("Nu exista electronic cu id-ul dat.\n");
}

void uiFilter(Lista* v) 
{
	char producator[30];
	printf("Producatorul electronicului este:");
	scanf_s("%s", producator, 30);
	Lista* filteredList = filterTranzactie(v, producator);
	printAllTranzactie(filteredList);
	destroy(filteredList, distrugeElectronic);

}

void ui_new_filter(Lista* v)
{
	char tip[30];
	printf("Tipul de electronic este:");
	scanf_s("%s", tip, 30);
	Lista* filteredList = new_filter(v, tip);
	printAllTranzactie(filteredList);
	destroy(filteredList, distrugeElectronic);
}


void uisortBPret(Lista* v) 
{
	Lista* sortedList = sortByPret(v);
	printAllTranzactie(sortedList);
	destroy(sortedList, distrugeElectronic);
}

void uiUndo(Lista* v, Lista* lista_undo)
{
	if (undo(v, lista_undo) == 0) printf("Nu se mai poate face undo\n");
	else
	{
		printf("S-a realizat undo cu succes!\n");
		printAllTranzactie(v);
	}
}


void run() {
	Lista* TranzactieList = createEmpty();
	Lista* undo_list = createEmpty();
	int running = 1;
	while (running) {
		printMenu();
		int cmd;
		printf("Comanda este:");
		scanf_s("%d", &cmd);
		switch (cmd) {
		case 1:
			uiAdd(TranzactieList,undo_list);
			break;
		case 2:
			uiModify(TranzactieList,undo_list);
			break;
		case 3:
			uiDelete(TranzactieList,undo_list);
			break;
		case 4:
			uisortBPret(TranzactieList);
			break;
		case 5:
			uiFilter(TranzactieList);
			break;
		case 6:
			printAllTranzactie(TranzactieList);
			break;
		case 7:
			uiUndo(TranzactieList,undo_list);
			break;
		case 8:
			ui_new_filter(TranzactieList);
			break;
		case 0:
			running = 0;
			destroy(TranzactieList, distrugeElectronic);
			destroy(undo_list, destroy_lista);
			break;
		default:
			printf("Comanda invalida!\n");

		}
	}
}

int main() {
	testAll();
	run();
	_CrtDumpMemoryLeaks();
}