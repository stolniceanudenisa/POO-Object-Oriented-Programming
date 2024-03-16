#include <iostream>
#include "Teste.h"
#include "Repo.h"
#include "Service.h"
#include "UI.h"

int main()
{
    testStudent();
    testRepo();

    Repo repo("studenti.txt");
    Service service(repo);
    UI ui(service);

    ui.runMenu();
    return 0;
}
