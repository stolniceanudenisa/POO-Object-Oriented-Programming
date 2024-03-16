
#include <iostream>

using namespace std;
#include "Tests/Tests.h"
#include "Repo.h"
#include "Product.h"
#include "Money.h"
#include "Service.h"
#include "UI.h"
#include "RepoFile.h"

int main(){

    RepoFile<Product> product("product.txt");
    RepoFile<Money> money("money.txt");
    Service service(product, money);
    UI ui(service);
    ui.runMenu();




    return 0;
    
}