#include "ui.h"
#include "exceptii.h"
UI::UI(Service& service) : service(service)
{
	//this->undo = service.getAll();
}

/// <summary>
/// Meniul aplicatiei
/// </summary>
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
			this->afisare_rochii_marime();
		}
		else if (optiune == "2")
		{
			optiunecorecta = true;
			this->cumparare_rochie();
		}
		else if (optiune == "3")
		{
			optiunecorecta = true;
			this->top3ui();
		}
		
		else if (optiune == "a")
		{
			optiunecorecta = true;
			this->list_rochii();
		}
		else if (optiune == "x")
		{
			break;
		}
	}
}

void UI::display_menu()
{
	cout << "1.Afisare rochii marime si personalizare \n";
	cout << "2.Cumparare rochie\n";
	cout << "3.Top 3\n";
	cout << "a.Afisare rochii\n";
	cout << "x.Exit\n";
}

/// <summary>
/// Lista cu toate rochiile
/// </summary>
void UI::list_rochii()
{
	vector<Rochie> rochii = this->service.getAll();
	if (rochii.size() == 0)
	{
		cout << "Nicio rochie." << '\n';
		return;
	}
	for (int i = 0; i < rochii.size(); i++)
		cout << rochii[i].toString() << '\n';
}

void UI::afisare_rochii_marime()
{
	string marime;
	string personalizare;
	try {
		cout << "Introduceti marimea: ";
		cin >> marime;
		cout << "Introduceti personalizarea: ";
		cin >> personalizare;
	
	
	vector<Rochie> rochii = this->service.afisare_rochii_marime(marime, personalizare);


	if (rochii.size() == 0)
	{
		cout << "Nu exista rochii cu aceasta marime si personalizare." << '\n';
		return;
	}
	
	for (int i = 0; i < rochii.size(); i++)
		cout << rochii[i].toString() << '\n';
	}
	catch (ValidationException& ve)
	{
		cout << ve.what() << endl;
	}
}

void UI::cumparare_rochie()
{
	int id;
	try {
		cout << "Introduceti id-ul rochiei: ";
		cin >> id;
	
	vector<Rochie> rochii = this->service.cumparare_rochie(id);
	/*if (rochii.size() == 0)
	{
		cout << "Nu exista rochie cu acest id." << '\n';
		return;
	}*/


	for (int i = 0; i < rochii.size(); i++)
		cout << rochii[i].toString() << '\n';
	}
	catch (ValidationException& ve)
	{
		cout << ve.what() << endl;
	}
	catch (const invalid_argument& e)
	{
		cerr << e.what() << '\n';
	}
}

void UI::top3ui()
{ 
	vector<pair<string, string>> rochii = this->service.top_3_rochii_ieftine();
	if (rochii.size() == 0)
	{
		cout << "Nu exista rochii." << '\n';
		return;
	}
	for (int i = 0; i < rochii.size(); i++)
		cout << rochii[i].first << " " << rochii[i].second << '\n';
}
 
