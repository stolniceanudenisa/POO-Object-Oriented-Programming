
#include "repofile.h"
void RepoFile::load_from_file()
{
	this->hoteluri.clear();
	ifstream fisier(this->filename);
	if (!fisier.is_open())
		throw exception("Nu s a putut deschide fisierul");

	int camerasingle, cameradubla, apartament, checkindate, nrzile;
	while (fisier >> camerasingle >> cameradubla >> apartament >> checkindate >> nrzile) {

		if (fisier.fail())
			throw exception("Eroare la citire");

		Hotel hotel(camerasingle, cameradubla, apartament,  checkindate,  nrzile);
		this->hoteluri.push_back(hotel);

	}
	
}

void RepoFile::save_to_file()
{
}

RepoFile::RepoFile(string filename)
{
	this->filename = filename;
	this->load_from_file();
}

void RepoFile::add(Hotel h)
{
}

vector<Hotel> RepoFile::get_all()
{
	return vector<Hotel>();
}
