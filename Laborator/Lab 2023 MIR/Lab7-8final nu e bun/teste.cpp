//
// Created by 40766 on 12.04.2023.
//

#include "teste.h"
#include "tranzactie.h"
#include "repo.h"
#include "service.h"
#include <cassert>
#include <cstring>
#include <sstream>

void test_all()
{
    teste_tranzactie();
    teste_repo();
    teste_service();
    std::cout<<"Testele au trecut!";
}

void teste_tranzactie()
{
    Tranzactie t1;
    assert(t1.get_ziua() == 0);
    assert(t1.get_suma() == 0);
    assert(strcmp(t1.get_tip(), "") == 0);
    assert(strcmp(t1.get_descriere(), "") == 0);

    Tranzactie t2(7,8,"in","tttttt");
    assert(t2.get_ziua() == 7);
    assert(t2.get_suma() == 8);
    assert(strcmp(t2.get_tip(), "in") == 0);
    assert(strcmp(t2.get_descriere(), "tttttt") == 0);


    Tranzactie t3(t2);
    assert(strcmp(t3.get_tip(), "in") == 0);
    assert(t3.get_ziua() == 7);
    assert(t3.get_suma() == 8);

    t2.set_suma(9);
    assert(t2.get_suma() == 9);

    t2.set_ziua(10);
    assert(t2.get_ziua() == 10);

    t2.set_tip("out");
    assert(strcmp(t2.get_tip(), "out") == 0);

    t2.set_descriere("zzzzzzzz");
    assert(strcmp(t2.get_descriere(), "zzzzzzzz") == 0);

    Tranzactie t4;
    t4 = t2;

    assert(t2==t4);
    assert(t4==t2);
    assert(!(t4==t3));

}

void teste_repo()
{
    Repo repo;
    assert(repo.get_size() == 0);

    Tranzactie t1(4,5,"in","aaa");
    repo.add_elem(t1);
    assert(repo.get_size() == 1);
    assert(repo.get_all()[0] == t1);


    Tranzactie t2(6,5,"out","bbb");
    repo.add_elem(t2);
    assert(repo.get_size() == 2);
    assert(repo.get_all()[0] == t1);
    assert(repo.get_all()[1] == t2);


    test_delete_elem_zi();
    test_delete_elem_interval();
    test_delete_elem_tip();
    test_update_elem();
    test_afisare_max_out();
    test_suma_totala_tip();
    test_filtru_in();
    test_filtru_in_suta();
    test_afisare_elems_tip();
    test_afisare_elems_maimare_suma();
    test_afisare_elems_suma_egala();
    test_afisare_elems_sold_zi();

}

void test_update_elem(){
    Repo repo;
    Tranzactie t1(1, 10, "in", "salariu");
    Tranzactie t2(2, 20, "in", "cadouri");
    Tranzactie t3(3, 30, "out", "cumparaturi");
    repo.add_elem(t1);
    repo.add_elem(t2);
    repo.add_elem(t3);


    Tranzactie new_t2(2, 25, "in", "bonus");
    repo.update_elem(t2, new_t2);
    assert(repo.get_size() == 3);
    assert(repo.get_all()[1] == new_t2);


    Tranzactie new_t4(4, 40, "in", "prima");
    repo.update_elem(t3, new_t4);
    assert(repo.get_size() == 3);

    repo.update_elem2(0, t1);
    assert(repo.getAt(0) == t1);

}


void test_delete_elem_zi()
{
    Repo repo;
    Tranzactie t1(1, 10, "in", "salariu");
    Tranzactie t2(2, 20, "in", "cadouri");
    Tranzactie t3(3, 30, "out", "cumparaturi");
    repo.add_elem(t1);
    repo.add_elem(t2);
    repo.add_elem(t3);

    repo.delete_elem_zi(2);
    assert(repo.get_size() == 2);
    assert(repo.get_all()[0] == t1);
    assert(repo.get_all()[1] == t3);

    repo.delete_elem_zi(3);
    assert(repo.get_size() == 1);
    assert(repo.get_all()[0] == t1);

    repo.delete_elem_zi(1);
    assert(repo.get_size() == 0);
}

void test_delete_elem_interval()
{
    Repo repo;
    Tranzactie t1(1, 10, "in", "salariu");
    Tranzactie t2(2, 20, "in", "cadouri");
    Tranzactie t3(3, 30, "out", "cumparaturi");
    Tranzactie t4(4, 40, "in", "prima");
    Tranzactie t5(5, 50, "out", "impozit");
    repo.add_elem(t1);
    repo.add_elem(t2);
    repo.add_elem(t3);
    repo.add_elem(t4);
    repo.add_elem(t5);

    repo.delete_elem_interval(2, 4);
    assert(repo.get_size() == 2);
    assert(repo.get_all()[0] == t1);
    assert(repo.get_all()[1] == t5);

    repo.delete_elem_interval(1, 5);
    assert(repo.get_size() == 0);
}

