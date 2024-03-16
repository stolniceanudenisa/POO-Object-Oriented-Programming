#pragma once
#include "service.h"

class UI {
private:
	Service& service;
public:
	UI(Service& service);
	void run_menu();
	void display_menu();


	void add();
	
	void list_profesori();

	void nrprofigreva();

	void disciplina_cu_cei_mai_multi_profi_greva();
	void clasa_cu_cei_mai_multi_profi_greva();

	~UI() {};
};