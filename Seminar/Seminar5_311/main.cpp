#include <iostream>
#include "Tara.h"
#include "DestinatiaTuristica.h"

int main() {
    Tara tara1("Romania", 300);
    Tara tara2("Italia", 200);
    vector<string> obiective = {"Turnul E.", "Versailles", "Luvru"};
    DestinatiaTuristica destinatie ("Franta", 500, obiective);
    cout << tara1.toString() << endl;
    cout << tara2.toString() << endl;
    cout << destinatie.toString() << endl << endl;
    vector<Tara> v;
    v.push_back(tara1);
    v.push_back(tara2);
    v.push_back(destinatie);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].toString() << endl;
    }
    return 0;
}
