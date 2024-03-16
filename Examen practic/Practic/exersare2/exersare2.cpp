 

#include <iostream>
#include "catalog.h"
#include "repofile.h"
#include "service.h"
#include "ui.h"

using namespace std;

int main()
{
    RepoFile repo = RepoFile("note.txt");
    Service service = Service(repo);
    UI ui = UI(service);
    ui.run_menu();

    return 0;
}

 