#pragma once
#include "service.h"
class UI {
private:
	Service& service;
public:
	UI(Service& service);
	
	//~UI();
	void run_menu();
	void display_menu();
	void list_meciuri();


	void addmeciui();
	void deletemeciui();
	void sortare_scor1ui();
	void clasament2();



	//void show_all(vector<Meci> meciuri);
	///void print_meciuri(vector<Meci> meciuri);
};