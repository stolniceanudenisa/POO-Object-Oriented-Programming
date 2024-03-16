#include <iostream>
#include "Teste.h"
#include "UI.h"
#include "repo.h"
#include "service.h"

int main() {
    Teste t;
    t.testAll();
    //Repository<pair<Produs,int>> repo;
    RepositoryFile repo("Produs.txt");
    Service service(repo);
    UI consola(service);
    consola.Menu();

    return 0;
}
