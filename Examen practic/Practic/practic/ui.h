#pragma once
#include"service.h"

class UI {
private:
	Service& service;

public:
	UI(Service& service);
	void run_menu();
	void display_menu();
	void list_rochii();
	void afisare_rochii_marime();
	void cumparare_rochie();
	void top3ui();


};

