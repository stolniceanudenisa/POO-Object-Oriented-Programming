//#include "TestService.h"
//#include <assert.h>
//#include "Service.h"
//#include "ProdusDulce.h"
//#include "ProdusSarat.h"
//#include "RepoException.h"
//#include <vector>
//#include "Repo.h"
//
//void TestService::testGetAll()
//{
//	Repo* repo = new Repo();
//	Service serv(repo);
//
//	ProdusDulce* p1 = new ProdusDulce("banane", 3, "fara");
//	ProdusSarat* p2 = new ProdusSarat("chipsuri", 5, 10);
//	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getGlazura());
//	serv.addProdusSarat(p2->getNume(), p2->getPret(), p2->getCantitateSare());
//	vector<Produs*> produse = serv.getAll();
//	assert(*produse[0] == *p1);
//	assert(*produse[1] == *p2);
//}
//
//void TestService::testAddProdusDulce()
//{
//	Repo* repo = new Repo();
//	Service serv(repo);
//
//	ProdusDulce* pd1 = new ProdusDulce("banane", 3, "fara");
//	serv.addProdusDulce(pd1->getNume(), pd1->getPret(), pd1->getGlazura());
//	assert(*serv.getAll()[0] == *pd1);
//}
//
//void TestService::testAddProdusSarat()
//{
//	Repo* repo = new Repo();
//	Service serv(repo);
//
//	ProdusSarat* ps1 = new ProdusSarat("chipsuri", 3, 20);
//	serv.addProdusSarat(ps1->getNume(), ps1->getPret(), ps1->getCantitateSare());
//	assert(*serv.getAll()[0] == *ps1);
//}
//
//void TestService::testUpdateProdusDulce()
//{
//	Repo* repo = new Repo();
//	Service serv(repo);
//
//	ProdusDulce* p1 = new ProdusDulce("banane", 3, "fara");
//	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getGlazura());
//	ProdusDulce* p2 = new ProdusDulce("briosa", 5, "capsuni");
//	ProdusDulce* p3 = new ProdusDulce("napolitane", 5, "vanilie");
//	serv.updateProdusDulce(p1->getNume(), p2->getNume(), p2->getPret(), p2->getGlazura());
//	assert(*serv.getAll()[0] == *p2);
//	try {
//		serv.updateProdusDulce(p3->getNume(), p2->getNume(), p2->getPret(), p2->getGlazura());
//		assert(false);
//	}
//	catch (RepoException& e) {
//	}
//	catch (...) {
//		assert(false);
//	}
//}
//
//void TestService::testUpdateProdusSarat()
//{
//	Repo* repo = new Repo();
//	Service serv(repo);
//
//	ProdusSarat* p1 = new ProdusSarat("chipsuri", 3, 12);
//	serv.addProdusSarat(p1->getNume(), p1->getPret(), p1->getCantitateSare());
//	ProdusSarat* p2 = new ProdusSarat("covrigi", 2, 8);
//	ProdusSarat* p3 = new ProdusSarat("saratele", 5, 20);
//	serv.updateProdusSarat(p1->getNume(), p2->getNume(), p2->getPret(), p2->getCantitateSare());
//	assert(*serv.getAll()[0] == *p2);
//	try {
//		serv.updateProdusSarat(p3->getNume(), p2->getNume(), p2->getPret(), p2->getCantitateSare());
//		assert(false);
//	}
//	catch (RepoException& e) {
//	}
//	catch (...) {
//		assert(false);
//	}
//}
//
//void TestService::testDeleteProdus()
//{
//	Repo* repo = new Repo();
//	Service serv(repo);
//
//	ProdusDulce* p1 = new ProdusDulce("banane", 3, "fara");
//	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getGlazura());
//	serv.deleteProdus("napolitane");
//	vector<Produs*> produse = serv.getAll();
//	assert(produse.size() == 1);
//	serv.deleteProdus(p1->getNume());
//	produse = serv.getAll();
//	assert(produse.size() == 0);
//}
//
//void TestService::testFilterByPrice()
//{
//	Repo* repo = new Repo();
//	Service serv(repo);
//
//	ProdusDulce* p1 = new ProdusDulce("banane", 5, "fara");
//	ProdusSarat* p2 = new ProdusSarat("covrigi", 20, 8);
//	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getGlazura());
//	serv.addProdusSarat(p2->getNume(), p2->getPret(), p2->getCantitateSare());
//
//	vector<Produs*> filterResult = serv.filterByPrice(0, 4);
//	assert(filterResult.size() == 0);
//	filterResult = serv.filterByPrice(30, 40);
//	assert(filterResult.size() == 0);
//	filterResult = serv.filterByPrice(4, 7);
//	assert(filterResult.size() == 1);
//	assert(*filterResult[0] == *p1);
//	filterResult = serv.filterByPrice(10, 28);
//	assert(filterResult.size() == 1);
//	assert(*filterResult[0] == *p2);
//	filterResult = serv.filterByPrice(2, 44);
//	assert(filterResult.size() == 2);
//	assert(*filterResult[0] == *p1);
//	assert(*filterResult[1] == *p2);
//}
//
//void TestService::testSortByName()
//{
//	Repo* repo = new Repo();
//	Service serv(repo);
//
//	ProdusDulce* p1 = new ProdusDulce("covrigi", 5, "fara");
//	ProdusSarat* p2 = new ProdusSarat("banane", 20, 8);
//	ProdusDulce* p3 = new ProdusDulce("ciocolata", 5, "fara");
//	serv.addProdusDulce(p1->getNume(), p1->getPret(), p1->getGlazura());
//	serv.addProdusSarat(p2->getNume(), p2->getPret(), p2->getCantitateSare());
//	serv.addProdusDulce(p3->getNume(), p3->getPret(), p3->getGlazura());
//
//	vector<Produs*> filterResult = serv.sortByName();
//	assert(filterResult.size() == 3);
//	assert(*filterResult[0] == *p2);
//	assert(*filterResult[1] == *p3);
//	assert(*filterResult[2] == *p1);
//}
//
//TestService::TestService()
//{
//}
//
//TestService::~TestService()
//{
//}
//
//void TestService::testAll()
//{
//	this->testGetAll();
//	this->testAddProdusDulce();
//	this->testAddProdusSarat();
//	this->testUpdateProdusDulce();
//	this->testUpdateProdusSarat();
//	this->testDeleteProdus();
//
//	this->testFilterByPrice();
//	this->testSortByName();
//}
