#include "Domain.h"

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;


std::string Item::to_string()
{
	string format;
	format += this->category + '|' + name + '|' + symptoms;
	///////
	return format;
}

std::vector<std::string> Item::tokenize(const std::string& str, char separator)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, separator))
		result.push_back(token);
	return result;
}



std::istream& operator>>(std::istream& stream, Item& item)
{
	item.reset();

	std::string line{};
	getline(stream, line);

	vector <string> parameters;
	stringstream line_stream(line);
	string parameter;
	while (getline(line_stream, parameter, '|'))
		parameters.push_back(parameter);

	if (parameters.size() == 0)
		return stream;

	item.category = parameters[0];
	item.name = parameters[1];
	item.symptoms = parameters[2];
//	item.auraLevel = stoi(parameters[2]);
//	turret.separateParts = stoi(parameters[SEPARATEPARTS_INDEX]);
//	turret.vision = parameters[VISION_INDEX];

	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Item& item)
{
	stream << item.category << '|';
	stream << item.name << '|';
	stream << item.symptoms;
//	stream << item. << ',';
//	stream << item. << ',';
//	stream << item. ;

	return stream;
}
