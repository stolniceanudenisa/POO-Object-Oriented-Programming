#pragma once
#include"service.h"

class UI {
private:
	Service& service;
	vector<Melodie> undo;

public:
	UI(Service& service);
	void run_menu();
	void display_menu();
	void list_melodii();
	void addmelodie();
	void insertmelodie();
	void deletemelodie();
	void delete_between();
	void updatemelodie();
	void update_anumit();
	void filtrare_gen();
	void sortare_durata();
	void sortare_denumire();
	void sortare_cantaret_denumire();
	void max_durata();
	void cautare_melodie();
	void numar_de_melodii_cantaret();
	void afisare_melodii_sub_4_minute();
	void durata_min_max();
	void undo_op();
	void generare_random();
	void vizualizare_per_gen();
	 
};