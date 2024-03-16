
#include "teste.h"
#include "repo.h"
#include "repofile.h"
#include "service.h"
#include "produs.h"
#include <assert.h>

void Teste::testeProdus()
{
    Produs prod1(1, "produs1", 10);
    Produs prod2(2, "produs2", 20);
    Produs prod3(3, "produs3", 30);

    // test the getCod() function
    assert(prod1.getCod() == 1);
    assert(prod2.getCod() == 2);
    assert(prod3.getCod() == 3);

    // test the getNume() function
    assert(prod1.getNume() == "produs1");
    assert(prod2.getNume() == "produs2");
    assert(prod3.getNume() == "produs3");

    // test the getPret() function
    assert(prod1.getPret() == 10);
    assert(prod2.getPret() == 20);
    assert(prod3.getPret() == 30);

    // test the setCod() function
    prod1.setCod(4);
    assert(prod1.getCod() == 4);

    // test the setNume() function
    prod2.setNume("produs2.1");
    assert(prod2.getNume() == "produs2.1");

    // test the setPret() function
    prod3.setPret(40);
    assert(prod3.getPret() == 40);

   
}

void Teste::testeRepo() {
 /*   Repository<int> repo1;
    repo1.addEntity(1);
    repo1.addEntity(2);
    assert(repo1.size() == 2);
    Repository<pair<Produs, int>> repo;
    Produs p1(1, "ciocolata", 10);
    Produs p2(2, "croissant", 10);
    Produs p3(3, "acadea", 10);
    Produs p4(4, "suc", 10);
    Produs p5(5, "napolitane", 10);
    Produs p6(6, "iaurt", 10);
    pair <Produs, int> p(p1, 2);
    repo.addEntity(p);
    p.first = p2;
    p.second = 4;
    repo.addEntity(p);
    p.first = p3;
    p.second = 10;
    repo.addEntity(p);
    p.first = p4;
    p.second = 23;
    repo.addEntity(p);
    p.first = p5;
    p.second = 7;
    repo.addEntity(p);
    p.first = p6;
    p.second = 9;
    repo.addEntity(p);

    assert(repo.size() == 6);*/

    Repository<int> repo;
    repo.addEntity(1);
    repo.addEntity(2);
    repo.addEntity(3);
    assert(repo.size() == 3);
    assert(repo.getAt(0) == 1);
    assert(repo.getAt(1) == 2);
    assert(repo.getAt(2) == 3);
    assert(!repo.findEntity(4));
    assert(repo.findEntity(2));
    assert(repo.delEntity(2));
    assert(repo.size() == 2);
    assert(repo.getAt(0) == 1);
    assert(repo.getAt(1) == 3);
    assert(!repo.delEntity(2));
 

    Repository<string> repo2;
    string s1 = "foo";
    string s2 = "bar";
    string s3 = "baz";
    repo2.addEntity(s1);
    repo2.addEntity(s2);
    repo2.addEntity(s3);
    assert(repo2.size() == 3);
    assert(repo2.getAt(0) == "foo");
    assert(repo2.getAt(1) == "bar");
    assert(repo2.getAt(2) == "baz");
    assert(!repo2.findEntity("qux"));
    assert(repo2.findEntity("bar"));
    assert(repo2.delEntity("bar"));
    assert(repo2.size() == 2);
    assert(repo2.getAt(0) == "foo");
    assert(repo2.getAt(1) == "baz");
    assert(!repo2.delEntity("bar"));
 
     
    //repo.addEntity("apple");
    //repo.addEntity("banana");
    //repo.addEntity("orange");

    //// Define the old and new entities
    //string old_entity = "banana";
    //string new_entity = "kiwi";

    //// Call the updateEntity() function
    //bool success = repo.updateEntity(old_entity, new_entity);

    //// Check that the update was successful
    //ASSERT_TRUE(success);

    //// Check that the repository now contains the new entity
    //ASSERT_TRUE(repo.findEntity(new_entity));

    //// Check that the repository no longer contains the old entity
    //ASSERT_FALSE(repo.findEntity(old_entity));
}

void Teste::testeRepoFile()
{
    RepositoryFile repo("testrepofile.txt");

    // test addEntity
    //assert(repo.size() == 0);
    /*pair<Produs, int> produs1(Produs(7, "tiramisu", 11), 1);
    repo.addEntity(produs1);
    assert(repo.size() == 1);*/

    //// test updateEntity
    //pair<Produs, int> old_produs(Produs(7, "tiramisu", 11), 1);
    //pair<Produs, int> new_produs(Produs(7, "papanasi", 15), 2);
    //repo.updateEntity(old_produs, new_produs);
    //assert(repo.size() == 7);
    //assert(repo.getAll()[6].first.getNume() == "papanasi");
    //assert(repo.getAll()[6].second == 2);

    //// test delEntity
    //pair<Produs, int> produs2(Produs(11, "ecler", 16), 5);
    //repo.addEntity(produs2);
    //assert(repo.size() == 8);
    //repo.delEntity(produs2);
    //assert(repo.size() == 7);

    //// test findEntity
    //pair<Produs, int> produs3(Produs(2, "briosa", 6), 2);
    //assert(repo.findEntity(produs3) == true);
    //pair<Produs, int> produs4(Produs(9, "tort", 30), 3);
    //assert(repo.findEntity(produs4) == false);
}

void Teste::testeService()
{
    //RepositoryFile repo;
    //Service s(repo);

    //// Test addProd and findByCode
    //s.addProd(1, "Produs1", 10, 5);
    //assert(s.findByCode(1) == true);
    //assert(s.findByCode(2) == false);

    //// Test updateProd
    //s.updateProd(1, "Produs1_updated", 15, 10);
    //assert(s.getAll()[0].first.getNume() == "Produs1_updated");
    //assert(s.getAll()[0].first.getPret() == 15);
    //assert(s.getAll()[0].second == 10);

    //// Test sortPrice and sortUnit
    //s.addProd(2, "Produs2", 20, 8);
    //s.addProd(3, "Produs3", 5, 15);
    //vector<pair<Produs, int>> v = s.sortPrice();
    //assert(v[0].first.getCod() == 3);
    //assert(v[1].first.getCod() == 1);
    //assert(v[2].first.getCod() == 2);
    //v = s.sortUnit();
    //assert(v[0].first.getCod() == 2);
    //assert(v[1].first.getCod() == 1);
    //assert(v[2].first.getCod() == 3);

    // Test lowPrice
    //v = s.lowPrice(10);
    //assert(v[0].first.getCod() == 1);
    //assert(v[1].first.getCod() == 3);

    // Test buyProdus
    //int buget = 50;
    //assert(s.buyProdus(1, buget) == 40);
    //assert(s.getAll()[0].second == 9);
    //assert(s.getBuget() == 10);
    //assert(s.buyProdus(1, buget) == -3);
    //assert(s.buyProdus(4, buget) == -1);
    //assert(s.buyProdus(2, buget) == 0);
    //assert(s.getAll()[1].second == 7);
}

Teste::Teste() {

}

void Teste::testAll() {
    testeProdus();
    testeRepo();
    testeRepoFile();
    testeService();
}
