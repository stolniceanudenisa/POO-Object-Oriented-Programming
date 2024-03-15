
#include <iostream>
#include "UI.h"


int main() {
    Repo r;
    Service s(r);
    UI ui(s);
    ui.menu();
    return 0;
}
