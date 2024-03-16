#include "repofile.h"

Repofile::Repofile(string filename, Validator validator)
{
	this->filename = filename;
	this->validator = validator;
	this->load_from_file();
}

Repofile::~Repofile()
{
}

void Repofile::load_from_file()
{
	this->meciuri.clear();

	ifstream fisier(this->filename);
	if (!fisier.is_open())
		throw exception("Nu s a putut deschide fisierul");

	string numeechipa1, numeechipa2;
	int scor1, scor2;
	while (fisier >> numeechipa1 >> numeechipa2 >> scor1 >> scor2) {

		if (fisier.fail())
			throw exception("Eroare la citire");

		Meci meci( numeechipa1,numeechipa2,scor1,scor2 );
		this->meciuri.push_back(meci);

	}
}
//sau
//
//ifstream f(this->filename);
//if (f.is_open())
//{
//	string line;
//	while (getline(f, line))
//	{
//		stringstream ss(line);
//		string nota_str, nume, materie, data;
//		getline(ss, nota_str, ',');
//		getline(ss, nume, ',');
//		getline(ss, materie, ',');
//		getline(ss, data, ',');
//
//		int nota = stoi(nota_str);
//
//		this->addc(new Catalog(nota, nume, materie, data));
//	}
//	f.close();
//}




void Repofile::save_to_file()
{
	std::ofstream fisier(filename);
	/*if (!fisier.is_open()) {
		throw RepositoryException("Nu se poate deschide fisierul pentru scriere.\n");
	}*/
	vector<Meci> nou = this->get_all();
	for (auto& activitate : nou)   // sau for (int i=0;i< meciuri.size();i++)
{
		fisier << activitate.get_echipa1() << ' ';
		fisier << activitate.get_echipa2() << ' ';
		fisier << activitate.get_scor1() << ' ';
		fisier << activitate.get_scor2() << '\n';
	}
}



vector<Meci> Repofile::get_all()
{
	return this->meciuri;
}

void Repofile::addmeci(Meci m)
{
	this->validator.validate(m);
	if (find(m.get_echipa1())==1)
		throw invalid_argument("Meciul deja exista!");
	this->meciuri.push_back(m);
	this->save_to_file();
}

void Repofile::deletemeci(Meci m)
{
	if (find(m.get_echipa1()) == -1)
		throw invalid_argument("Meciul nu exista!");
	for (int i = 0; i < this->meciuri.size(); i++)
	{
		if (this->meciuri[i].get_echipa1() == m.get_echipa1())
		{
			
			this->meciuri.erase(this->meciuri.begin() + i);
			
		}
	}

	this->save_to_file();
}

//completeaza functia
void Repofile::updatemeci(Meci m)
{
 		 

	this->save_to_file();
}

int Repofile::find(string numeechipa1)
{
	for (int i = 0; i < this->meciuri.size(); i++)
	{
		if (this->meciuri[i].get_echipa1() == numeechipa1)
			return 1;
	}
	return -1;
}

int Repofile::find_meci(Meci meci)
{
	for (int i = 0; i < meciuri.size(); i++)
	{
		if (this->meciuri[i] == meci)
		{
			return i;
		}
	}
	return -1;
}
