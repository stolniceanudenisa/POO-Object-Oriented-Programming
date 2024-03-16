// Finall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "service.h"
#include "repos.h"
#include "teste.h"
#include "testesrv.h"
#include "testerepo.h"
#include "testerpfile.h"
#include "testvalidator.h"
 
#include "repofile.h"
#include "ui.h"
using namespace std;


int main()
{
    TestValidatorProdus testval;
    testval.testAll();
    TestProdus testProdus;
    testProdus.testAllP();
    testAllRpfile();
    testAllSrv();
     
    ValidatorProdus* v = new ValidatorProdus();
    RepoFile repo = RepoFile("produse.txt",v);
    Service ctrl = Service(repo);
    UI ui = UI(ctrl);
    ui.runMenu();

    return 0;
}









//testAllR();

