#pragma once
#include "Service.h"
class UI {
private:
	Service& service;
public:
	UI(Service& service);
	~UI();

	void runMenu();
private:
	void displayMenu();
	void uiAddStudent();
	void uiUpdateVarstaDupaNume();
	void uiDeleteBetweenAges();
	void showAll();
};