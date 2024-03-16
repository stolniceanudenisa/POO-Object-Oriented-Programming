#include <iostream>
#include "tranzactie.h"
#include "teste.h"
#include "repo.h"
#include "service.h"
#include "UI.h"

using namespace std;

int main() {

    test_all();

    Repo repo;
    Service service(repo);
    UI ui(service);

    ui.run_menu();
    return 0;
}