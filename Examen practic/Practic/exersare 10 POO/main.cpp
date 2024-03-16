
#include <iostream>
#include "teste.h"
#include "melodii.h"
#include "repofile.h"
#include "service.h"
#include "ui.h"
#include "validator.h"
using namespace std;
int main()
{
    Teste t;
    t.run_all();
    cout << "Testele au trecut! " << '\n';
    Validator validator;
    RepoFile repofile("melodii.txt", validator);
    Service service(repofile);
    UI ui(service);
    ui.run_menu();
    return 0;
}
