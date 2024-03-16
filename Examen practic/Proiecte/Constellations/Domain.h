#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>

class Astronomer
{
private:
	std::string name;
	std::string constellation;
	
public:
	Astronomer() {}
	Astronomer(std::string n, std::string c) : name(n), constellation(c) {}

	// GETTERS
	std::string getName() { return name; }
	std::string getConstellation() { return constellation; }
	void setName(std::string p) { name = p; }
	void setConstellation(std::string c) { constellation = c; }

	void reset() { name = ""; constellation = ""; }
	
	std::string toString() { return name + " " + constellation; }
	

	friend std::ostream& operator<<(std::ostream& os, const Astronomer& obj);
	friend std::istream& operator>>(std::istream& is, Astronomer& obj);
};



class Star
{
private:
	std::string name;
	std::string constellation;
	int RA;
	int Dec;
	int diameter;

public:
	Star() {}
	Star(std::string n, std::string c, int RA, int Dec, int d) : name(n), constellation(c), RA(RA), Dec(Dec), diameter(d){}

	// GETTERS
	std::string getName() { return name; }
	std::string getConstellation() { return constellation; }
	int getRA() { return RA; }
	int getDec() { return Dec; }
	int gerDiameter() { return diameter; }
	void reset() { name = ""; constellation = ""; RA = 0; Dec = 0; diameter = 0; }
	
	bool operator==(Star other) { return name == other.name; }
	std::string toString() { return name + "," + constellation + "," + std::to_string(RA) + "," + std::to_string(Dec) + "," + std::to_string(diameter); }
	

	friend std::ostream& operator<<(std::ostream& os, const Star& obj);
	friend std::istream& operator>>(std::istream& is, Star& obj);

	bool operator<(Star other) { return constellation < other.constellation; }
};



std::vector<std::string> tokenize(const std::string& str, char delimiter);