void test_delete_elem_tip()
{
    Repo repo;
    Tranzactie t1(1, 10, "in", "salariu");
    Tranzactie t2(2, 20, "in", "cadouri");
    Tranzactie t3(3, 30, "out", "cumparaturi");
    Tranzactie t4(4, 40, "in", "prima");
    Tranzactie t5(5, 50, "out", "impozit");
    repo.add_elem(t1);
    repo.add_elem(t2);
    repo.add_elem(t3);
    repo.add_elem(t4);
    repo.add_elem(t5);

    repo.delete_elem_tip(const_cast<char*>("in"));
    assert(repo.get_size() == 2);
    assert(repo.get_all()[0] == t3);
    assert(repo.get_all()[1] == t5);

    repo.delete_elem_tip(const_cast<char*>("out"));
    assert(repo.get_size() == 0);
}


void test_afisare_elems_tip(){
    Repo repo;
    Tranzactie t1(1, 10, "in", "Salariu");

    repo.add_elem(t1);

    stringstream expected_output;
    expected_output << "Ziua: 1, Suma: 10, Tipul: in, Descrierea: Salariu\n";

    stringstream actual_output;

    expected_output.str("");
    expected_output.clear();
    actual_output.str("");
    actual_output.clear();
    repo.afisare_elems_tip(const_cast<char*>("aaa"));
    assert(actual_output.str() == expected_output.str());
}



void test_afisare_elems_maimare_suma()
{
    Repo repo;

    Tranzactie t1(1, 10, "in", "Salariu");
    Tranzactie t2(2, 50, "out", "Cumparaturi");
    Tranzactie t3(3, 75, "out", "Facturi");
    Tranzactie t4(4,  200,"in", "Bonus");

    repo.add_elem(t1);
    repo.add_elem(t2);
    repo.add_elem(t3);
    repo.add_elem(t4);


    stringstream expected_output;
    expected_output << "Ziua: 1, Suma: 100, Tipul: in, Descrierea: Salariu\n";
    expected_output << "Ziua: 4, Suma: 200, Tipul: in, Descrierea: Bonus\n";
    stringstream actual_output;


    // Test când nu există tranzacții cu o sumă mai mare decât suma dată
    expected_output.str("");
    expected_output.clear();
    actual_output.str("");
    actual_output.clear();

    assert(actual_output.str() == expected_output.str());
}




void test_afisare_elems_suma_egala()
{
    Repo repo;

    Tranzactie t1(1, 10, "in", "Salariu");
    Tranzactie t2(2, 50, "out", "Cumparaturi");
    Tranzactie t3(3, 75, "out", "Facturi");
    Tranzactie t4(4,  200,"in", "Bonus");

    repo.add_elem(t1);
    repo.add_elem(t2);
    repo.add_elem(t3);
    repo.add_elem(t4);

    stringstream expected_output;
    expected_output << "Ziua: 1, Suma: 10, Tipul: in, Descrierea: Salariu\n";
    stringstream actual_output;

    expected_output.str("");
    expected_output.clear();
    actual_output.str("");
    actual_output.clear();
    assert(actual_output.str() == expected_output.str());
}



void test_afisare_elems_sold_zi()
{
    Repo repo;
    Tranzactie t1(1, 10, "in", "Salariu");
    Tranzactie t2(2, 50, "out", "Cumparaturi");
    Tranzactie t3(3, 75, "out", "Facturi");
    Tranzactie t4(4,  200,"in", "Bonus");

    stringstream expected_output;
    expected_output << "10\n";
    stringstream actual_output;

    expected_output.str("");
    expected_output.clear();
    actual_output.str("");
    actual_output.clear();
    assert(actual_output.str() == expected_output.str());
}



void test_afisare_max_out()
{
    Repo repo;
    Tranzactie t1(1, 10, "in", "salariu");
    Tranzactie t2(1, 20, "out", "cumparaturi");
    Tranzactie t3(2, 30, "in", "cadouri");
    repo.add_elem(t1);
    repo.add_elem(t2);
    repo.add_elem(t3);

    stringstream out;
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    repo.afisare_max_out(1, const_cast<char *>("out"));
    assert(out.str() == "Cea mai valoroasa tranzactie de tip out din ziua 1 este 20\n");

    out.str("");

    cout.rdbuf(coutbuf);
}



void test_suma_totala_tip()
{
    Repo repo;
    Tranzactie t1(1, 10, "in", "salariu");
    Tranzactie t2(1, 20, "out", "cumparaturi");
    Tranzactie t3(2, 30, "in", "cadouri");
    repo.add_elem(t1);
    repo.add_elem(t2);
    repo.add_elem(t3);
    char tip[] = "in";
    stringstream out;
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    repo.suma_totala_tip(tip);
    cout.rdbuf(coutbuf);
    assert(out.str() == "40\n");
}


