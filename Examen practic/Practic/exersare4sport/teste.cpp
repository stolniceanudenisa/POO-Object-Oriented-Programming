#include "teste.h"


//test delete repo si service
//test update repo si service
//test sortare repo si service
//test filtrare repo si service





void Teste::testdomain()
{

	Meci m;
	assert(m.get_echipa1().empty());
	assert(m.get_echipa2().empty());
	assert(m.get_scor1() == 0);
	assert(m.get_scor2() == 0);

	//test constructor cu parametri
	Meci m1("a", "b", 1, 2);
	assert(m1.get_echipa1() == "a");
	assert(m1.get_echipa2() == "b");
	assert(m1.get_scor1() == 1);
	assert(m1.get_scor2() == 2);

	//test copy constructor

	Meci m2(m1);
	assert(m2.get_echipa1() == "a");
	assert(m2.get_echipa2() == "b");
	assert(m2.get_scor1() == 1);
	assert(m2.get_scor2() == 2);

	//nu am test setteri nu am nevoie
	//nu am test operator nu am nevoie


}

void Teste::testrepo()
{
	//string filename = "test.txt";
	Validator validator;
	Repofile repo("meci.txt", validator);
	assert(repo.get_all().size() == 5);
	assert(repo.get_all()[0].get_echipa1() == "steaua");

	//Meci m("aa", "bb", 4, 4);
	//repo.addmeci(m);
	//assert(repo.get_all().size() == 5);
}

void Teste::testservice()
{
	Validator validator;
	Repofile repo("meci.txt", validator);
	Service service(repo);
	assert(repo.get_all().size() == 5);
	assert(repo.get_all()[0].get_echipa1() == "steaua");
	assert(repo.get_all()[0].get_echipa2() == "dinamo");

	assert(service.sortare_scor1()[0].get_scor1() == 0);

	//test clasament
	assert(service.clasament2()[0].get_echipa1() == "cluj");
	assert(service.clasament2()[0].get_echipa2() == "bc");
	assert(service.clasament2()[0].get_scor1() == 3);
	assert(service.clasament2()[0].get_scor2() == 0);


	//test la functia din service updatemecis
	service.updatemecis("steaua", "dinamo", 1, 1);
	assert(service.get_all()[0].get_scor1() == 1);
	assert(service.get_all()[0].get_scor2() == 1);
		
}

void Teste::testvalidator()
{
	Validator validator;
	Meci m1("a", "b", 1, 1);
	try {
		validator.validate(m1);
	}
	catch (...)
	{
		assert(false);
	}
	Meci m2("a", "b", -1, -1);
	try {
		validator.validate(m1);
		//assert(false);
	}
	catch (ValidationException& e) {}
	catch (...) {
		assert(false);
	}
}

void Teste::run_all()
{
	testdomain();
	testrepo();
	testservice();
	testvalidator();
}
