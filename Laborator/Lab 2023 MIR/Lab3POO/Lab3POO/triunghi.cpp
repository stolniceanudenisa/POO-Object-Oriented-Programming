#include "Triunghi.h"
#include <stdlib.h>
#include <cmath>

Triunghi::Triunghi()
{
	this->latura1 = 0;
	this->latura2 = 0;
	this->latura3 = 0;
}

Triunghi::Triunghi(int latura1, int latura2,int latura3)
{
	this->latura1 = latura1;
	this->latura2 = latura2;
	this->latura3 = latura3;
}

Triunghi::Triunghi(const Triunghi& tr)
{
	this->latura1 = tr.latura1;
	this->latura2 = tr.latura2;
	this->latura3 = tr.latura3;
}

int Triunghi::getLatura1()
{
	return this->latura1;
}


int Triunghi::getLatura2()
{
	return this->latura2;
}


int Triunghi::getLatura3()
{
	return this->latura3;
}

void Triunghi::setLatura1(int latura1)
{
	this->latura1 = latura1;
}

void Triunghi::setLatura2(int latura2)
{
	this->latura2 = latura2;
}


void Triunghi::setLatura3(int latura3)
{
	this->latura3 = latura3;
}


int Triunghi::getArie()
{
	int sp = (latura1 + latura2 + latura3) / 2;
	return sqrt((sp * (sp - latura1) * (sp - latura2) * (sp - latura3)));

}


int Triunghi::getPerimetru()
{
	return latura1 + latura2 + latura3;

}


Triunghi& Triunghi::operator=(const Triunghi& tr)
{
	if (this != &tr)
	{
		this->setLatura1(tr.latura1);
		this->setLatura2(tr.latura2);
		this->setLatura3(tr.latura3);
	}
	return *this;
}

ostream& operator<<(ostream& os, const Triunghi& tr)
{
	os << tr.latura1;
	os << tr.latura2;
	os << tr.latura3;
	return os;
}








//Patrat::Patrat()
//{
//	this->latura = 0;
//}

//Patrat::Patrat(int latura)
//{
//	this->latura = latura;
//}


//Patrat::Patrat(const Patrat& pt)
//{
//	this->latura = pt.latura;
//}


//int Patrat::getLatura()
//{
//	return this->latura;
//}

//void Patrat::setLatura(int latura)
//{
//	this->latura = latura;
//}
//
//int Patrat::getArie()
//{
//	return latura*latura;
//}


//Patrat& Patrat::operator=(const Patrat& pt)
//{
//	if (this != &pt)
//	{
//		this->setLatura(pt.latura);
//	}
//	return *this;
//}
//
//ostream& operator<<(ostream& os, const Patrat& pt)
//{
//	os << pt.latura;
//	return os;
//}