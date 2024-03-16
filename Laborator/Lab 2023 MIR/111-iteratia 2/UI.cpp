#include "UI.h"
#include <iostream>

using namespace std;

UI::UI(Service& service) : service(service)
{

}

UI::~UI()
{
}

void UI::runMenu()
{
	char optiune[5];
	bool optiuneGresita;
	while (true)
	{
		this->displayMenu();
		cin >> optiune;
		optiuneGresita = true;
		if (strcmp(optiune, "1") == 0)
		{
			this->uiAddStudent();
			optiuneGresita = false;
		}
		if (strcmp(optiune, "2") == 0)
		{
			this->uiUpdateVarstaDupaNume();
			optiuneGresita = false;
		}
		if (strcmp(optiune, "3") == 0)
		{
			this->uiDeleteBetweenAges();
			optiuneGresita = false;
		}
		if (strcmp(optiune, "a") == 0)
		{
			this->showAll();
			optiuneGresita = false;
		}
		if (strcmp(optiune, "x") == 0)
		{
			break;
		}
		if (optiuneGresita)
		{
			cout << "Optiune gresita! Reincercati: ";
		}
	}
}

void UI::displayMenu()
{
	cout << "1. Adauga student" << endl;
	cout << "2. Updateaza varsta dupa nume" << endl;
	cout << "3. Sterge studenti intre varste date" << endl;
	cout << "a. Arata toti studentii" << endl;
	cout << "x. Iesire" << endl;
}

void UI::uiAddStudent()
{
	char nume[20];
	int varsta;
	cout << "Dati numele: ";
	cin >> nume;
	// poate citi si spatii
	// cin.getline(nume);
	cout << "Dati varsta: ";
	cin >> varsta;
	this->service.addStudent(nume, varsta);
}

void UI::uiUpdateVarstaDupaNume()
{
	char nume[20];
	int varsta;
	cout << "Dati numele studentilor carora vreti sa le modificati varsta: ";
	cin >> nume;
	cout << "Dati noua varsta: ";
	cin >> varsta;
	this->service.updateVarstaDupaNume(nume, varsta);
}

void UI::uiDeleteBetweenAges()
{
	int varstaMin, varstaMax;
	cout << "Dati varsta minima: ";
	cin >> varstaMin;
	cout << "Dati varsta maxima: ";
	cin >> varstaMax;
	this->service.deleteBetweenAges(varstaMin, varstaMax);
}

void UI::showAll()
{
	vector<Student> studenti = this->service.getAll();
	for (int i = 0; i < studenti.size(); i++)
	{
		cout << studenti[i] << endl;
	}
}
