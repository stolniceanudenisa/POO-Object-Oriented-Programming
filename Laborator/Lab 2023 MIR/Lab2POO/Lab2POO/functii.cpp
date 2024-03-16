#include <iostream>
using namespace std;

int n;
//v[100];

int* v = new int[100];


void citireSir(int x[], int val, int& cont)
{
    x[cont] = val;
    cont++;

}

void afisareSir(int x[], int cont)
{
    int i = 0;
    while (i < cont)
    {
        cout << x[i] << " ";
        i++;
    }
    delete[]v;
    cout << '\n';
}


void citireSir2() {
    cout << "n =";
    cin >> n;
    cout << "Vectorul:";
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << endl;
    //cout << "Vectorul a fost citit!\n";
}

void afisareSir2() 
{
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    //delete []v;
    cout << endl;
    //cout << "Vectorul a fost afisat!\n";
}
// 1 2 3 3 4 5 6 7    1 2 3 4 1 2 2      -1 4 3 2 1 0 2     4 4 3 2 1 0 2


int secv_nr_distincte(int x[], int n, int aux[])
{

    int i, l, j, lmax, start, stop, pmax, lungmax, ap[100000] = { 0 };
    l = lmax = 0;
    start = stop = lungmax = pmax = 0;
    i = 1;
    ap[x[0]]++;
    while (i < n)
    {
        if (ap[x[i]] == 0)
        {
            l++;
            ap[x[i]]++;
        }
        else
        {
            if (l > lmax)
            {
                lmax = l;
                pmax = i - 1;
                lungmax = start;
            }
            start = stop = i;
            l = 1;
            for (j = 0; j <= 99999; j++)
                ap[j] = 0;
            ap[x[i]]++;
        }
        i++;
    }
    if (l > lmax)
    {
        pmax = i - 1;
        lungmax = start;
    }
    j = 0;
    for (i = lungmax; i <= pmax; i++)
    {
        aux[j] = x[i];
        j++;
    }
    return pmax - lungmax + 1;
    
}


int secv_3_val_dist(int x[], int n, int aux[])
{
    
    // 3 4 1 2 2 3 3 4    ---------
    
    
    // 1, 1, 2, 2, 3, 5, 6, 7
    // 1 2 3 4 | 1 2 2 2 3 | 4 1 2

    int lc = 0, j,x1=0,y=0,z=0;
    int lmax = 0, pmax = 0, pc = 0;
    int pasy = 0;
    int i = 0;
    while (i < n)
    {
        if (z != 0 && z != x[i]) {
             if (lc > lmax)
            {
                lmax = lc;
                pmax =i-lc;
            }
            x1 = 0;
            y = 0;
            z = 0;
            lc = 0;
            
            /*lc = 1;
            pc = i;*/
                
        }

        if (x1 == 0 && y == 0 && z == 0) {
            x1 = x[pasy];
            if (pasy != 0)
                i = pasy;
            lc++;

        }
        else if (x1 != 0 && y == 0 && z == 0 && x1 != x[i])
        {
            y = x[i];
            pasy = i;
            lc++;
        }
        else if (x1 != 0 && y != 0 && z == 0 && y != x[i])
        {
            z = x[i];
            lc++;
        }
        else
            lc++;
        //cout << x1 << " ";
        //cout << y << " ";
        //cout << z << " ";
        //cout << lc << " ";
        //cout << endl;
        i++;
    }

        /*else
        {
            if (lc > lmax)
            {
                lmax = lc;
                pmax = pc;
            }
            lc = 1;
            pc = i;

        }
    if (lc > lmax)
    {
        lmax = lc;
        pmax = pc;
    }
   */ 

    if (lc > lmax)
    {
        lmax = lc;
        pmax = i - lc;
    }

    j = 0;
    for (int i = pmax; i <= pmax + lmax; i++)
    {

        aux[j] = x[i];
        //cout << aux[j]<<" ";
        j++;
    }
    return lmax;
}

