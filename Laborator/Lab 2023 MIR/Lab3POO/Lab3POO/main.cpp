// Lab3POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "triunghi.h"
#include "teste.h"
#include "utils.h"
 

using namespace std;

int main()
{
    teste();

    Triunghi triunghiuri[100], aux[100] = { };

    //Triunghi* triunghiuri = new Triunghi[100], aux[100] = { };



    //Triunghi* triunghiuri = new Triunghi[nrTriunghiuri];
    int nrTriunghiuri = 0,lungime;

    //triunghiuri[0] = Triunghi(1, 2, 3);
    //triunghiuri[1] = Triunghi(3, 4, 5);

    while (true) {
        cout << "1. Adauga triunghi\n";
        cout << "2. Afiseaza triunghiuri\n";
        cout << "3. Cea mai mare entitate\n";
        cout << "4. Entitati din cadranul I\n";
        cout << "5. Secventa de entitati egale\n";
        cout << "6. Perimetru\n";
       /* cout << "7. Arie\n";
        cout << "0. Iesire\n";*/
        int optiune;
        cout << "Introduceti o comanda:"<<endl;
        cin >> optiune;
        if (optiune == 0)
            break;
        if (optiune == 1)
        {
            addTriangle(triunghiuri, nrTriunghiuri);
           
        }
        else if (optiune == 2)
        {
            afisareTriunghiuri(triunghiuri, nrTriunghiuri);
           
        }
        else if (optiune == 3)
        {
            int ceamaimare = ceamaimareentitate(triunghiuri, nrTriunghiuri);
            
        }
        else if (optiune == 5)
        {
            lungime=celmaimailungsecventa(triunghiuri, nrTriunghiuri, aux);
            for (int i = 0; i < lungime; i++)
                cout << aux[i] << " ";
            cout << '\n';
        }
        //else if (optiune == 6)
        //{
        //    cout << "Perimetru: " << triunghiuri[0].getPerimetru() << endl;

        //}
        //else if (optiune == 7)
        //{
        //    cout << "Arie: " << triunghiuri[0].getArie() << endl;

        //}
        else
            cout << "Optiune invalida\n"; 

        }
    
    
 
    /*Triunghi myTriangle(3, 4, 5);
    cout << "Latura 1: " << myTriangle.getLatura1() << endl;
    cout << "Latura 2: " << myTriangle.getLatura2() << endl;
    cout << "Latura 3: " << myTriangle.getLatura3() << endl;
    cout << "Perimetru: " << myTriangle.getPerimetru() << endl;
    cout << "Arie: " << myTriangle.getArie() << endl;*/
    //delete[] triunghiuri;
    return 0;
}






















    /*Patrat my_square(5);
    cout << "Latura este: " << my_square.getLatura() << endl;
    cout << "Aria este: " << my_square.getArie() << endl;
    
    my_square.setLatura(7);
    cout << "Latura noua este: " << my_square.getLatura() << endl;
    cout << "Aria noua este: " << my_square.getArie() << endl;*/




    /*Complex z1(1.0, 2.0);
    std::cout << "z1 = (" << z1.getReal() << ", " << z1.getImag() << ")" << std::endl;

    z1.setReal(3.0);
    std::cout << "z1 = (" << z1.getReal() << ", " << z1.getImag() << ")" << std::endl;

    Complex z2(2.0, 3.0);
    std::cout << "z2 = (" << z2.getReal() << ", " << z2.getImag() << ")" << std::endl;

    Complex z3 = z1 + z2;
    std::cout << "z3 = z1 + z2 = (" << z3.getReal() << ", " << z3.getImag() << ")" << std::endl;

    Complex z4 = z1 * z2;
    std::cout << "z4 = z1 * z2 = (" << z4.getReal() << ", " << z4.getImag() << ")" << std::endl;

    std::cout << "Magnitude of z1 = " << z1.magnitude() << std::endl;*/


    /*
    
    */


    /*
    Circle c1(3.0);
    std::cout << "Radius of c1: " << c1.getRadius() << std::endl;
    std::cout << "Area of c1: " << c1.getArea() << std::endl;
    std::cout << "Circumference of c1: " << c1.getCircumference() << std::endl;

    c1.setRadius(4.0);
    std::cout << "Radius of c1: " << c1.getRadius() << std::endl;
    std::cout << "Area of c1: " << c1.getArea() << std::endl;
    std::cout << "Circumference of c1: " << c1.getCircumference() << std::endl;
    */


    /*
    Rectangle r1(3.0, 4.0);
    std::cout << "Width of r1: " << r1.getWidth() << std::endl;
    std::cout << "Height of r1: " << r1.getHeight() << std::endl;
    std::cout << "Area of r1: " << r1.getArea() << std::endl;
    std::cout << "Perimeter of r1: " << r1.getPerimeter() << std::endl;

    r1.setWidth(5.0);
    r1.setHeight(6.0);
    std::cout << "Width of r1: " << r1.getWidth() << std::endl;
    std::cout << "Height of r1: " << r1.getHeight() << std::endl;
    std::cout << "Area of r1: " << r1.getArea() << std::endl;
    std::cout << "Perimeter of r1: " << r1.getPerimeter() << std::endl;
    */

