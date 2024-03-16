#include "teste.h"

void Teste::testdomain()
{
	Melodie m;

	Melodie m1("Dor de tine", "Vescan", "Rap", 3);
	assert(m.getDenumire() == "");
	assert(m.getCantaret() == "");
	assert(m.getGen() == "");
	assert(m.getDurata() == 0);

	assert(m1.getDenumire() == "Dor de tine");
	assert(m1.getCantaret() == "Vescan");
	assert(m1.getGen() == "Rap");
	
	Melodie m2(m1);
	assert(m2.getDenumire() == "Dor de tine");
	assert(m2.getCantaret() == "Vescan");
	assert(m2.getGen() == "Rap");
	assert(m2.getDurata() == 3);


	//test bool operator
	assert(m1 == m2);
	assert(m1 == m1);
	assert(m2 == m2);
	assert(!(m1 == m));
	assert(!(m2 == m));


}

void Teste::testrepo()
{
	Validator validator;
	RepoFile repo("test.txt", validator);
	 
	assert(repo.getAll()[0].getDenumire() == "clairedelune");

	repo.addmelodie(Melodie("dd", "Vescan", "Rap", 3));
	
	Melodie m1("dd", "Vescan", "Rap", 3);
	repo.deletemelodie(m1);


	assert(repo.getAll().size() == 9);
	assert(repo.find("Dordetine") == -1);

	repo.updatemelodie(Melodie("clairedelune", "Vescan", "Rap", 3));
	assert(repo.getAll()[0].getDenumire() == "clairedelune");
}

void Teste::testservice()
{
	Validator validator;
	RepoFile repo("test.txt", validator);
	Service service(repo);
	assert(service.getAll()[0].getDenumire() == "clairedelune");
	service.addmelodie("uu", "Vescan", "Rap", 3);
	assert(service.getAll().size() == 10);
	service.deletemelodie("uu");
	assert(service.getAll().size() == 9);
	service.updatemelodie("clairedelune", "Vescan", "Rap", 3);
	assert(service.getAll()[0].getDenumire() == "clairedelune");

	assert(service.filtrare_gen("Rap").size() == 1);
	assert(service.filtrare_gen("Rap")[0].getDenumire() == "clairedelune");
	assert(service.sortare_durata()[0].getDenumire() == "aeroplane");
	assert(service.sortare_denumire(true)[0].getDenumire() == "a");
	assert(service.sortare_denumire(false)[0].getDenumire() == "mandwozky");
	assert(service.afisare_melodii_sub_4_minute().size() == 5);
	//assert(service.sortare_cantaret_denumire()[0].getCantaret() == "b");

}

void Teste::testvalidator()
{
	Validator validator;
	Melodie m1("a","b", "c", 3);
	try {
		validator.validate(m1);
	}
	catch (...)
	{
		assert(false);
	}
	Melodie m2("", "b", "c", -3);
	try {
		validator.validate(m2);
		assert(false);
	}
	catch (ValidationException& e)
	{
		assert(true);
	}

}

void Teste::run_all()
{
	testdomain();
	testrepo();
	testservice();
	testvalidator();
}
