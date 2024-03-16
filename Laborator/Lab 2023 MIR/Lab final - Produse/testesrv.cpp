#include "testesrv.h"
#include <assert.h>
#include "service.h"
#include "produss.h"
#include <vector>
#include "repos.h"
 


void testGetAllSrv()
{
    ValidatorProdus* validator = new ValidatorProdus();
    RepoFile* repo = new RepoFile("test.txt", validator);
    Service serv(*repo);

    Produs* p1 = new Produs(3, "banane", 23, 2);
    Produs* p2 = new Produs(5, "chipsuri", 10, 3);
    serv.addProdus(p1->getCod(), p1->getNume(), p1->getPret(), p1->getNraparitii());
    serv.addProdus(p2->getCod(), p2->getNume(), p2->getPret(), p2->getNraparitii());
    vector<Produs*> produse = serv.getAll();
    assert(*produse[0] == *p1);
    assert(*produse[1] == *p2);
}

void testAddProdusSrv()
{
    ValidatorProdus* validator = new ValidatorProdus();
    RepoFile* repo = new RepoFile("test.txt", validator);
    Service serv(*repo);

    Produs* p1 = new Produs(3, "banane", 23, 2);
    serv.addProdus(p1->getCod(), p1->getNume(), p1->getPret(), p1->getNraparitii());
    assert(*serv.getAll()[0] == *p1);
}

void testUpdateProdusSrv()
{
    ValidatorProdus* validator = new ValidatorProdus();
    RepoFile* repo = new RepoFile("test.txt", validator);
    Service serv(*repo);

    Produs* p1 = new Produs(3, "banane", 23, 2);
    Produs* p2 = new Produs(4, "covrigi", 2, 8);
    Produs* p3 = new Produs(5, "saratele", 5, 20);

    serv.addProdus(p1->getCod(), p1->getNume(), p1->getPret(), p1->getNraparitii());
    serv.addProdus(p2->getCod(), p2->getNume(), p2->getPret(), p2->getNraparitii());
    serv.updateProdus(p1->getCod(), p2->getNume(), p2->getPret(), p2->getNraparitii());
    assert(p1->getCod() == 3);
    
        /*try {
            //serv.updateProdusSarat(p3->getNume(), p2->getNume(), p2->getPret(), p2->getCantitateSare());
            assert(false);
        }
        catch (RepoException& e) {
        }
        catch (...) {
            assert(false);
        }*/
}

void testDeleteProdusCodSrv()
{
    ValidatorProdus* validator = new ValidatorProdus();
    RepoFile* repo = new RepoFile("test.txt", validator);
    Service serv(*repo);
    Produs* p1 = new Produs(3, "banane", 23, 2);
    Produs* p2 = new Produs(5, "chipsuri", 10, 3);
    serv.addProdus(p1->getCod(), p1->getNume(), p1->getPret(), p1->getNraparitii());
    serv.addProdus(p2->getCod(), p2->getNume(), p2->getPret(), p2->getNraparitii());
    serv.deleteProdusCod(p1->getCod());
    assert(*serv.getAll()[0] == *p2);
}

void testCumparaProdusSrv()
{
    RepoFile repo{ "produse.txt", new ValidatorProdus{} };
    Service service{ repo };
    int buget{ 100 };

    // produs ce nu exista
    int result = service.buyProdus(999, buget);
    assert(result == -1);

    // out of stock
    result = service.buyProdus(7, buget);
    assert(result == -2);

    // fonduri insuficiente
    result = service.buyProdus(8, buget);
    assert(result == -3);

    // cumparare cu succes
    result = service.buyProdus(4, buget);
    assert(result == 91); 
   
}



void testFilterByPriceSrv()
{
    ValidatorProdus* validator = new ValidatorProdus();
    RepoFile* repo = new RepoFile("testsrvvv", validator);
    Service serv(*repo);
    vector<Produs*> result = serv.filterByPrice(15, 35);
    assert(result.size() == 0);
}

void testSortByNameSrv()
{
    ValidatorProdus* validator = new ValidatorProdus();
    RepoFile* repo = new RepoFile("testsrvvv.txt", validator);
    Service serv(*repo);

    Produs* p1 = new Produs(1, "a", 10, 5);
    Produs* p2 = new Produs(2, "b", 20, 3);
 

    serv.addProdus(p1->getCod(), p1->getNume(), p1->getPret(), p1->getNraparitii());
    serv.addProdus(p2->getCod(), p2->getNume(), p2->getPret(), p2->getNraparitii());
     
    vector<Produs*> result = serv.sorteazaDupaNume();
    /*for (auto produs : result)
    {
        cout << "Cod: " << produs->getCod() << ", Nume: " << produs->getNume() << ", Pret: " << produs->getPret() << ", Nr. aparitii: " << produs->getNraparitii() << endl;
    }*/

    assert(*result[0] == *p1);
    
 
}

void testFindByCodeSrv()
{
    ValidatorProdus* validator = new ValidatorProdus();
    RepoFile* repo = new RepoFile("test.txt", validator);
    Service serv(*repo);

    Produs* p1 = new Produs(1, "mere", 10, 5);
    Produs* p2 = new Produs(2, "pere", 15, 3);
    serv.addProdus(p1->getCod(), p1->getNume(), p1->getPret(), p1->getNraparitii());
    serv.addProdus(p2->getCod(), p2->getNume(), p2->getPret(), p2->getNraparitii());

    assert(serv.findByCode(p1->getCod()) == true);
    
}

 













void testAllSrv()
{
    //testGetAllSrv();
    //testFindByCodeSrv();
    //testDeleteProdusCodSrv();
    //testAddProdusSrv();
    //testUpdateProdusSrv();
    //testSortByNameSrv();
    //testFilterByPriceSrv();
    //testCumparaProdusSrv();
}