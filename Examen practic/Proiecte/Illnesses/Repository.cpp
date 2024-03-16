#include "Repository.h"

#include <sstream>
#include <fstream>

using namespace std;



void Repository::add(const Item& item)
{
	vector<Item> items = load_file();
	items.push_back(item);
	save_file(items);
}

void Repository::remove(const Item& item)
{
	vector<Item> items = load_file();

	int position = this->search(item);
	items.erase(items.begin() + position);

	save_file(items);
}

void Repository::update(const Item& item)
{
	std::vector<Item> items = load_file();

	// UPDATE

	save_file(items);
}

std::vector<Item> Repository::get_all()
{
	std::vector<Item> items = load_file();
	return items;
}

int Repository::search(Item item)
{
	vector<Item> items = load_file();

	for (int i = 0; i < items.size(); i++)
		if (items[i] == item)
			return i;
	return -1;
}

std::vector<Item> Repository::load_file()
{
	std::vector<Item> items;
	Item item;

	ifstream file{ file_name };
	while (file >> item)
		items.push_back(item);

	file.close();
	return items;
}

void Repository::save_file(std::vector<Item> items)
{
	ofstream file{ file_name };
	for (const auto& item : items)
		file << item << endl;
	file.close();
}
