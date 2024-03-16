#pragma once

#include "Domain.h"

class Repository
{
private:
	std::string file_name;

public:
	Repository() {}
	Repository(std::string file) : file_name(file) {}

	void set_file(std::string file) { file_name = file; }

	std::vector<Item> get_all();

	void add(const Item& item);
	void remove(const Item& item);
	void update(const Item& item);

	int search(Item item);

	void save_file(std::vector<Item> items);
	std::vector<Item> load_file();
};