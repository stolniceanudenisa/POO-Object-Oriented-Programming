

#include <iostream>
#include "test.h"
#include "Entitate.h"
#include "Repo.h"
#include "cassert"

void test() {
    Entitate myTriangle(1, 2, 3);

    // Test the getter method
    assert(myTriangle.getLatura1() == 1);
    assert(myTriangle.getLatura2() == 2);
    assert(myTriangle.getLatura3() == 3);

    // Test the setter method
    myTriangle.setLatura1(3);
    assert(myTriangle.getLatura1() == 3);

    myTriangle.setLatura2(4);
    assert(myTriangle.getLatura2() == 4);

    myTriangle.setLatura3(5);
    assert(myTriangle.getLatura3() == 5);



    assert(myTriangle.get_perimetru()==12);
    assert(myTriangle.arie()==6);


    std::cout << "Testele au trecut!" << std::endl;



//    Triunghi t1(3, 4, 5);
//    Triunghi t2(1, 2, 3);
//    Triunghi t3(7, 8, 9);
//
//    Triunghi triunghiuri[3] = { t1, t2, t3 };
//    int nrtriunghiuri = 3;
//
//    assert(ceamaimareentitate(triunghiuri, nrtriunghiuri) == t3.getArie()); // test nou

}


void test_all()
{
    test_countTrianglesInQuadrant12();
    test_add();
    test_item_from_pos();
    test_size();
    test_get_max();
    test_get_longest_equal_sequence();

}
void test_add()
{
    Repo repo;
    Entitate triunghi(1,2,3);
    repo.addItem(triunghi);
    assert(repo.getSize()==1);
}


void test_item_from_pos()
{
    Repo repo;
    Entitate triunghi(1,2,3);
    repo.addItem(triunghi);
    assert(repo.getItemFromPos(0)==triunghi);
}


void test_size()
{
    Repo repo;
    Entitate triunghi1(1,2,3);
    Entitate triunghi2(1,1,1);
    Entitate triunghi3(1,0,0);
    repo.addItem(triunghi1);
    repo.addItem(triunghi2);
    repo.addItem(triunghi3);
    assert(repo.getSize()==3);

}


void test_get_max()
{
    Repo repo;
    Entitate triunghi1(1,2,3);
    Entitate triunghi2(3,4,5);
    Entitate triunghi3(2,2,2);
    repo.addItem(triunghi1);
    repo.addItem(triunghi2);
    repo.addItem(triunghi3);


    // Test the getIndexOfMaxEntitate function
    assert(repo.getIndexOfMaxEntitate() == 1); // the second Entitate object has the largest perimeter and area
}

void test_get_longest_equal_sequence()
{
    Repo repo;
    Entitate triunghi1(1,2,3);
    Entitate triunghi2(2,2,2);
    Entitate triunghi3(2,2,2);
    Entitate triunghi4(3,4,5);
    repo.addItem(triunghi1);
    repo.addItem(triunghi2);
    repo.addItem(triunghi3);
    repo.addItem(triunghi4);

    assert(repo.getLongestEqualSequence() == 2); // there are two sequences of equal triangles: (triunghi2, triunghi3) and (triunghi4, triunghi4)
}


void test_countTrianglesInQuadrant12()
{
        Repo repo;
        Entitate triunghi1(4, 2, 5); // not in Quadrant 1 or 2
        Entitate triunghi2(3, 4, 5); // in Quadrant 1
        Entitate triunghi3(9, 9, 9); // in Quadrant 1
        Entitate triunghi4(7, 8, 9); // in Quadrant 2
        Entitate triunghi5(4, 5, 6); // in Quadrant 2
        repo.addItem(triunghi1);
        repo.addItem(triunghi2);
        repo.addItem(triunghi3);
        repo.addItem(triunghi4);
        repo.addItem(triunghi5);

        assert(repo.countTrianglesInQuadrant12() == 3);

}
