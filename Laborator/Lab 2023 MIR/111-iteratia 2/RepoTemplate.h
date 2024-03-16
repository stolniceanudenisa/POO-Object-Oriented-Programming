#pragma once
#include "Student.h"
#include <vector>

using namespace std;

template <class T>
class RepoTemplate {
private:
	vector<T> studenti;
	char* fileName;
public:
	RepoTemplate();
	RepoTemplate(const char* fileName);
	~RepoTemplate();

	vector<T> getAll();
	int getLength();

	void addElem(const T& st);
	void updateElem(const T& oldSt, const T& newSt);
	void deleteElem(const T& st);
private:
	void loadFromFile();
	void saveToFile();
};

template <class T>
RepoTemplate<T>::RepoTemplate()
{
	this->fileName = NULL;
}

template <class T>
RepoTemplate<T>::RepoTemplate(const char* fileName)
{
	if (fileName != NULL)
	{
		this->fileName = new char[strlen(fileName) + 1];
		strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
	}
	else
	{
		this->fileName = NULL;
	}
	this->loadFromFile();
}

template<class T>
RepoTemplate<T>::~RepoTemplate()
{
	if (this->fileName != nullptr)
	{
		delete[]this->fileName;
		this->fileName = NULL;
	}
}

template <class T>
vector<T> RepoTemplate<T>::getAll()
{
	return this->studenti;
}

template <class T>
int RepoTemplate<T>::getLength()
{
	return this->studenti.size();
}

template <class T>
void RepoTemplate<T>::addElem(const T& st)
{
	this->studenti.push_back(st);
	this->saveToFile();
}

template <class T>
void RepoTemplate<T>::updateElem(const T& oldSt, const T& newSt)
{
	// modalitatea 1
	//for (int i = 0; i < this->studenti.size(); i++)
	//{
	//	if (this->studenti[i] == oldSt)
	//	{
	//		this->studenti[i] = newSt;
	//	}
	//}

	typename vector<T>::iterator it;
	// modalitatea 2
	/*for (it = this->studenti.begin(); it != this->studenti.end(); it++)
	{
		if (*it == oldSt)
		{
			*it = newSt;
		}
	}*/

	// modalitatea 3
	it = find(this->studenti.begin(), this->studenti.end(), oldSt);
	// nu s-a gasit niciun student egal cu oldSt
	if (it != this->studenti.end())
	{
		*it = newSt;
	}
	this->saveToFile();
}

template <class T>
void RepoTemplate<T>::deleteElem(const T& st)
{
	typename vector<T>::iterator it = find(this->studenti.begin(), this->studenti.end(), st);
	if (it != this->studenti.end())
	{
		this->studenti.erase(it);
	}
	this->saveToFile();
}

template <class T>
void RepoTemplate<T>::loadFromFile()
{
	if (this->fileName)
	{
		ifstream f(this->fileName);
		T element;
		while (!f.eof())
		{
			f >> element;
			if (!(element == T()))
			{
				this->addElem(element);
			}
		}
		f.close();
	}
}

template <class T>
void RepoTemplate<T>::saveToFile()
{
	if (this->fileName)
	{
		ofstream f(this->fileName);
		for (int i = 0; i < this->studenti.size();i++)
		{
			f << this->studenti[i] << endl;
		}
	}
}