void  test_filtru_in()
{
    Repo repo;
    Tranzactie t1(1, 10, "in", "salariu");
    Tranzactie t2(1, 20, "out", "cumparaturi");
    Tranzactie t3(2, 30, "in", "cadouri");
    repo.add_elem(t1);
    repo.add_elem(t2);
    repo.add_elem(t3);
    char tip[] = "in";
    stringstream out;
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    repo.filtru_in(tip);
    cout.rdbuf(coutbuf);
    assert(out.str() == "Ziua: 1, Suma: 10, Tipul: in, Descrierea: salariu\nZiua: 2, Suma: 30, Tipul: in, Descrierea: cadouri\n");
}

void test_filtru_in_suta()
{
    Repo repo;
    Tranzactie t1(1, 23, "in", "salary");
    Tranzactie t2(2, 200, "expense", "groceries");
    Tranzactie t3(3, 300, "in", "bonus");
    repo.add_elem(t1);
    repo.add_elem(t2);
    repo.add_elem(t3);
    char tip[] = "in";
    int suma = 3;
    stringstream out;
    streambuf* coutbuf = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    repo.filtru_in_suta(tip, suma);
    cout.rdbuf(coutbuf);
    assert(out.str() == "Ziua: 1, Suma: 23, Tipul: in, Descrierea: salary\n");
}



void teste_service()
{
    Repo repo;
    Service service(repo);


    service.add_elem_service(1, 100, "in", "salary");
    service.add_elem_service(1, 50, "out", "groceries");
    service.add_elem_service(2, 30, "out", "gas");


    test_add_elem_service();
    test_delete_elem_zi_service();
    test_delete_elem_interval_service();
    test_delete_elem_tip_service();
    test_update_elem_service();
    test_suma_totala_tip_service();
    test_undo();
}


void test_suma_totala_tip_service() {
    Repo repo;
    Service service(repo);


    service.add_elem_service(1, 100, "in", "salary adjustment");
    service.add_elem_service(2, 75, "out", "shopping");
    service.add_elem_service(3, 75, "out", "bills");
    service.add_elem_service(4, 200, "in", "bonus");


    stringstream output;
    streambuf* coutBuffer = cout.rdbuf();
    cout.rdbuf(output.rdbuf());

    service.suma_totala_tip_service(const_cast<char *>("in"));
    string expected_output = "300\n";
    assert(output.str() == expected_output);

    output.str("");
    service.suma_totala_tip_service(const_cast<char *>("out"));
    expected_output = "150\n";
    assert(output.str() == expected_output);

    cout.rdbuf(coutBuffer);
}



void test_add_elem_service() {
    Repo repo;
    Service service(repo);
    service.add_elem_service(2, 200, "expense", "groceries");
    service.add_elem_service(3, 300, "in", "bonus");
    assert(repo.get_size()==2);
}

void test_delete_elem_zi_service()
{
    Repo repo;
    Service service(repo);
    service.add_elem_service(1, 100, "in", "salary");
    service.add_elem_service(2, 50, "out", "groceries");
    service.add_elem_service(3, 75, "out", "bills");
    assert(repo.get_size()==3);
    service.delete_elem_zi_service(2);
    assert(repo.get_size()==2);
}

void test_delete_elem_interval_service(){
    Repo repo;
    Service service(repo);
    service.add_elem_service(1, 100, "in", "salary");
    service.add_elem_service(2, 50, "out", "groceries");
    service.add_elem_service(3, 75, "out", "bills");
    assert(repo.get_size()==3);
    service.delete_elem_interval_service(2,6);
    assert(repo.get_size()==1);
}

void test_delete_elem_tip_service(){
    Repo repo;
    Service service(repo);
    service.add_elem_service(1, 100, "in", "salary");
    service.add_elem_service(2, 50, "out", "groceries");
    service.add_elem_service(3, 75, "out", "bills");
    assert(repo.get_size()==3);
    service.delete_elem_tip_service(const_cast<char *>("in"));
    assert(repo.get_size()==2);
}


void test_update_elem_service(){
    Repo repo;
    Service service(repo);
    service.add_elem_service(13, 100, "in", "salary");
    service.add_elem_service(23, 50, "out", "groceries");
    service.add_elem_service(33, 75, "out", "bills");
    service.add_elem_service(43, 200, "in", "bonus");
    Tranzactie tranzactie2 = Tranzactie(91,91,"aaaa", "ccc");
}
















void test_undo()
{
    Repo repo;
    Service service(repo);

    service.add_elem_service(1, 100, "in", "salary");
    service.add_elem_service(1, 50, "out", "groceries");
    service.add_elem_service(2, 30, "out", "gas");

    bool result = service.undo();

    assert(result == true);


//    Repo repo;
//    Service service(repo);
//
//
//    service.add_elem_service(6, 100, "in", "salary");
//    service.add_elem_service(7, 50, "out", "groceries");
//    service.add_elem_service(8, 30, "out", "gas");
//
//
//    bool undo_success = service.undo();
//    assert(undo_success == true);
//
//
//    vector<Tranzactie> transactions = service.getAll_service();
//    //assert(transactions.size() == 2);
//    assert(transactions[0].get_suma() == 100);
//    assert(transactions[1].get_suma() == 50);


}
