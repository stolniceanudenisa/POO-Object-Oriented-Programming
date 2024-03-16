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
			this->add();
		}
		else if (optiune == "2")
		{
			optiunecorecta = true;
			this->nrprofigreva();
		}
		else if (optiune == "3")
		{
			optiunecorecta = true;
			this->disciplina_cu_cei_mai_multi_profi_greva();
		}
		else if (optiune == "4")
		{
			optiunecorecta = true;
			this->clasa_cu_cei_mai_multi_profi_greva();
		}
		
		else if (optiune == "a")
		{
			optiunecorecta = true;
			this->list_profesori();
		}
		else if (optiune == "x")
		{
			break;
		}
	}
}

void UI::display_menu()
{
	cout<<"1. Adauga profesor: "<<endl;
	cout<<"2. Numar profesori greva: "<<endl;
	cout<<"3. disciplina_cu_cei_mai_multi_profi_greva: "<<endl;
	cout<<"4. clasa_cu_cei_mai_multi_profi_greva: "<<endl;
	cout<<"a. Afiseaza profesori: "<<endl;
	cout<<"x. Iesire: "<<endl;
}

void UI::add()
{
	string nume, disciplina, clase, greva;
	cout << "Nume: ";
	getline(cin, nume);
	cout << "Disciplina: ";
	getline(cin, disciplina);
	cout << "Clase: ";
	getline(cin, clase);
	cout << "Greva: ";
	getline(cin, greva);
	try
	{
		this->service.addProfesor(nume, disciplina, clase, greva);
	}
	catch (ValidationException& ve)
	{
		cout << ve.what() << endl;
	}
 
}

void UI::list_profesori()
{
	vector<Profesor> profesori = this->service.getAll();
	if (profesori.size() == 0)
	{
		cout << "Niciun profesor." << '\n';
		return;
	}
	for (int i = 0; i < profesori.size(); i++)
		cout << profesori[i].toString() << '\n';
 
}

void UI::nrprofigreva()
{
	int nr = this->service.nr_profesori_greva();
	cout << "Numarul de profesori in greva este: " << nr << '\n';
}

void UI::disciplina_cu_cei_mai_multi_profi_greva()
{
	vector<Profesor> profesori = this->service.disciplina_cu_cei_mai_multi_profi_greva();
	if (profesori.size() == 0)
	{
		cout << "Nu exista profesori in greva." << '\n';
		return;
	}
	for (int i = 0; i < profesori.size(); i++)
		cout << profesori[i].getDisciplina() << '\n';
}

void UI::clasa_cu_cei_mai_multi_profi_greva()
{
	vector<Profesor> profesori = this->service.clasa_cu_cei_mai_multi_profi_greva();
	if (profesori.size() == 0)
	{
		cout << "Nu exista profesori in greva." << '\n';
		return;
	}
	for (int i = 0; i < profesori.size(); i++)
	{
		cout << "Clasa: "<<profesori[0].getClase();
		break;
	}
}
