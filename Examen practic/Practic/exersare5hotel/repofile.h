#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "hotel.h"

class RepoFile {
private:
	string filename;
	vector<Hotel> hoteluri;

	void load_from_file();
	void save_to_file();
public:
	RepoFile(string filename);
	void add(Hotel h);
	vector<Hotel> get_all();

};