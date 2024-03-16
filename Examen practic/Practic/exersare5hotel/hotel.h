#pragma once

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Hotel {
private:
	int camerasingle;
	int cameradubla;
	int apartament;
	int checkindate;
	int nrzile;
public:
	Hotel();
	Hotel(int camerasingle, int cameradubla, int apartament, int checkindate, int nrzile);
	Hotel(const Hotel&h);
	 
	int getcamerasingle();
	int getcameradubla();
	int getapartament();
	int getcheckindate();
	int getnrzile();
	void setcamerasingle(int camerasingle);
	void setcameradubla(int cameradubla);
	void setapartament(int apartament);
	void setcheckindate(int checkindate);
	void setnrzile(int nrzile);
	//Hotel& operator=(const Hotel&);
	
	string to_string() const
	{
		return std::to_string(camerasingle) + " " + std::to_string(cameradubla) + " " + std::to_string(apartament) + " " + std::to_string(checkindate) + " " + std::to_string(nrzile);
	
		/*stringstream ss;
		ss << "Nume echipa 1: " << this->numeechipa1 << " | Nume echipa 2: " << this->numeechipa2 << " | Scor echipa1: " << this->scor1 << " | Scor echipa 2: " << this->scor2;
		return ss.str();*/

	}
	//bool operator==(const Hotel&);
};