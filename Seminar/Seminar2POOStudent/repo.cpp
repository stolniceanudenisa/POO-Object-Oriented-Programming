#include "Repo.h"

Repo::Repo() 
{
	this->noStudents = 0;
}

Repo::~Repo() 
{
}

void Repo::addItem(Student& s) 
{
	this->students[this->noStudents++] = s;
}


Student Repo::getItemFromPos(int pos) 
{
	return this->students[pos];
}


int Repo::getSize() 
{
	return this->noStudents;
}