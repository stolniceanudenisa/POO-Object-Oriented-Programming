
#include "repo.h"

/// <summary>
/// Constructor implicit
/// </summary>
/// <param name="filename"></param> numele fisierului
/// <param name="validator"></param> validatorul
RepoFile::RepoFile(string filename, Validator validator)
{
	this->filename = filename;
	this->validator = validator;
	this->loadfromfile();
}


/// <summary>
///citirea din fisier
/// </summary> citeste din fisier si adauga in lista de melodii
void RepoFile::loadfromfile()
{
	this->rochii.clear();

	ifstream fisier(this->filename);
	if (!fisier.is_open())
		throw exception("Fisierul nu s-a putut deschide!");

	string denumire, marime, culoare, personalizare;
	int id, nr_disponibile, pret;
	while (fisier >> id >> denumire >> marime >> culoare >>  nr_disponibile >> pret >> personalizare)
	{
		if (fisier.fail())
			throw exception("Eroare la citirea din fisier!");

		Rochie r( id, denumire,  marime, culoare,nr_disponibile,pret,personalizare);
		this->rochii.push_back(r);
	}
}

/// <summary>
/// scrierea in fisier
/// </summary> scrie in fisier lista de melodii
void RepoFile::savetofile()
{
	ofstream fisier(this->filename);
	if (!fisier.is_open())
		throw exception("Fisierul nu s-a putut deschide pentru scriere!");
	vector<Rochie> nou = this->getAll();
	for (auto& melodie : nou)
	{
		fisier << melodie.get_id() << ' ';
		fisier << melodie.get_denumire() << ' ';
		fisier << melodie.get_marime() << ' ';
		fisier << melodie.get_culoare() << ' ';
		fisier << melodie.get_nr_disponibile() << ' ';
		fisier << melodie.get_pret() << ' ';
		fisier << melodie.get_personalizare() << '\n';

	}
}

/// <summary>
///	Destructor
/// </summary>

RepoFile::~RepoFile()
{
}

/// <summary>
/// Functie de get tall
/// </summary>
/// <returns></returns> toate rochiile
vector<Rochie> RepoFile::getAll()
{
	return this->rochii;
}

/// <summary>
/// Functie de find
/// </summary>
/// <param name="id"></param> id-ul rochiei
/// <returns></returns> 1 daca a gasit rochia, -1 daca nu
int RepoFile::find(int id)
{
	for (int i = 0; i < this->rochii.size(); i++)
		if (this->rochii[i].get_id() == id)
			return 1;
	return -1;
}

 
