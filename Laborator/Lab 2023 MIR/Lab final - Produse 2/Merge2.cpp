#include <iostream>

#include "RepoFile.h"
#include "service.h"
#include "teste.h"

#include "UI.h"


using namespace std;

int main()
{
     TestProdus testProdus;
     testProdus.testAll();
    RepoFile repo = RepoFile("produse.txt");
    Service ctrl = Service(repo);
    UI ui = UI(ctrl);
    ui.runMenu();

    return 0;
}
