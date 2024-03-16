#include "ui.h"
#include "exceptii.h"
UI::UI(Service& service) : service(service)
{
	this->undo = service.getAll();
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
			this->addmelodie();
		}
		else if (optiune == "2")
		{
			optiunecorecta = true;
			this->deletemelodie();
		}
		else if (optiune == "3")
		{
			optiunecorecta = true;
			this->updatemelodie();
		}
		else if (optiune == "4")
		{
			optiunecorecta = true;
			this->filtrare_gen();
		}
		else if (optiune == "5")
		{
			optiunecorecta = true;
			this->sortare_durata();
		}
		else if (optiune == "6")
		{
			optiunecorecta = true;
			this->numar_de_melodii_cantaret();
		}

		else if (optiune == "7")
		{
			optiunecorecta = true;
			this->afisare_melodii_sub_4_minute();
		}
		else if (optiune == "8")
		{
			optiunecorecta = true;
			this->sortare_denumire();
		}
		else if (optiune == "9")
		{
			optiunecorecta = true;
			this->sortare_cantaret_denumire();
		}
		else if (optiune == "10")
		{
			optiunecorecta = true;
			this->update_anumit();
		}
		else if (optiune == "11")
		{
			optiunecorecta = true;
		
			this->cautare_melodie();
		}
		else if (optiune == "12")
		{
			optiunecorecta = true;

			this->durata_min_max();
		}
		else if (optiune == "13")
		{
			optiunecorecta = true;

			this->insertmelodie();
		}	

		else if (optiune == "14")
		{
			optiunecorecta = true;

			this->vizualizare_per_gen();
		}

		
		else if (optiune == "15")
		{
			optiunecorecta = true;
			this->undo_op();
		}
		else if (optiune == "16")
		{
			optiunecorecta = true;
			this->delete_between();
		}
		else if (optiune == "17")
		{
			optiunecorecta = true;
			this->max_durata();
		}
		else if (optiune == "a")
		{
			optiunecorecta = true;
			this->list_melodii();
		}
		else if (optiune == "x")
		{
			break;
		}
	}
}

void UI::display_menu()
{
	cout << "1.Adauga melodie\n";
	cout << "2.Sterge melodie\n";
	cout << "3.Update melodie\n";
	cout << "4.Filtrare dupa un anumit gen\n";
	cout << "5.Sortare dupa durata\n";
	cout << "6.Numar melodii cantaret\n";
	cout << "7.Melodii sub 4 minute\n";
	cout << "8.Sortare denumire\n";
	cout << "9.Sortare cantaret egal / melodie\n";
	cout << "10.Update anumit\n";
	cout << "11.Cauatare melodie dupa nume\n";
	cout << "12.Durata min max\n";
	cout << "13.Insereaza melodie\n";
	cout << "14.vizualizare_per_gen\n";
	
	
	cout << "15.Undo\n";
	cout << "16.delete_between\n";
	cout << "17.max durata\n";



	cout << "a.Afisare melodii\n";
	cout << "x.Exit\n";
}

void UI::list_melodii()
{
	vector<Melodie> melodii = this->service.getAll();
	if (melodii.size() == 0)
	{
		cout<<"Nicio melodie."<<'\n';
		return;
	}
	for(int i=0; i<melodii.size(); i++)
		cout<<melodii[i].toString()<<'\n';
}


void UI::addmelodie()
{
	string denumire, cantaret, gen;
	int durata;
	cout << "Denumire: ";
	cin >> denumire;
	cout << "Cantaret: ";
	cin >> cantaret;
	cout << "Gen: ";
	cin >> gen;
	cout << "Durata: ";
	cin >> durata;
	this->undo = service.getAll();

	try {
	this->service.addmelodie(denumire, cantaret, gen, durata);
	}
	catch (ValidationException& ve)
	{
		cout << ve.what() << endl;
	}
	catch (const invalid_argument& e)
	{
		cerr<<e.what()<<'\n';
	}
}

