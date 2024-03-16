#include "Teste.h"
#include <assert.h>
#include <iostream>
#include <fstream>
#include "produs.h"
 


void TestProdus::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	 
	this->testGetNume();
	this->testSetNume();
	this->testGetPret();
	this->testSetPret();
	//this->testAssignmentOperator();
	//this->testEqualityOperator();
	this->testToString();
}

void TestProdus::testImplicitConstructor()
{
	Produs p;
	assert(p.getCod() == 0);
	assert(p.getNume().empty());
	assert(p.getPret() == 0);
	assert(p.getNraparitii() == 0);
}

void TestProdus::testConstructorWithParameters()
{
	Produs p(77,"cioco", 12, 2);
	assert(p.getCod() == 77);
	assert(p.getNume() == "cioco");
	assert(p.getPret() == 12);
	assert(p.getNraparitii() == 2);
}

void TestProdus::testCopyConstructor()
{
	Produs p1(77, "cioco", 12,2);
	Produs p2(p1);
	assert(p2.getCod() == p1.getCod());
	assert(p2.getNume() == p1.getNume());
	assert(p2.getPret() == p1.getPret());
	assert(p2.getNraparitii() == p1.getNraparitii());
}

void TestProdus::testGetCod()
{
	Produs p(77, "cioco", 12, 2);
	assert(p.getCod() == 77);
}

void TestProdus::testSetCod()
{
	Produs p;
	p.setPret(55);
	assert(p.getCod() == 55);
}


void TestProdus::testGetNume()
{
	Produs p(77, "cioco", 12, 2);
	assert(p.getNume() == "cioco");
}

void TestProdus::testSetNume()
{
	Produs p;
	p.setNume("afine");
	assert(p.getNume() == "afine");
}

void TestProdus::testGetPret()
{
	Produs p(77, "cioco", 12, 2);
	assert(p.getPret() == 12);
}

void TestProdus::testSetPret()
{
	Produs p;
	p.setPret(3);
	assert(p.getPret() == 3);
}

//void TestProdus::testAssignmentOperator()
//{
//	Produs p1(77, "cioco", 12);
//	Produs p2;
//	p2 = p1;
//	assert(p2.getCod() == p1.getCod());
//	assert(p2.getNume() == p1.getNume());
//	assert(p2.getPret() == p1.getPret());
//}
//
//void TestProdus::testEqualityOperator()
//{
//	Produs p1(77, "cioco", 12);
//	Produs p2 = p1;
//	assert(p1 == p2);
//	p2.setNume("briosa");
//	assert(!(p1 == p2));
//	p2.setNume(p1.getNume());
//	assert(p1 == p2);
//	p2.setPret(10);
//	assert(!(p1 == p2));
//	p2.setPret(p1.getPret());
//	assert(p1 == p2);
//}

void TestProdus::testToString()
{
	//Produs p("banane", 3);
	//assert(p.toString() == "banane 3");
}

//
//void TestProdus::testAdaugaRepoFile()
//{
//	ofstream f("testProduse.txt");
//	f.close();
//	RepoFile repo("testProduse.txt");
//	//RepoFile repo("testProduse.txt", new ValidatorProdusDulce());
//
//	repo.addProdus(new Produs(12, "clatita", 25));
//
//	ifstream g("testProduse.txt");
//	string linie;
//	g >> linie;
//	assert(linie == "12,clatita,25");
//}