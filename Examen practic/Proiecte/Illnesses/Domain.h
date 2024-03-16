#pragma once

#include <string>
#include <vector>

class Item
{
private:

	std::string category, name;
	std::string symptoms;
//	FIELDS

public:
	
	Item() { category = ""; name = ""; symptoms = ""; }
//	Item(std::string id /*other*/ ) : category(c), name(n), {}

	std::string getCategory() { return category; }
	std::string getName() { return name; }
	std::string getSymptoms() { return symptoms; }
//	GETTERS


	std::string to_string();
	bool operator==(Item other) { return category== other.category && name==other.name; /**/}

	void reset() { category = ""; name = ""; symptoms = ""; }

	friend std::istream& operator>>(std::istream& stream, Item& item);
	friend std::ostream& operator<<(std::ostream& stream, const Item& item);

	std::vector<std::string> tokenize(const std::string& str, char separator);
};