void UI::insertmelodie()
{
	string denumire, cantaret, gen;
	int durata, pos;
	cout << "Pozitia: ";
	cin >> pos;
	cout << "Denumire: ";
	cin >> denumire;
	cout << "Cantaret: ";
	cin >> cantaret;
	cout << "Gen: ";
	cin >> gen;
	cout << "Durata: ";
	cin >> durata;
	this->undo = service.getAll();

	try {
		this->service.insertmelodie(denumire, cantaret, gen, durata, pos);
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

void UI::deletemelodie()
{
	string denumire;
	cout << "Denumirea melodiei ce se va sterge: ";
	cin >> denumire;
	try {
		this->service.deletemelodie(denumire);
	}
	catch (const invalid_argument& e)
	{
		cerr << e.what() << '\n';
	}
}

void UI::delete_between()
{
int start, end;
	cout << "Start: ";
	cin >> start;
	cout << "End: ";
	cin >> end;
try {
		this->service.delete_between(start, end);
	}
	catch (const invalid_argument& e)
	{
		cerr << e.what() << '\n';
	}
}

void UI::updatemelodie()
{
	string denumire, cantaret, gen;
	int durata;
	cout << "Denumirea melodiei care va fi modificata: ";
	cin >> denumire;
	cout << "Cantaret: ";
	cin >> cantaret;
	cout << "Gen: ";
	cin >> gen;
	cout << "Durata: ";
	cin >> durata;

	try {
		this->service.updatemelodie(denumire, cantaret, gen, durata);
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

 
void UI::update_anumit()
{
	string denumire, cantaret, gen;
	int durata;
	cout << "Denumirea melodiei a carei DOAR DURATA va fi modificata: ";
	cin >> denumire;
	cout << "Durata: ";
	cin >> durata;
	try {
		this->service.update_anumit(denumire, cantaret, gen, durata);
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

void UI::filtrare_gen()
{
	string gen;
	cout << "Genul dupa care se va face filtrarea: ";
	cin >> gen;
	vector<Melodie> melodii = this->service.filtrare_gen(gen);
	if (melodii.size() == 0)
	{
		cout << "Nicio melodie." << '\n';
		return;
	}
	for (int i = 0; i < melodii.size(); i++)
		cout << melodii[i].toString() << '\n';
}

void UI::sortare_durata()
{

	vector<Melodie> melodii = this->service.sortare_durata();
	if (melodii.size() == 0)
	{
		cout << "Nicio melodie." << '\n';
		return;
	}
	for (int i = 0; i < melodii.size(); i++)
		cout << melodii[i].toString() << '\n';
}

void UI::sortare_denumire()
{
	int ordine;
	cout<<"1.Crescator\n";
	cout<<"2.Descrescator\n";
	cin >> ordine;
	bool ascending = ordine == 1;
	vector<Melodie> melodii = this->service.sortare_denumire(ascending);
	if (melodii.size() == 0)
	{
		cout << "Nicio melodie." << '\n';
		return;
	}
	for (int i = 0; i < melodii.size(); i++)
		cout << melodii[i].toString() << '\n';
}

void UI::sortare_cantaret_denumire()
{
 vector<Melodie> melodii = this->service.sortare_cantaret_denumire();
	if (melodii.size() == 0)
	{
		cout << "Nicio melodie." << '\n';
		return;
	}
	for (int i = 0; i < melodii.size(); i++)
		cout << melodii[i].toString() << '\n';
}

void UI::max_durata()
{
int durata;
	
	vector<Melodie> melodii = this->service.max_durata();
	if (melodii.size() == 0)
	{
		cout << "Nicio melodie." << '\n';
		return;
	}
	for (int i = 0; i < melodii.size(); i++)
		cout << melodii[i].toString() << '\n';
}

void UI::cautare_melodie()
{
string denumire;
	cout << "Denumirea melodiei cautate: ";
	cin >> denumire;
	vector<Melodie> melodii =  this->service.cautare_melodie(denumire);
	if (melodii.size() == 0)
	{
		cout << "Nicio melodie." << '\n';
		return;
	}
	for (int i = 0; i < melodii.size(); i++)
		cout << melodii[i].toString() << '\n';
}

//afisarea numelui cantaretului si a numarului de melodii cantate
void UI::numar_de_melodii_cantaret()
{
	vector<Melodie> cantareti = this->service.numar_de_melodii_cantaret();
	if (cantareti.size() == 0)
	{
		cout << "Niciun cantaret." << '\n';
		return;
	}
	for (int i = 0; i < cantareti.size(); i++)
		cout << cantareti[i].toString() << '\n';
}

void UI::afisare_melodii_sub_4_minute()
{
	vector<Melodie> melodii = this->service.afisare_melodii_sub_4_minute();
	if (melodii.size() == 0)
	{
		cout << "Nicio melodie." << '\n';
		return;
	}
	for (int i = 0; i < melodii.size(); i++)
		cout << melodii[i].toString() << '\n';
}

void UI::durata_min_max()
{
	int min, max;
	cout << "Durata minima: ";
	cin >> min;
	cout << "Durata maxima: ";
	cin >> max;
	vector<Melodie> melodii = this->service.durata_min_max(min, max);
	if (melodii.size() == 0)
	{
		cout << "Nicio melodie." << '\n';
		return;
	}
	for (int i = 0; i < melodii.size(); i++)
		cout << melodii[i].toString() << '\n';
}

//undo operatie dupa orice operatie revine la starea de dinainte a listei de melodii
void UI::undo_op()
{

	//this->service = this->undo;
	cout << "Undo efectuat!";
}

void UI::generare_random()
{
	int nr;
	cout << "Numarul de melodii ce se vor genera: ";
	cin >> nr;
	this->service.generare_random(nr);
}

void UI::vizualizare_per_gen()
{
	 auto melodii = this->service.vizualizare_per_gen();
	if (melodii.size() == 0)
	{
		cout << "Nicio melodie." << '\n';
		return;
	}
	cout << "Statistica melodiilor pe genuri:\n";
	for (auto& pair : melodii) {
			cout<<pair.first<<" "<<pair.second<<'\n';
	}
		 
}

 