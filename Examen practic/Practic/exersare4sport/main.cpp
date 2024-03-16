
#include <iostream>
#include "meci.h"
#include "repofile.h"
#include "service.h"
#include "ui.h"
#include "teste.h"
#include "validator.h"


int main()
{
    Teste teste;
    teste.run_all();
    cout << "Testele au trecut" << '\n';

    Validator validator;
    Repofile repofile("meci.txt", validator);
    Service service(repofile);
    UI ui(service);
    ui.run_menu();
    return 0;
}
 