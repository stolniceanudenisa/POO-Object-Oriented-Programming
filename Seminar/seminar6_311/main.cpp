#include <iostream>
#include "Melon.h"
#include "Watermelon.h"
#include <vector>

int main() {
    vector <Fruit*> v;
    Fruit* wm1,*wm2,*me ;
    try {
        wm1 = new Watermelon(6, false);
        wm2 = new MelonLike(11, true);
        v.push_back(wm1);
        v.push_back(wm2);

        me = new MelonLike(-11, true);
    }
        catch (MyException &e) {
            cout << e.what() << endl;
        }

    for ( auto p : v)
        cout << p->getDescription() <<endl;
    cout << "Hello, World!" << endl;
    return 0;
}
