#include "ui.h"
#include "exceptii.h"

UI::UI(Service& service): service(service)
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
			this->addmeciui();
		}
		else if (optiune == "2")
		{
			optiunecorecta = true;
			this->sortare_scor1ui();
		}
		else if (optiune == "3")
		{
			optiunecorecta = true;
			this->clasament2();
		}
		else if (optiune == "4")
		{
			optiunecorecta = true;
			this->deletemeciui();
		}

		else if (optiune == "a")
		{
			optiunecorecta = true;
			this->list_meciuri();
		}
		else if (optiune == "x")
		{
			break;
		}
	}

}

void UI::display_menu()
{
	cout << "1.Adauga meci\n";
	cout << "2.Sortare dupa primul scor\n";
	cout << "3.Afisare clasament\n";
	cout << "4.Sterge meci\n";
	cout << "a.Afisare meciuri\n";
	cout << "x.Exit\n";

}

void UI::list_meciuri()
{
	vector<Meci> meciuri = this->service.get_all();



	if (meciuri.size() == 0) {
		cout << "Niciun meci." << '\n';
		return;
	}
	for (int i = 0; i < meciuri.size(); i++) {
		cout << meciuri[i].to_string() << '\n';
	}

}


void UI::addmeciui()
{
	string numeechipa1, numeechipa2;
	int scor1, scor2;
	cout << "Nume echipa 1: ";
	cin >> numeechipa1;
	cout << "Nume echipa 2: ";
	cin >> numeechipa2;
	cout << "Scor1: ";
	cin >> scor1;
	cout << "Scor2: ";
	cin >> scor2;

	try{
		this->service.addmecis(numeechipa1, numeechipa2, scor1, scor2);
	}
	catch (ValidationException& ve)
	{
		cout << ve.what() << endl;
	}
	catch (const invalid_argument& e)
	{
		cerr << e.what() << endl;
	}



	/*try {
		this->service.addActivity(title, descriere, tip, durata);
	}
	catch (ValidationException& exception) {
		cout << exception << '\n';
	}
	catch (RepositoryException& exception) {
		cout << exception << '\n';
	}*/


}

void UI::deletemeciui()
{
	string numeech1;
	cout << "Numele echipei 1: ";
	cin >> numeech1;
	try {
		this->service.deletemecis(numeech1);

	}
	catch (const invalid_argument& e)
	{
		cerr << e.what() << endl;
	}
}

void UI::sortare_scor1ui()
{
	vector<Meci> meciuri = this->service.sortare_scor1();
	for (int i = 0; i < meciuri.size(); i++)
		cout << meciuri[i].to_string() << '\n';
}
 
 
void UI::clasament2()
{
	vector<Meci> clasament = this->service.clasament2();

	cout << "Clasament:\n";
	int pozitie = 1;
	for (auto& meci : clasament) {
		cout << pozitie << ". " << meci.get_echipa1() << " - " << meci.get_echipa2() << ": "
			<< meci.get_scor1() << " puncte, " << meci.get_scor2() << " puncte\n";
		pozitie++;
	}
}


