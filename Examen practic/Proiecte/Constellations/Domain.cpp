#include "Domain.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const Astronomer& obj)
{
	os << obj.name << ",";
	os << obj.constellation;

	return os;
}

std::istream& operator>>(std::istream& is, Astronomer& obj)
{
	obj.reset();

	std::string line{};
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() == 0)
		return is;
	
	obj.name = tokens[0];
	obj.constellation = tokens[1];

	return is;
}

std::ostream& operator<<(std::ostream& os, const Star& obj)
{
	os << obj.name << ",";
	os << obj.constellation << ",";
	os << obj.RA << ",";
	os << obj.Dec << ",";
	os << obj.diameter;

	return os;
}

std::istream& operator>>(std::istream& is, Star& obj)
{
	obj.reset();

	std::string line{};
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() == 0)
		return is;

	obj.name = tokens[0];
	obj.constellation = tokens[1];
	obj.RA = stoi(tokens[2]);
	obj.Dec = stoi(tokens[3]);
	obj.diameter = stoi(tokens[4]);

	return is;
}

std::vector<std::string> tokenize(const std::string& str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}
