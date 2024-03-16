#include "service.h"
#include "validator.h"
#include "exceptii.h"
#include <algorithm>
#include <map>
 
/// <summary>
/// Constructor implicit
/// </summary>
/// <param name="repofile"></param> repo file
Service::Service(RepoFile& repofile, Validator validator) : repofile(repofile)
{
	this->repofile = repofile;
	this->validator = validator;
}


/// <summary>
/// Functie de get pentru toate rochiile
/// </summary>
/// <returns></returns> toate rochiile
vector<Rochie> Service::getAll()
{
	return repofile.getAll();
}

/// <summary>
/// aFISARE ROCHII DUPA MARIME SI PERSONALIZARE
/// </summary>
/// <param name="marime"></param>
/// <param name="personalizare"></param> personalizare
/// <returns></returns> rochiile cu marimea si personalizarea respectiva
vector<Rochie> Service::afisare_rochii_marime(string marime, string personalizare)
{
	//validare
	Rochie r(1, "a", marime, "a", 1, 1, personalizare);
	this->validator.validate(r);

	
	vector<Rochie> rochie = this->repofile.getAll();
	vector<Rochie> cautare_rochii;
	for (int i = 0; i < rochie.size(); i++)
	{
		if (rochie[i].get_marime() == marime && rochie[i].get_personalizare() == personalizare)
			cautare_rochii.push_back(rochie[i]);
	}
	return cautare_rochii;
}

/// <summary>
/// Gasire rochie dupa id
/// </summary>
/// <param name="id"></param> id-ul rochiei
void Service::find(int id)
{
	this->repofile.find(id);
}


/// <summary>
/// Cautare rochie dupa id
/// </summary>
/// <param name="id"></param> id-ul rochiei
/// <returns></returns> rochia cu id-ul respectiv
vector<Rochie> Service::cumparare_rochie(int id)
{
	vector<Rochie> rochie = this->repofile.getAll();
	vector<Rochie> cumparare_rochie;
	
	for (int i = 0; i < rochie.size(); i++)
	{
		if (rochie[i].get_nr_disponibile() == 0)
			throw invalid_argument("Ne pare rau, nu mai e in stoc!");
		else
		if (rochie[i].get_id() == id)
		{
			if (rochie[i].get_nr_disponibile() > 0)
			{
				rochie[i].set_nr_disponibile(rochie[i].get_nr_disponibile() - 1);
	
				 

				cumparare_rochie.push_back(rochie[i]);
				savetofileservice();
				return cumparare_rochie;
			} 
		}
	}
	
}

/// <summary>
///	Cele mai ieftine 3 rochii disponibile
/// </summary>
/// <returns></returns> cele mai ieftine 3 rochii disponibile
vector<pair<string, string>> Service::top_3_rochii_ieftine()
{
	vector<Rochie> rochie = this->repofile.getAll();
	vector<pair<string, string>> top_3;
	map<int, Rochie> map;
	for (int i = 0; i < rochie.size(); i++)
	{
		if (rochie[i].get_nr_disponibile() > 0)
			map.insert(pair<int, Rochie>(rochie[i].get_pret(), rochie[i]));
	}
	int i = 0;
	for (auto it = map.begin(); it != map.end() && i < 3; it++)
	{
		top_3.push_back(pair<string, string>(it->second.get_marime(), it->second.get_personalizare()));
		i++;
	}
	return top_3;

}

 






/// <summary>
/// Save to file service
/// </summary>
void Service::savetofileservice()
{
	this->repofile.savetofile();
}

void Service::find_rochie(int id)
{
	this->repofile.find(id);
}
