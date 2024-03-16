#pragma once

#include "Repository.h"

class Service
{
private:
	Repository& repository;

public:
	Service(Repository& repo) : repository(repo) {}

	std::vector<Item> get_all() { return repository.get_all(); }
	void set_file(std::string file) { repository.set_file(file); }

	/*
	Function that searches illnes by name or category
	Input: string to search
	Output: vector of illnesses matching name or category
	*/
	std::vector<Item> search(std::string str);

	//ADD DELETE UPDATE

	//FILTERS SORTS
};