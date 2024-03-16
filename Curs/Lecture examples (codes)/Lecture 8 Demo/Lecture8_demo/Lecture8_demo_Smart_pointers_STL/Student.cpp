#include "Student.h"
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

Student::Student(const std::string & name, const std::string & id): name{name}, studentID{id}
{
}

Student::~Student()
{
	cout << "Student " << this->name << " is being destroyed." << endl;
}

/*
	Tokenizes a string.
	Input:	str - the string to be tokenized.
			delimiter - char - the delimiter used for tokenization
	Output: a vector of strings, containing the tokens
*/
vector<string> tokenize(string str, char delimiter)
{
	vector <string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, ','))
		result.push_back(token);

	return result;
}


std::ostream & operator<<(std::ostream & os, const Student & s)
{
	os << s.name << "," << s.studentID  << "\n";
	return os;
}
