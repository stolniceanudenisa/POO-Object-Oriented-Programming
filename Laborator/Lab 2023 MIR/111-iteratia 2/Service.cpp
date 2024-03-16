#include "Service.h"

Service::Service(Repo& repo) : repo(repo)
{
}

Service::~Service()
{
}

vector<Student> Service::getAll()
{
	return this->repo.getAll();
}

void Service::addStudent(const char* nume, int varsta)
{
	Student st(nume, varsta);
	this->repo.addElem(st);
}

void Service::updateVarstaDupaNume(const char* nume, int varstaNoua)
{
	Student studentNou(nume, varstaNoua);
	vector<Student> studenti = this->repo.getAll();
	for (int i = 0; i < this->repo.getLength(); i++)
	{
		if (strcmp(studenti[i].getNume(), nume) == 0)
		{
			this->repo.updateElem(studenti[i], studentNou);
		}
	}
}

void Service::deleteBetweenAges(int varstaMin, int varstaMax)
{
	for (int i = 0; i < this->repo.getLength(); i++)
	{
		int varsta = this->repo.getAll()[i].getVarsta();
		if (varstaMin <= varsta && varsta <= varstaMax)
		{
			this->repo.deleteElem(this->repo.getAll()[i]);
			i--;
		}
	}
}
