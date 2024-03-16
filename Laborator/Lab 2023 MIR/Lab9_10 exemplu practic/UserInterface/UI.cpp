//
// Created by fabia on 5/3/2022.
//

#include "UI.h"
#include "NotFoundElementException.h"
#include "InvalidCodeException.h"
#include "InvalidMoneyValueException.h"
#include <iostream>
#include <cstring>
#include <vector>

UI::UI(Service &givenService) : service(givenService) {

}

UI::~UI() {

}

bool UI::showAllProducts() {
    vector<Product> allProducts;
    this->service.getAllProducts(allProducts);
    if (allProducts.empty() == true) {
        cout << "No products!" << endl;
        return false;
    } else {
        for (int i = 0; i < allProducts.size(); i++) {
            cout << allProducts[i] << endl;
        }
        cout << "X. Exit" << endl;
        return true;
    }

}

void UI::console(string &option) {
    cout << "Enter the product's code: ";
    cin >> option;
    cout << endl;
}

void UI::handleMoneyChange(int remainder) {
    cout << "Your change is: " << remainder;

}

int UI::handleMoneyExchange(int productPrice) {
    cout << "Enter the sum of money required: ";
    int sum = 0;
    do {
        int value;
        cin >> value;
        sum += value;
        int money = productPrice;
        this->service.addAmountOfMoney(money, 1);
    } while (sum < productPrice);
    return sum - productPrice;
}

void UI::runMenu() {
    bool run = true;
    while (run) {
        bool existProducts = showAllProducts();
        if (existProducts) {
            string option;
            console(option);
            if (option == "x")
                run = false;
            else {
                try {
                    Product neededProduct = service.getProductByCode(stoi(option));


                    int remainder = handleMoneyExchange(neededProduct.getPrice());

                    handleMoneyChange(remainder);

                    service.deleteOneAmountProduct(neededProduct);
                }
                catch (ElementNotFoundException &error) {
                    cout << error.what();
                }
                catch (...) {
                    cout << "Another error!";
                }
            }
        } else
            run = false;
    }
}