int cifracomuna(int x, int y)
{ // 11234  345
    // 12 2213 31 314 451 777
    int nr = 0;
    int aux = 0;
    aux = y;
    while (x)
    {
        int c = x % 10;
        y = aux;
        while (y)
        {
            if (c == y % 10)
                nr++;
            y /= 10;
        }
        x /= 10;
    }
    return nr;
}

int secv_cif_comune(int v[], int n, int aux[])
{
    int lc = 1, j;
    int lmax = 0, pmax = 0, pc = 0;
    for (int i = 1; i < n; i++)
        if (cifracomuna(v[i-1], v[i]) >= 2)
        {
            //cout << cifracomuna(v[i-1], v[i]);
            lc++;
        }
        else
        {
            if (lc > lmax)
            {
                lmax = lc;
                pmax = pc;
            }
            lc = 1;
            pc = i;

        }
    if (lc > lmax)
    {
        lmax = lc;
        pmax = pc;
    }
    j = 0;
    //cout << pmax << " " << lmax << endl;
    for (int i = pmax; i <= pmax + lmax; i++)
    {
        
       
        aux[j] = v[i];
        //cout << aux[j]<<" ";
        j++;
    }
    //cout << endl;
    return lmax;

}

int secv_semne_ctr(int v[], int n, int aux[])
{
    int lc = 1,j;
    int lmax = 0, pmax = 0, pc = 0;
    for (int i = 1; i < n; i++)
        if (v[i] < 0 && v[i - 1] >0 || v[i] > 0 && v[i - 1] < 0)
            lc++;
        else
        {
            if (lc > lmax)
            {
                lmax = lc;
                pmax = pc;
            }
            lc = 1;
            pc = i;

        }
    if (lc > lmax)
    {
        lmax = lc;
        pmax = pc;
    }
    j = 0;
    for (int i = pmax; i <= pmax+lmax; i++)
    {
        aux[j] = v[i];
        j++;
    }
    return lmax;
}


void secv_nr_distincte()
{
    
    int c[100];
    for (int i = 0; i < n; i++)
        c[i] = v[i];
    int lc = 1;
    int lmax = 0, pmax = 0, pc = 0;
    for (int i = 1; i < n; i++) {
        lc = 1;
        pc = i;
        for (int j = i - 1; j >= 0; j--) {
            if (v[i] != v[j] && v[j] != -1)
                lc++;
            else
            {
                if (lc > lmax)
                {
                    lmax = lc;
                    pmax = pc;
                }
                lc = 1;
                pc = i;
                v[j] = -1;

            }
        }

        if (lc > lmax)
        {
            lmax = lc;
            pmax = pc;
        }
    }
    for (int i = pmax - lmax + 1; i <= pmax; i++)
        cout << c[i] << " ";

 /*   int poz = pmax - lmax + 1;
    return poz;*/

    //cout << endl;
    /*cout << lmax;
    cout << endl;
    cout << pmax;*/


    /*  for (int i = pmax - lmax + 1; i <= pmax; i++)
      cout << c[i] << " ";*/
      //int vector[100];
      //for (int i = pmax - lmax + 1; i <= pmax; i++)
      //    vector[i] = c[i];
      //return vector;
}


void secv_semne_ctr()
{
    int lc = 1;
    int lmax = 0, pmax = 0, pc = 0;
    for (int i = 1; i < n; i++)
        if (v[i] < 0 && v[i - 1] >0 || v[i] >0 && v[i - 1]<0)
            lc++;
        else
        {
            if (lc > lmax)
            {
                lmax = lc;
                pmax = pc;
            }
            lc = 1;
            pc = i;

        }
    if (lc > lmax)
    {
        lmax = lc;
        pmax = pc;
    }
    for (int i = pmax; i < pmax + lmax; i++)
        cout << v[i] << " ";
    cout << endl;
    cout << endl;
}
















