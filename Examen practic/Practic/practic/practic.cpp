// practic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "teste.h"
#include "rochie.h"
#include "repo.h"
#include "service.h"
#include "ui.h"
#include "validator.h"
int main()
{
    Teste t;
    t.run_all();
    cout << "Testele au trecut! " << '\n';
    Validator validator;
    RepoFile repofile("rochii.txt", validator);
    Service service(repofile, validator);
    UI ui(service);
    ui.run_menu();
    return 0;
}

