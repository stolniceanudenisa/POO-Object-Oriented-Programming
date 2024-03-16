#include "repofile.h"

/// <summary>
///citirea din fisier
/// </summary> citeste din fisier si adauga in lista de profesori
void RepoFile::loadfromfile()
{
	this->profesori.clear();

	ifstream fisier(this->filename);
	if (!fisier.is_open())
		throw exception("Fisierul nu s-a putut deschide!");

	string nume, disciplina, clase, greva;
	while (fisier >> nume >> disciplina >> clase >> greva)
	{
		if (fisier.fail())
			throw exception("Eroare la citirea din fisier!");

		Profesor p(nume, disciplina, clase, greva);
		this->profesori.push_back(p);
	}
}

/// <summary>
/// scrierea in fisier
/// </summary> scrie in fisier lista de profesori
void RepoFile::savetofile()
{
	ofstream fisier(this->filename);
	if (!fisier.is_open())
		throw exception("Fisierul nu s-a putut deschide pentru scriere!");
	vector<Profesor> nou = this->getAll();
	for (auto& melodie : nou)
	{
		fisier << melodie.getNume() << ' ';
		fisier << melodie.getDisciplina() << ' ';
		fisier << melodie.getClase() << ' ';
		fisier << melodie.getGreva() << '\n';
		 
	}
}

RepoFile::RepoFile(string filename, Validator validator)
{
	this->filename = filename;
	this->validator = validator;
	this->loadfromfile();
}

RepoFile::~RepoFile()
{
}

vector<Profesor> RepoFile::getAll()
{
	return this->profesori;
}

void RepoFile::addProfesor(Profesor p)
{
	this->validator.validate(p);
	/*if (find(p.getNume()) == 1)
		throw invalid_argument("Melodia exista deja!");
	else
	{
		this->melodii.push_back(m);

	}*/
	profesori.push_back(p);
	this->savetofile();
}
 
 
int RepoFile::find(string nume)
{
	for (int i = 0; i < this->profesori.size(); i++)
		if (this->profesori[i].getNume() == nume)
			return 1;
	return -1;
}

int RepoFile::findProfesor(Profesor p)
{
	for (int i = 0; i < this->profesori.size(); i++)
		if (this->profesori[i] == p)
			return i;
	return -1;
}
