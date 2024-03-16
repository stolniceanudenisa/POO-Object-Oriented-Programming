#include "service.h"
#include <algorithm>
#include <map>
Service::Service(RepoFile& repofile): repofile(repofile)
{
	this->repofile = repofile;
}

vector<Melodie> Service::getAll()
{
	return repofile.getAll();
}

void Service::addmelodie(string denumire, string cantaret, string gen, int durata)
{
	
	Melodie m(denumire, cantaret, gen, durata);
	this->repofile.addmelodie(m);

}

void Service::updatemelodie(string denumire, string cantaret, string gen, int durata)
{
	Melodie m(denumire, cantaret, gen, durata);
	this->repofile.updatemelodie(m);

}

void Service::deletemelodie(string denumire)
{
	Melodie m(denumire, "", "", 0);
	this->repofile.deletemelodie(m);
}

void Service::delete_between(int start, int end)
{
	this->repofile.delete_between(start, end);
}

void Service::insertmelodie(string denumire, string cantaret, string gen, int durata, int pos)
{
	Melodie m(denumire, cantaret, gen, durata);
	this->repofile.insertmelodie(m, pos);
}


//updateaza doar durata melodiei cu denumirea data
void Service::update_anumit(string denumire, string cantaret, string gen, int durata)
{
	Melodie m(denumire, cantaret, gen, durata);
	this->repofile.update_anumit(m);	
}

//melodia cu cea mai mare durata
vector<Melodie> Service::max_durata()
{
	vector<Melodie> melodii = this->repofile.getAll();
	vector<Melodie> nou;
    int max = melodii[0].getDurata();
	for (int i = 1; i < melodii.size(); i++)
	{
		if (melodii[i].getDurata() > max)
			max = melodii[i].getDurata();
	}
	for (int i = 1; i < melodii.size(); i++)
	{
		if (melodii[i].getDurata() == max)
			nou.push_back(melodii[i]);
	}
	 return nou;

}

 
vector<Melodie> Service::cautare_melodie(string denumire)
{
	vector<Melodie> melodii = this->repofile.getAll();
	vector<Melodie> cautare_melodii;
	for (int i = 0; i < melodii.size(); i++)
	{
		if (melodii[i].getDenumire() == denumire)
			cautare_melodii.push_back(melodii[i]);
	}
	return cautare_melodii;
	 
}

vector<Melodie> Service::filtrare_gen(string gen)
{
	//metoda 1
	vector<Melodie> filteredmelodii1;
	

	//for (int i = 0; i < this->repofile.getAll().size(); i++)
	//{
	//	Melodie melodie = this->repofile.getAll()[i];
	//	if (melodie.getGen() == gen)
	//		filteredmelodii.push_back(melodie);
	//}
	//return filteredmelodii1;
	//----------------------

	//metoda 2 cu copy if
	vector<Melodie> melodii = this->repofile.getAll();
	vector<Melodie> filteredmelodii2;
	copy_if(melodii.begin(), melodii.end(), back_inserter(filteredmelodii2), [gen](Melodie m) {return m.getGen() == gen; });
	return filteredmelodii2;

	
}

vector<Melodie> Service::durata_min_max(int min, int max)
{
	vector<Melodie> melodii = this->repofile.getAll();
	vector<Melodie> cautare_melodii;
	for (int i = 0; i < melodii.size(); i++)
	{
		if (melodii[i].getDurata() >= min && melodii[i].getDurata() <= max)
			cautare_melodii.push_back(melodii[i]);
	}
	return cautare_melodii;
}

vector<Melodie> Service::sortare_durata()
{
	vector<Melodie> copie = this->getAll();
	sort(copie.begin(), copie.end(), [](Melodie m1, Melodie m2) {return m1.getDurata() < m2.getDurata(); });
	return copie;
}

vector<Melodie> Service::sortare_denumire(bool ascending)
{
	 vector<Melodie> copie = this->getAll();
	if (ascending)
		sort(copie.begin(), copie.end(), [](Melodie m1, Melodie m2) {return m1.getDenumire() < m2.getDenumire(); });
	else
		sort(copie.begin(), copie.end(), [](Melodie m1, Melodie m2) {return m1.getDenumire() > m2.getDenumire(); });
	return copie;
}

//sorteaza dupa cantaret, iar daca cantaretul e acelasi, dupa denumire
vector<Melodie> Service::sortare_cantaret_denumire()
{
	vector<Melodie> copie = this->getAll();
	sort(copie.begin(), copie.end(), [](Melodie m1, Melodie m2) {return m1.getCantaret() < m2.getCantaret() || (m1.getCantaret() == m2.getCantaret() && m1.getDenumire() < m2.getDenumire()); });
	return copie;
}

//functie ce numara pentru fiecare cantaret numarul de melodii si face un pair cu numele cantaretului si numarul de melodii
vector<Melodie> Service::numar_de_melodii_cantaret()
{
	vector<Melodie> melodii = this->repofile.getAll();
	vector<Melodie> numar_melodii_cantaret;
	vector<string> cantareti;

	for (int i = 0; i < melodii.size(); i++)
	{
		string cantaret = melodii[i].getCantaret();
		if (find(cantareti.begin(), cantareti.end(), cantaret) == cantareti.end())
		{
			cantareti.push_back(cantaret);
			int nr = 0;
			for (int j = 0; j < melodii.size(); j++)
			{
				if (melodii[j].getCantaret() == cantaret)
					nr++;
			}
			Melodie m("", cantaret, "", nr);
			numar_melodii_cantaret.push_back(m);
		}
	}
	return numar_melodii_cantaret;
}

vector<pair<string, string>> Service::vizualizare_per_gen()
{
	map<string, string> melodii_per_gen;
	vector<Melodie> melodii = this->repofile.getAll();
	for (int i = 0; i < melodii.size(); i++)
	{
		string gen = melodii[i].getGen();
		if (melodii_per_gen.find(gen) == melodii_per_gen.end())
			melodii_per_gen[gen] = melodii[i].getDenumire();
		else
			melodii_per_gen[gen] = melodii_per_gen[gen] + ", " + melodii[i].getDenumire();
	}
	vector<pair<string, string>> rez;
	for (auto it = melodii_per_gen.begin(); it != melodii_per_gen.end(); it++)
		rez.push_back(make_pair(it->first, it->second));
	return rez;
}

//genereaza nr melodii random
void Service::generare_random(int nr)
{

}

 

vector<Melodie> Service::afisare_melodii_sub_4_minute()
{
	vector<Melodie> melodii;
	for (int i = 0; i < this->repofile.getAll().size(); i++)
	{
		Melodie m= this->repofile.getAll()[i];
		if (m.getDurata() < 4)
			melodii.push_back(m);
	}
	return melodii;	
}
 


 