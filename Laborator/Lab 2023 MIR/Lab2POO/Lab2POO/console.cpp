#include <cstring>
#include <iostream>
#include "console.h"
#include "functii.h"
#include "teste.h"
using namespace std;

void menu()
{
    cout << endl;
    cout << " 1. Citirea unei liste de numere intregi\n"
        " 2. Afisarea unei liste de numere intregi \n"
        " 3. secventa de numere distincte \n"
        " 4. secventa de numere cu semne contrare \n"
        " 5. secventa de numere cu cel mult 3 valori distincte \n"
        " 6. secventa de numere cu cifre comune \n"
        " 0. Iesire din aplicatie\n";
    cout << endl;
}


void Console()
{
    int option;
    int val, contor = 0, aux[100] = {}, aux2[100] = {}, lungime, x[100];
    int run = true;
    while (run) {
        menu();
        cout << "Dati optiunea: ";
        cin >> option;
        if (option == 1)
        {
            cout << "Introduceti cate un element: " << '\n';
            cin >> val;
            citireSir(x, val, contor);
           
        }
        else if (option == 2)
        {
            afisareSir(x, contor);
            
        }
        else if (option == 3)
        {
            lungime = secv_nr_distincte(x, contor, aux);
            for (int i = 0; i < lungime; i++)
                cout << aux[i] << " ";
            cout << '\n';
            
        }
            
        else if (option == 4)
        {
            lungime = secv_semne_ctr(x, contor,aux2);
            cout << lungime << endl;
            for (int i = 0; i < lungime; i++)
                cout << aux2[i] << " ";
            cout << '\n';
            
        }

        else if (option == 5)
        {
            lungime = secv_3_val_dist(x, contor, aux2);
            //cout << lungime << endl;
            for (int i = 0; i < lungime; i++)
                cout << aux2[i] << " ";
            cout << '\n';

        }

        else if (option == 6)
        {
            lungime = secv_cif_comune(x, contor, aux2);
            //cout << lungime << endl;
            for (int i = 0; i < lungime; i++)
                cout << aux2[i] << " ";
            cout << '\n';

        }

        else if (option == 0)
            run = false;
        else cout << "Comanda gresita! Incearca din nou.\n";
    }
}









//" 11. secventa de numere cu cel mult 3 valori distincte \n"
//" 12. secventa de numere prime \n"
//" 13. secventa cu numere distincte \n"
//" 14.  \n"
//" 19. secventa de numere suma = cu o constanta \n"


 //else if (option == 12)
 //    secv_nr_prime();

 //else if (option == 13)
 //    secv_nr_distincte();

 //else if (option == 14)
 //    secv_dif_doua();

 //else if (option == 15)
 //    secv_interval();

 //else if (option == 16)
 //    secv_dif_perechi();

 //else if (option == 17)
 //    secv_semne_ctr();

 //else if (option == 19)
 //{
 //    int ct;
 //    cout << "Dati constanta: ";
 //    cin >> ct;
 //    secv_suma_ct(ct);
 //       }

 //else if (option == 12)
 //    secv_cif_comune();

 //else if (option == 13)
 //    secv_munte();






