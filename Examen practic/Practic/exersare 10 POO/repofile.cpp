#include "repofile.h"

/// <summary>
///citirea din fisier
/// </summary> citeste din fisier si adauga in lista de melodii
void RepoFile::loadfromfile()
{
	this->melodii.clear();

	ifstream fisier(this->filename);
	if(!fisier.is_open())
			throw exception("Fisierul nu s-a putut deschide!");

	string denumire, cantaret, gen;
	int durata;
	while (fisier >> denumire >> cantaret >> gen >> durata)
	{
		if (fisier.fail())
			throw exception("Eroare la citirea din fisier!");

		Melodie m(denumire, cantaret, gen, durata);
		this->melodii.push_back(m);
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
	vector<Melodie> nou = this->getAll();
	for (auto& melodie : nou)
	{
		fisier << melodie.getDenumire() << ' ';
		fisier << melodie.getCantaret() << ' ';
		fisier << melodie.getGen() << ' ';
		fisier << melodie.getDurata() << '\n';

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

vector<Melodie> RepoFile::getAll()
{
	return this->melodii;
}

void RepoFile::addmelodie(Melodie m)
{
	this->validator.validate(m);
	if(find(m.getDenumire())== 1)
		throw invalid_argument("Melodia exista deja!");
	else
	{
		this->melodii.push_back(m);
		
	}
	this->savetofile();
}

void RepoFile::insertmelodie(Melodie m, int pos)
{
	this->validator.validate(m);
	if (find(m.getDenumire()) == 1)
		throw invalid_argument("Melodia exista deja!");
	else
	{
		this->melodii.insert(this->melodii.begin() + pos, m);
	}
	this->savetofile();
}

void RepoFile::updatemelodie(Melodie m)
{
	this->validator.validate(m);
	if (find(m.getDenumire()) == -1)
		throw invalid_argument("Melodia nu exista!");
	else
	{
		for (int i = 0; i < this->melodii.size(); i++)
			if (this->melodii[i].getDenumire() == m.getDenumire())
			{
				this->melodii[i] = m;
			
			}
	}
	this->savetofile();
}



//updateaza doar durata melodiei cu denumirea data
void RepoFile::update_anumit(Melodie m)
{
	this->validator.validate(m);
	if (find(m.getDenumire()) == -1)
		throw invalid_argument("Melodia nu exista!");
	else
	{
		for (int i = 0; i < this->melodii.size(); i++)
			if (this->melodii[i].getDenumire() == m.getDenumire())
			{
				this->melodii[i].setDurata(m.getDurata());
			}
	}
	this->savetofile();
}

void RepoFile::deletemelodie(Melodie m)
{
	if(find(m.getDenumire()) == -1)
		throw invalid_argument("Melodia nu exista!");
	else
	{
		for (int i = 0; i < this->melodii.size(); i++)
			if (this->melodii[i].getDenumire() == m.getDenumire())
				this->melodii.erase(this->melodii.begin() + i);
	}
	this->savetofile();
}

void RepoFile::delete_between( int start, int end)
{
	vector <Melodie> nou;
	if (start < 0 || end > this->melodii.size())
		throw invalid_argument("Pozitii invalide!");
	else
		for (int i = 0; i < this->melodii.size(); i++)
			if (this->melodii[i].getDurata() < start
				|| this->melodii[i].getDurata() > end)			
			{
				nou.push_back(this->melodii[i]);
				//this->melodii.erase(this->melodii.begin() + start, this->melodii.begin() + end);
			}
	this->melodii = nou;	
	this->savetofile();


	/*vector<Melodie>::iterator it = melodii.begin();
	while (it != melodii.end()) {
		if (it->getDurata() >= start && it->getDurata() <= end) {
			it = melodii.erase(it);
		}
		else {
			++it;
		}
	}*/
}

int RepoFile::find(string denumire)
{
	for(int i=0;i<this->melodii.size();i++)
		if (this->melodii[i].getDenumire() == denumire)
			return 1;
	return -1;
}

int RepoFile::find_melodie(Melodie melodie)
{
	
for (int i = 0; i < this->melodii.size(); i++)
		if (this->melodii[i].getDenumire() == melodie.getDenumire() && this->melodii[i].getCantaret() == melodie.getCantaret() && this->melodii[i].getGen() == melodie.getGen() && this->melodii[i].getDurata() == melodie.getDurata())
			return i;
	return -1;
}

 