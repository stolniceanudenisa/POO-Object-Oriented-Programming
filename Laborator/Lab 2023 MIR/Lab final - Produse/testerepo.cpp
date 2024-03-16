#include "testerepo.h"
#include "produss.h"
#include <assert.h>
#include "repoexception.h"

 
void testGetAll()
{
    ValidatorProdus* validator = new ValidatorProdus();
    Repo repo(validator);

    Produs* p1 = new Produs(1, "mere", 2, 10);
    Produs* p2 = new Produs(2, "pere", 3, 15);
    repo.addProdus(p1);
    repo.addProdus(p2);

    vector<Produs*> produse = repo.getAll();
    assert(produse.size() == 2);
    assert(*produse[0] == *p1);
    assert(*produse[1] == *p2);
  
}

void testGetSize()
{

    ValidatorProdus* validator = new ValidatorProdus();
    Repo repo(validator);

    assert(repo.size() == 0);

    Produs* p1 = new Produs(1, "mere", 2, 10);
    Produs* p2 = new Produs(2, "pere", 3, 15);
    repo.addProdus(p1);
    repo.addProdus(p2);

    assert(repo.size() == 2);
}

void testGet()
{
    Repo repo;
    ValidatorProdus* validator = new ValidatorProdus();
    Produs* produs1 = new Produs(1, "a", 12, 5);
    Produs* produs2 = new Produs(2, "b", 56, 5);
    repo.addProdus(produs1);
    repo.addProdus(produs2);
    assert(repo.get(0) == produs1);
    assert(repo.get(1) == produs2);
    assert(repo.get(2) == nullptr);


    try
    {
        repo.get(-1);
        assert(false);
    }
    catch (RepoException& e)
    {
    }
    catch (...)
    {
        assert(false);
    }

    try
    {
        repo.get(repo.size());
        assert(false);
    }
    catch (RepoException& e)
    {
    }
    catch (...)
    {
        assert(false);
    }
}

void testGetAt()
{
    ValidatorProdus* validator = new ValidatorProdus();
    Repo repo(validator);

    Produs* p1 = new Produs(1, "mere", 2, 10);
    Produs* p2 = new Produs(2, "pere", 3, 15);
    repo.addProdus(p1);
    repo.addProdus(p2);

    assert(*repo.get_at(0) == *p1);
    assert(*repo.get_at(1) == *p2);
}

void testFind()
{
    Repo repo;
    ValidatorProdus* validator = new ValidatorProdus();
    Produs* produs1 = new Produs(1, "a", 12, 5);
    Produs* produs2 = new Produs(2, "b", 56, 5);
    repo.addProdus(produs1);
    repo.addProdus(produs2);
    assert(repo.find("a") == produs1);
    assert(repo.find("b") == produs2);
    assert(repo.find("cccc") == nullptr);
}

void testAddProdus()
{
 
    Repo repo(new ValidatorProdus());
    Produs* p1 = new Produs(1, "a", 12, 5);
    Produs* p2 = new Produs(2, "b", 56, 5);
    Produs* p3 = new Produs(2, "b", 56, 5);
    repo.addProdus(p1);
    repo.addProdus(p2);
    assert(repo.getAll().size() == 2);
    assert(repo.getAll()[0]->getNume() == "a");
    assert(repo.getAll()[1]->getNume() == "b");

    repo.addProdus(p3);
     
    try {
        repo.addProdus(p3);
    }
    catch (RepoException e) {}
    catch (...)
    {
        assert(false);
    }

}

void testUpdateProdus()
{
    ValidatorProdus* validator = new ValidatorProdus();
    Repo repo(validator);

    Produs* p1 = new Produs(1, "a", 12, 5);
    Produs* p2 = new Produs(2, "b", 56, 5);
    repo.addProdus(p1);
    repo.updateProdus(p1, p2);

    assert(repo.size() == 1);

    try {
        repo.updateProdus(p1, p2);
    }
    catch (RepoException e) {}
    catch (...)
    {
        assert(false);
    }
}

void testDeleteProdus()
{
    ValidatorProdus* validator = new ValidatorProdus();
    Repo repo(validator);

    Produs* p1 = new Produs(1, "a", 12, 5);
    repo.addProdus(p1);
    repo.deleteProdus(p1);

    assert(repo.size() == 0);


    Produs* p2 = new Produs(1, "a", 12, 5);
    try {
        repo.deleteProdus(p2);
    }
    catch (RepoException e) {}
    catch (...)
    {
        assert(false);
    }

}






void testAllR()
{
    testGetSize();
    testGetAll();
    //testAddProdus();
    //testUpdateProdus();
    testGet();
    testFind();
    //testDeleteProdus();
}

 
