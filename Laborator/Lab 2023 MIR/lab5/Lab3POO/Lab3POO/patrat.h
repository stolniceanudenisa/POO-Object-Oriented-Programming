#pragma once
#include <ostream>

using namespace std;

class Patrat {
private:
	int latura;

public:
	Patrat();
	Patrat(int latura);
	Patrat(const Patrat& pt);
	//~Patrat();

	int getLatura();
	void setLatura(int latura);
	int getArie();
	Patrat& operator=(const Patrat& pt);
	~Patrat() {
		//nimic de facut
	}
	friend ostream& operator<<(ostream& os, const Patrat& pt);
};