#include "Repo.h"
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include "RepoTemplate.h"

Repo::Repo()
{
	this->fileName = NULL;
}

Repo::Repo(const char* fileName)
{
	if (fileName != NULL)
	{
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
	}
	else
	{
		this->fileName = NULL;
	}
	this->loadFromFile();
}

Repo::~Repo()
{
	if (fileName != NULL)
	{
		delete []this->fileName;
		this->fileName = NULL;
	}
}

vector<Student> Repo::getAll()
{
	return this->studenti;
}

int Repo::getLength()
{
	return this->studenti.size();
}

void Repo::addElem(const Student& st)
{
	this->studenti.push_back(st);
	this->saveToFile();
}

void Repo::updateElem(const Student& oldSt, const Student& newSt)
{
	// modalitatea 1
	//for (int i = 0; i < this->studenti.size(); i++)
	//{
	//	if (this->studenti[i] == oldSt)
	//	{
	//		this->studenti[i] = newSt;
	//	}
	//}

	vector<Student>::iterator it;
	// modalitatea 2
	/*for (it = this->studenti.begin(); it != this->studenti.end(); it++)
	{
		if (*it == oldSt)
		{
			*it = newSt;
		}
	}*/

	// modalitatea 3
	it = find(this->studenti.begin(), this->studenti.end(), oldSt);
	// nu s-a gasit niciun student egal cu oldSt
	if (it != this->studenti.end())
	{
		*it = newSt;
	}
	this->saveToFile();
}

void Repo::deleteElem(const Student& st)
{
	vector<Student>::iterator it = find(this->studenti.begin(), this->studenti.end(), st);
	if (it != this->studenti.end())
	{
		this->studenti.erase(it);
	}
	this->saveToFile();
}

void Repo::loadFromFile()
{
	if (this->fileName)
	{
		ifstream f(this->fileName);
		char nume[20];
		int varsta;
		while (!f.eof())
		{
			f >> nume >> varsta;
			if (strlen(nume) > 0)
			{
				Student st(nume, varsta);
				this->addElem(st);
			}
		}
		f.close();
	}
}

void Repo::saveToFile()
{
	if (this->fileName)
	{
		ofstream f(this->fileName);
		for (int i = 0; i < this->studenti.size();i++)
		{
			f << this->studenti[i] << endl;
		}
	}
}