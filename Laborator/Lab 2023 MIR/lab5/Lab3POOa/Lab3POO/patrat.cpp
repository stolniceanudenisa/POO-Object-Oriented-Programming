#include "Patrat.h"
#include <stdlib.h>

Patrat::Patrat()
{
	this->latura = 0;
}

Patrat::Patrat(int latura)
{
	this->latura = latura;
}


Patrat::Patrat(const Patrat& pt)
{
	this->latura = pt.latura;
}


int Patrat::getLatura()
{
	return this->latura;
}

void Patrat::setLatura(int latura)
{
	this->latura = latura;
}

int Patrat::getArie()
{
	return latura*latura;
}


Patrat& Patrat::operator=(const Patrat& pt)
{
	if (this != &pt)
	{
		this->setLatura(pt.latura);
	}
	return *this;
}

ostream& operator<<(ostream& os, const Patrat& pt)
{
	os << pt.latura;
	return os;
}