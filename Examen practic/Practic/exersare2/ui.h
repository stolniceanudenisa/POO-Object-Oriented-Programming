#pragma once
#include "service.h"
class UI {
private:
	Service& service;
public:
	UI(Service& service);
	~UI();
	void run_menu();
	void display_menu();
	void show_all(vector<Catalog*> cataloage);
	void addcui();
	void afisarezi();

	void print_catalog(vector<Catalog*> cataloage);
};