void secv_nr_cresc()
{
    int lc = 1;
    int lmax=0, pmax = 0, pc=0;
    for (int i = 1; i < n; i++)
        if (v[i] > v[i - 1])
            lc++;
        else
        {
            if (lc > lmax)
            {
                lmax = lc;
                pmax = pc;
            }
            lc = 1;
            pc = i;
           
        }
    if (lc > lmax)
    {
        lmax = lc;
        pmax = pc;
    }
    for (int i = pmax; i < pmax + lmax; i++)
        cout << v[i] << " ";
    cout << endl;
    cout << endl;

}


void secv_3_val_dist()
{
    int lc = 1;
    int lmax = 0, pmax = 0, pc = 0;
    for (int i = 1; i < n-1; i++)
        if (v[i] != v[i - 1] && v[i] != v[i+1])
            lc++;
        else
        {
            if (lc > lmax)
            {
                lmax = lc;
                pmax = pc;
            }
            lc = 1;
            pc = i;

        }
    if (lc > lmax)
    {
        lmax = lc;
        pmax = pc;
    }
    for (int i = pmax; i < pmax + lmax; i++)
        cout << v[i] << " ";
    cout << endl;
    cout << endl;

}

int prim(int x)
{
    if (x < 2 || x>2 && x % 2 == 0)
        return 0;
    for (int d = 2; d * d <= x; d++)
        if (x % d == 0)
            return 0;
    return 1;
}


void secv_nr_prime()
{
    int lc = 1;
    int lmax = 0, pmax = 0, pc = 0;
    for (int i = 0; i < n; i++)
        if (prim(v[i]))
            lc++;
        else
        {
            if (lc > lmax)
            {
                lmax = lc;
                pmax = pc;
            }
            lc = 1;
            pc = i;

        }
    if (lc > lmax)
    {
        lmax = lc;
        pmax = pc;
    }
    for (int i = pmax+1; i < pmax + lmax; i++)
        cout << v[i] << " ";
    cout << endl;
    cout << endl;
}




void secv_dif_doua()
{

}

void secv_interval()
{

}

void secv_dif_perechi()
{

}


//void secv_suma_ct(int ct)
//{
//    // 1 2 3 4 5 6
//    int lc = 1,  sumacurenta=0;
//    int lmax = 0, pmax = 0, pc = 0;
//    for (int i = 0; i < n; i++)
//
//    {
//        
//        if (v[i] + sumacurenta < ct)
//        {
//            lc++;
//            sumacurenta = sumacurenta + v[i];
//        }
//            
//        else
//        {
//            if (lc > lmax)
//            {
//                lmax = lc;
//                pmax = pc;
//            }
//            lc = 1;
//            pc = i;
//            sumacurenta = v[i];
//
//        }
//       
//        
//    } 
//    if (lc > lmax)
//        {
//            lmax = lc;
//            pmax = pc;
//        }
//    for (int i = pmax; i < pmax + lmax; i++)
//        cout << v[i] << " ";
//    cout << endl;
//    cout << endl;
//
//}


void secv_suma_ct(int ct)
{
    // 1 2 3 4 5 6
    int lc = 1, sumacurenta = 0;
    int lmax = 0, pmax = 0, pc = 0;
    for (int j = 0; j < n; j++){
        for (int i = j; i < n; i++)

        {

            if (v[i] + sumacurenta <= ct)
            {
                lc++;
                sumacurenta = sumacurenta + v[i];
            }

            else
            {
                if (sumacurenta == ct)
                    if (lc > lmax)
                    {
                        lmax = lc;
                        pmax = pc;
                    }
                lc = 1;
                pc = i;
                sumacurenta = v[i];
               

            }


        }
    if (sumacurenta == ct)
        if (lc > lmax)
        {
            lmax = lc;
            pmax = pc;
        }
   
} 
    for (int i = pmax; i < pmax + lmax; i++)
        cout << v[i] << " ";
    cout << endl;
    cout << endl;

}

void secv_cif_comune()
{

}

void secv_munte()
{

}
