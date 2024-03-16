#include "service.h"
#include <algorithm>

Service::Service(RepoFile& repo) : repo(repo)
{
	this->repo = repo;
}

vector<Profesor> Service::getAll()
{
	return this->repo.getAll();
}

void Service::addProfesor(string nume, string disciplina, string clase, string greva)
{
	Profesor p(nume, disciplina, clase, greva);
	this->repo.addProfesor(p);
}

Service::~Service()
{
}

int Service::nr_profesori_greva()
{
	int nr = 0;
	for (auto p : this->repo.getAll())
	{
		if(p.getGreva() == "da")
			nr++;
	}
	return nr;
}

vector<Profesor> Service::disciplina_cu_cei_mai_multi_profi_greva()
{
	vector<Profesor> profesori = this->repo.getAll();
	vector<Profesor> rez;
	int max = 0;
	for (auto p : profesori)
	{
		if (p.getGreva() == "da")
		{
			int nr = 0;
			for (auto q : profesori)
			{
				if (q.getDisciplina() == p.getDisciplina() && q.getGreva() == "da")
					nr++;
			}
			if (nr > max)
			{
				max = nr;
				rez.clear();
				rez.push_back(p);
			}
			else if (nr == max)
				rez.push_back(p);
		}
	}
	return rez;
}

vector<Profesor> Service::clasa_cu_cei_mai_multi_profi_greva()
{
	vector<Profesor> profesori = this->repo.getAll();
	vector<Profesor> rez;
	int max = 0;
	for (auto p : profesori)
	{
		if (p.getGreva() == "da")
		{
			int nr = 0;
			for (auto q : profesori)
			{
				if (q.getClase() == p.getClase() && q.getGreva() == "da")
					nr++;
			}
			if (nr > max)
			{
				max = nr;
				rez.clear();
				rez.push_back(p);
			}
			else if (nr == max)
				rez.push_back(p);
		}
	}
	return rez;
}