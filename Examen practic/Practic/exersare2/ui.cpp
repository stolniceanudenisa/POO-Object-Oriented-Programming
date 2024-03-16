#include "ui.h"

UI::UI(Service& service) : service(service)
{
	//this->service=service;
}

UI::~UI()
{
}

void UI::run_menu()
{
	string optiune;
	bool optiunecorecta;
	while (true)
	{
		cout << endl;
		this->display_menu();
		cout << endl;
		optiunecorecta = false;
		cout << "Introduceti optiunea: ";
		getline(cin, optiune);
		if (optiune == "1")
		{
			optiunecorecta = true;
			this->addcui();
		}
		else if (optiune == "2")
		{
			optiunecorecta = true;
			this->afisarezi();
		}

		else if (optiune == "a")
		{
			optiunecorecta = true;
			this->show_all(this->service.get_all());
		}
		else if (optiune == "x")
		{
			break;
		}
		else if (!optiunecorecta)
		{
			cout << "Optiune gresita! Reincercati\n";
		}
	}
}

void UI::display_menu()
{
	cout << "1.Adauga ceva in catalog\n";
	cout << "a.Afisare catalog\n";
	cout << "x.Exit\n";
}

void UI::show_all(vector<Catalog*> cataloage)
{
	for (int i = 0; i < cataloage.size(); i++)
	{
		cout << cataloage[i]->to_string() << "\n";
	}
}

void UI::addcui()
{
	int nota;
	string nume, materie, data;

	cout << "Introduceti nota: ";
	cin >> nota;
	cin.ignore();

	cout << "Introduceti nume elev: ";
	getline(cin, nume);

	cout << "Introduceti materie: ";
	getline(cin, materie);

	cout << "Introduceti data: ";
	getline(cin, data);

	this->service.adds(nota, nume, materie, data);

}

void UI::afisarezi()
{
	string datai, dataf;
	cout << "Data inceput: ";
	getline(cin, datai);
	cout << "Data sfarsit: ";
	getline(cin, dataf);

	this->print_catalog(service.filter_interval(datai, dataf));
}

void UI::print_catalog(vector<Catalog*> cataloage)
{
	for (int i = 0; i < cataloage.size(); i++)
	{
		cout << cataloage[i]->to_string() << endl;
	}
}
