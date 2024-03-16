#pragma once

#include <assert.h>
#include <algorithm>
#include "Domain.h"

template<typename T>
class Repository
{
private:
	std::string file;
	std::vector<T> elems;

public:
	Repository() {}
	Repository(std::string f) :file(f) {}

	std::vector<T> getAll();
	std::vector<T>& getAllReference();

	void add(T el);
	void update(T update);
	void removeElem(T elem);
	void removePos(int pos);

	bool checkExisting(T elem);
	int positionOfElement(T elem);
	T elementOnPosition(int pos);

	void save() { this->saveFile(this->elems); }

private:
	void saveFile(std::vector<T> elems);
	std::vector<T> loadFile();
};




template<typename T>
inline std::vector<T> Repository<T>::getAll()
{
	std::vector<T> elems = this->loadFile();
	return elems;
}

template<typename T>
inline std::vector<T>& Repository<T>::getAllReference()
{
	this->elems = this->loadFile();
	return this->elems;
}

template<typename T>
inline void Repository<T>::add(T el)
{
	std::vector<T> elems = this->loadFile();
	elems.push_back(el);
//	sort(elems.begin(), elems.end(), [](T a, T b) {return a < b; });

	this->saveFile(elems);
}

template<typename T>
inline void Repository<T>::update(T update)
{
	int pos = positionOfElement(update);
	std::vector<T> elems = this->loadFile();
	elems[pos] = update;
	this->saveFile(elems);
}

template<typename T>
inline void Repository<T>::removeElem(T elem)
{
	std::vector<T> elems = this->loadFile();
	auto it = find(elems.begin(), elems.end(), elem);
	if (it != end())
		elems.erase(it);
	this->saveFile(elems);
}

template<typename T>
inline void Repository<T>::removePos(int pos)
{
	std::vector<T> elems = this->loadFile();
	auto it = find(elems.begin(), elems.end(), elem[pos]);
	if (it != end())
		elems.erase(it);
	this->saveFile(elems);
}

template<typename T>
inline void Repository<T>::saveFile(std::vector<T> elems)
{
	std::ofstream f{ this->file };

	sort(elems.begin(), elems.end(), [](T a, T b) {return a < b; });

	for (auto el : elems)
	{
		f << el << std::endl;
	}
	f.close();
}

template<typename T>
inline std::vector<T> Repository<T>::loadFile()
{
	T elem;
	std::vector<T> elems;

	std::ifstream f{ this->file };
	while (f >> elem)
		elems.push_back(elem);

	f.close();
	return elems;
}

template<typename T>
inline bool Repository<T>::checkExisting(T elem)
{
	std::vector<T> elems = this->loadFile();
	for (auto e : elems)
		if (e == elem)
			return true;
	return false;
}

template<typename T>
inline int Repository<T>::positionOfElement(T elem)
{
	std::vector<T> elems = this->loadFile();
	for (int i = 0; i < elems.size(); i++)
		if (elems[i] == elem)
			return i;
	return -1;
}

template<typename T>
inline T Repository<T>::elementOnPosition(int pos)
{
	std::vector<T> elems = this->loadFile();
	return elems[pos];
}

