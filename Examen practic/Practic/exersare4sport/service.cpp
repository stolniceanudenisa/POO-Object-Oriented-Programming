#include "service.h"
#include <algorithm>

Service::Service(Repofile& repofile): repofile(repofile)
{
	this->repofile = repofile;
}

vector<Meci> Service::get_all()
{
	return repofile.get_all();
	
}

void Service::addmecis(string numeechipa1, string numeechipa2, int scor1, int scor2)
{
	Meci meci = Meci(numeechipa1, numeechipa2, scor1, scor2);
	this->repofile.addmeci(meci);
}

void Service::deletemecis(string numeechipa1)
{
    Meci meci(numeechipa1, "", 0, 0);
    this->repofile.deletemeci(meci);
}

// completeaza functia de update
void Service::updatemecis(string numeechipa1, string numeechipa2, int scor1, int scor2)
{
      Meci meci(numeechipa1, numeechipa2, scor1, scor2);
	this->repofile.updatemeci(meci);
}

//functie ce sorteaza meciurile dupa numele echipei 1






vector<Meci> Service::sortare_scor1()
{
	vector<Meci>copie = this->get_all();

	sort
	(copie.begin(), copie.end(), [](Meci m1, Meci m2)
	
	{ return m1.get_scor1() < m2.get_scor1(); }
	
	);

	return copie;
}

//

vector<Meci> Service::clasament2()
{
    vector<Meci> clasament;

    vector<Meci> meciuri = this->get_all();

    // Parcurgem fiecare meci si calculam punctajele
    for (auto& meci : meciuri) {
        int punctaj1 = 0;
        int punctaj2 = 0;

        // Calculam punctajul pentru prima echipa
        if (meci.get_scor1() > meci.get_scor2()) {
            punctaj1 = 3; // Echipa 1 a castigat
        }
        else if (meci.get_scor1() == meci.get_scor2()) {
            punctaj1 = 1; // Meciul a fost egal
        }

        // Calculam punctajul pentru a doua echipa
        if (meci.get_scor2() > meci.get_scor1()) {
            punctaj2 = 3; // Echipa 2 a castigat
        }
        else if (meci.get_scor2() == meci.get_scor1()) {
            punctaj2 = 1; // Meciul a fost egal
        }

        // Actualizam punctajele pentru meciurile din clasament
        Meci meci1(meci.get_echipa1(), meci.get_echipa2(), punctaj1, punctaj2);
        Meci meci2(meci.get_echipa2(), meci.get_echipa1(), punctaj2, punctaj1);
        clasament.push_back(meci1);
        clasament.push_back(meci2);
    }

    // Sortam clasamentul in ordine descrescatoare dupa punctaje
    sort(clasament.begin(), clasament.end(), []( Meci m1,  Meci m2) {
        return m1.get_scor1() + m1.get_scor2() > m2.get_scor1() + m2.get_scor2();
        });

    return clasament;
}
