

#include "teste.h"
#include "validator.h"
#include "repo.h"
#include "service.h"
#include "exceptii.h"

void Teste::testdomain()
{
	Rochie r;

	Rochie r1(1, "rochie1", "M", "alba", 2, 50, "True");
	assert(r1.get_id() == 1);
	assert(r1.get_denumire() == "rochie1");
	assert(r1.get_marime() == "M");
	assert(r1.get_culoare() == "alba");
	assert(r1.get_nr_disponibile() == 2);
	assert(r1.get_pret() == 50);
	assert(r1.get_personalizare() == "True");

	

	Rochie r2(r1);
	assert(r2.get_id() == 1);
	assert(r2.get_denumire() == "rochie1");
	assert(r2.get_marime() == "M");
	assert(r2.get_culoare() == "alba");
	assert(r2.get_nr_disponibile() == 2);
	assert(r2.get_pret() == 50);
	assert(r2.get_personalizare() == "True");

	r2.set_nr_disponibile(3);
	assert(r2.get_nr_disponibile() == 3);


	//test bool operator
	
	assert(r1 == r1);
	assert(r2 == r2);
	assert(!(r1 == r));
	assert(!(r2 == r));


}
 

void Teste::testrepo()
{
	Validator validator;
	RepoFile repo("test.txt", validator);
	assert(repo.getAll()[0].get_id() == 1);
	assert(repo.getAll().size() == 10);
	assert(repo.find(1) == 1);
}

void Teste::testservice()
{
	Validator validator;
	RepoFile repo("test.txt", validator);
	Service service(repo, validator);
	assert(service.getAll()[0].get_id() == 1);
	assert(service.getAll().size() == 10);
	assert(service.afisare_rochii_marime("S","False").size() == 2);
	
	//assert cu try catch pentru afisare_rochii_marime
	try
	{
		service.afisare_rochii_marime("a", "a");
		assert(false);
	}
	catch (ValidationException&e)
	{
		assert(true);
	}
	catch (...)
	{
		assert(false);
	}


	assert(service.cumparare_rochie(1).size() ==1);
	assert(service.cumparare_rochie(1)[0].get_nr_disponibile() == 1);
	assert(service.cumparare_rochie(1)[0].get_id() == 1);
	assert(service.cumparare_rochie(1)[0].get_denumire() == "rochie1");
	assert(service.cumparare_rochie(1)[0].get_marime() == "M");
	//test cu try catch pentru cumparare_rochie
	try
	{
		service.cumparare_rochie(100);
		assert(false);
	}
	catch (ValidationException& e)
	{
		assert(true);
	}
	catch (...)
	{
		assert(false);
	}
	 
	assert(service.top_3_rochii_ieftine().size()==3);
}

void Teste::testvalidator()
{
	Validator validator;
	Rochie r1(1, "rochie1", "M", "alba", 2, 50, "True");
	try {
		validator.validate(r1);
	}
	catch (...)
	{
		assert(false);
	}
	Rochie m2(1, "", "", "", 2, 50, "");
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
}

