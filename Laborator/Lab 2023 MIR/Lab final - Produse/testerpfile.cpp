#include "testerpfile.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <assert.h>
 
#include "repos.h"
#include "repofile.h"
#include "produss.h"
#include "valp.h"
#include <fstream>
#include "repoexception.h"


void testSaveToFile()
{
    RepoFile repo{ "trepofile.txt", new ValidatorProdus{} };
    ifstream in("trepofile.txt");
    string line;
    getline(in, line);
    assert(line == "2,c,12,25");
   
}


void testLoadFromFile()
{
    RepoFile repo("trepofile.txt", new ValidatorProdus{});

    assert(repo.size() == 2);
    assert(repo.getAll()[0]->getCod() == 2);
    assert(repo.getAll()[0]->getNume() == "c");
    assert(repo.getAll()[0]->getPret() == 12);
    assert(repo.getAll()[0]->getNraparitii() == 25);

}

void testAdauga()
{
    ofstream f("trepofile.txt");
    f.close();

    RepoFile repo("trepofile.txt", new ValidatorProdus{});
    Produs* p1 = new Produs(2, "c", 12, 25);
    repo.addProdus(p1);


    try {
        repo.addProdus(p1);
    }
    catch (RepoException e) {}
    catch (...)
    {
        assert(false);
    }


    assert(repo.size() == 1);
    assert(*repo.getAll()[0] == *p1);
    ifstream g("trepofile.txt");
    string linie;
    g >> linie;
    assert(linie == "2,c,12,25");
}



void testDeleteProdusRfile()
{ 
    RepoFile repo("trepofile.txt", new ValidatorProdus{});

    Produs* p2 = new Produs(3, "a", 12, 5);
    repo.addProdus(p2);
    repo.deleteProdus(p2);


    try {
        repo.deleteProdus(p2);
    }
    catch (RepoException e) {}
    catch (...)
    {
        assert(false);
    }


    assert(repo.size() == 1);
}



void testUpdateProdusRfile()
{
    RepoFile repo("trepofile.txt", new ValidatorProdus{});

    Produs* p3 = new Produs(4, "uu", 12, 5);
    Produs* p4 = new Produs(5, "uu", 99, 9);
    repo.addProdus(p3);
    repo.updateProdus(p3,p4);

    try {
        repo.updateProdus(p3,p4);
    }
    catch (RepoException ex) {}
    catch (...)
    {
        assert(false);
    }


    assert(repo.get_at(1)->getPret() == 99);
}

 
void setFileName()
{
    RepoFile repo("aaaa.txt", new ValidatorProdus{});
    repo.setFileName("vvv.txt");
    assert(repo.getFileName() == "vvv.txt");
}












void testAllRpfile()
{
    //testSaveToFile();
    //testLoadFromFile();
    //testAdauga();
    //testDeleteProdusRfile();
    //testUpdateProdusRfile();
    setFileName();
}