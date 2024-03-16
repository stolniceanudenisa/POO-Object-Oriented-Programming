#include "teste.h"
#include "triunghi.h"
#include <assert.h>
#include "utils.h"
#include <iostream>

void teste()
{
    Triunghi myTriangle(1, 2, 3);

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



    assert(myTriangle.getPerimetru()==12);
    assert(myTriangle.getArie()==6);


    cout << "Testele au trecut!" << std::endl;

    Triunghi t1(3, 4, 5);
    Triunghi t2(1, 2, 3);
    Triunghi t3(7, 8, 9);

    Triunghi triunghiuri[3] = { t1, t2, t3 };
    int nrtriunghiuri = 3;

    assert(ceamaimareentitate(triunghiuri, nrtriunghiuri) == t3.getArie()); // test nou

}


void test_celmaimailungsecventa()
{
    Triunghi triunghiuri[] = { Triunghi(1, 2, 3), Triunghi(3, 4, 5), Triunghi(4, 5, 6), Triunghi(7, 8, 8), Triunghi(1, 1, 1) };
    int nrTriunghiuri = 5;
    Triunghi aux[10];

    int lungime = celmaimailungsecventa(triunghiuri, nrTriunghiuri, aux);

    assert(lungime == 2);

    //delete[] triunghiuri;

  
   /* Triunghi 1: 123
        Triunghi 2 : 345
        Triunghi 3 : 456
        Triunghi 4 : 788
        Triunghi 5 : 111


        345 456*/
}


//void test_celmaimailungsecventa() {
//    triunghi t1(3, 4, 5);
//    triunghi t2(1, 2, 3);
//    triunghi t3(7, 8, 9);
//    triunghi t4(2, 2, 2);
//    triunghi t5(6, 8, 10);
//    triunghi t6(3, 3, 3);
//
//    triunghi triunghiuri[] = { t1, t2, t3, t4, t5, t6 };
//    int nrTriunghiuri = 6;
//
//    assert(celmaimailungsecventa(triunghiuri, nrTriunghiuri) == 3);
//}
