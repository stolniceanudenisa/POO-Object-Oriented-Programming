#include "Teste.h"
#include "produs.h"
#include "Repo.h"
#include <assert.h>
//#include "RepoException.h"

//void TestRepo::testGetAll()
//{
//	Repo repo;
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		repo.addProdus(this->produse[i]);
//	}
//
//	vector<Produs*> produse = repo.getAll();
//	assert(produse.size() == this->produse.size());
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		assert(*produse[i] == *this->produse[i]);
//	}
//}
//
//void TestRepo::testGetSize()
//{
//	Repo repo;
//	assert(repo.getSize() == 0);
//
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		repo.addProdus(this->produse[i]);
//	}
//
//	assert(repo.getSize() == this->produse.size());
//}

//void TestRepo::testGet()
//{
//	Repo repo;
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		repo.addProdus(this->produse[i]);
//	}
//
//	vector<Produs*> produse = repo.getAll();
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		assert(*repo.get(i) == *this->produse[i]);
//	}
//
//	try
//	{
//		repo.get(-1);
//		assert(false);
//	}
//	catch (RepoException& e)
//	{
//	}
//	catch (...)
//	{
//		assert(false);
//	}
//
//	try
//	{
//		repo.get(repo.getSize());
//		assert(false);
//	}
//	catch (RepoException& e)
//	{
//	}
//	catch (...)
//	{
//		assert(false);
//	}
//
//}
//
//void TestRepo::testFind()
//{
//	Repo repo;
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		repo.addProdus(this->produse[i]);
//	}
//
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		assert(repo.find(this->produse[i]) == i);
//	}
//
//	//ProdusDulce* pd = new ProdusDulce("briosa", 6, "capsuni");
//	//assert(repo.find(pd) == -1);
//}
//
//void TestRepo::testAddProdus()
//{
//	Repo repo;
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		repo.addProdus(this->produse[i]);
//	}
//
//	//ProdusDulce* pd = new ProdusDulce("briosa", 6, "capsuni");
//	repo.addProdus(pd);
//	assert(repo.getSize() == this->produse.size() + 1);
//	assert(*repo.get(repo.getSize() - 1) == *pd);
//	try {
//		repo.addProdus(pd);
//	}
//	catch (RepoException e) {}
//	catch (...)
//	{
//		assert(false);
//	}
//}
//
//void TestRepo::testUpdateProdus()
//{
//	Repo repo;
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		repo.addProdus(this->produse[i]);
//	}
//
//	//ProdusDulce* pNou = new ProdusDulce("briosa", 6, "capsuni");
//	//ProdusDulce* pNou2 = new ProdusDulce("napolitane", 3, "vanilie");
//	//repo.updateProdus(this->produse[1], pNou);
//	///assert(repo.find(this->produse[1]) == -1);
//	//assert(repo.find(pNou) != -1);
//	try {
//		//repo.updateProdus(this->produse[1], pNou2);
//	}
//	catch(RepoException e) {}
//	catch (...)
//	{
//		assert(false);
//	}
//	//assert(repo.find(pNou) != -1);
//	//assert(repo.find(pNou2) == -1);
//}
//
//void TestRepo::testDeleteProdus()
//{
//	Repo repo;
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		repo.addProdus(this->produse[i]);
//	}
//
//	repo.deleteProdus(this->produse[0]);
//	assert(repo.getSize() == 1);
//	assert(repo.find(this->produse[1]) != -1);
//
//	//ProdusDulce* p = new ProdusDulce("briosa", 6, "capsuni");
//	try {
//		repo.deleteProdus(p);
//	}
//	catch (RepoException e) {}
//	catch (...)
//	{
//		assert(false);
//	}
//
//	assert(repo.getSize() == 1);
//	assert(repo.find(this->produse[1]) != -1);
//}
//
//TestRepo::TestRepo()
//{
//	//ProdusDulce* p1 = new ProdusDulce("banane", 3, "fara");
//	//ProdusSarat* p2 = new ProdusSarat("chipsuri", 5, 10);
//	this->produse.push_back(p1);
//	this->produse.push_back(p2);
//}
//
//TestRepo::~TestRepo()
//{
//	for (int i = 0; i < this->produse.size(); i++)
//	{
//		delete this->produse[i];
//		this->produse[i] = NULL;
//	}
//	this->produse.clear();
//}
//
//void TestRepo::testAll()
//{
//	this->testGetAll();
//	this->testGetSize();
//	this->testGet();
//	this->testFind();
//	this->testAddProdus();
//	this->testUpdateProdus();
//	this->testDeleteProdus();
//}
