#include "repofile.h"
#include <fstream>
#include <sstream>


void RepoFile::loadfromfile()
{
	ifstream f(this->filename);
	if (f.is_open())
	{
		string line;
		while (getline(f, line))
		{
			stringstream ss(line);
			string nota_str, nume, materie, data;
			getline(ss, nota_str, ',');
			getline(ss, nume, ',');
			getline(ss, materie, ',');
			getline(ss, data, ',');

			int nota = stoi(nota_str);
			
			this->addc(new Catalog(nota, nume, materie, data));
		}
		f.close();
	}

}

void RepoFile::savetofile()
{

	ofstream f(this->filename);
	if (f.is_open())
	{
		const auto& cataloage = this->get_all();
		for (const auto& catalog : cataloage) {
			f << catalog->get_nota() << ',' << catalog->get_nume_elev() << ',' << catalog->get_nume_materie() << ',' << catalog->get_data() << '\n';
		}
		f.close();
	}
}

RepoFile::RepoFile(string filename)
{
	this->filename = filename;
	this->loadfromfile();
}

RepoFile::~RepoFile()
{
	for (int i = 0; i < this->cataloage.size(); i++)
		delete this->cataloage[i];
}

int RepoFile::size()
{
	return this->cataloage.size();
}

vector<Catalog*> RepoFile::get_all()
{
	return this->cataloage;
}

Catalog* RepoFile::get_at(int pos)
{
	if (pos < 0 || pos > this->cataloage.size())
		return nullptr;
	return this->cataloage[pos];
}

Catalog* RepoFile::find(string nume_elev)
{
	for (int i = 0; i < this->cataloage.size(); i++)
	{
		if (this->cataloage[i]->get_nume_elev() == nume_elev)
		{ 
			return this->cataloage[i];
		}
	}
	return nullptr;
}

void RepoFile::addc(Catalog* c)
{
	this->cataloage.push_back(c);
	this->savetofile();
}

void RepoFile::updatec(Catalog* cvechi, Catalog* cnou)
{
}

void RepoFile::deletec(Catalog* c)
{
}
