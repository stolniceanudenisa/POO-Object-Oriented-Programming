#include "service.h"

Service::Service(RepoFile& repo) : repo(repo)
{
	this->repo = repo;
}

Service::~Service()
{
}

vector<Catalog*> Service::get_all()
{
	vector<Catalog*> cataloage= this->repo.get_all();
	return cataloage;
}

void Service::adds(int nota, string nume, string materie, string data)
{
	Catalog* c = new Catalog(nota, nume, materie, data);
	this->repo.addc(c);
}

vector<Catalog*> Service::filter_interval(string ziuai, string ziuaf)
{
	return vector<Catalog*>();
	vector< Catalog*> cataloage = this->repo.get_all();
	vector< Catalog*> rezultat;
	for (Catalog* c : cataloage)
	{
		if (strcmp(c->get_data(), ziuai) == 0)
		{
			rezultat.push_back(c);


		}
		return rezultat;
}

 