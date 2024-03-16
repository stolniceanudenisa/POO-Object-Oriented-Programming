
#include "service.h"
#include <cstring>

Service::Service(Repo &repo): repo(repo) {

}

Service::~Service()  {

}

vector<Tranzactie> Service::getAll_service() {
    repo.get_all();
}


int Service::get_size_service() {
    repo.get_size();
}


void Service::afisare_elemente_toate() {
    return this->repo.afisare_elems();

}


void Service::afisare_elems_tip_service(char* tip) {
    return repo.afisare_elems_tip(tip);
}

void Service::afisare_elems_maimare_suma_service(int suma) {
    return repo.afisare_elems_maimare_suma(suma);
}

void Service::afisare_elems_suma_egala_service(int suma) {
    return repo.afisare_elems_suma_egala(suma);
}


void Service::afisare_elems_sold_zi_service(int ziua) {
    return repo.afisare_elems_sold_zi(ziua);
}

void Service::suma_totala_tip_service(char *tip) {
    return repo.suma_totala_tip(tip);
}


void Service::filtru_in_service(char *tip) {
    return repo.filtru_in(tip);
}

void Service::filtru_in_suta_service(char *tip, int suma) {
    return repo.filtru_in_suta(tip, suma);
}



void Service::add_elem_service(int ziua, int suma, const char *tip, const char *descriere) {
    Tranzactie tr(ziua, suma, tip, descriere); // asta trebuie.

    vector<Tranzactie> oldList(repo.get_all(), repo.get_all() + repo.get_size()); // copiem tranzactiile existente

    repo.add_elem(tr);  // asta trebuie.

    vector<Tranzactie> newList(repo.get_all(), repo.get_all() + repo.get_size()); // copiem tranzactiile updatate

    history.push(oldList);


}

void Service::delete_elem_zi_service(int ziua) {

    vector<Tranzactie> oldList(repo.get_all(), repo.get_all() + repo.get_size()); // copiem tranzactiile existente

    repo.delete_elem_zi(ziua); // asta trebuie

    vector<Tranzactie> newList(repo.get_all(), repo.get_all() + repo.get_size()); // copiem tranzactiile updatate

    history.push(oldList);
}



void Service::delete_elem_interval_service(int ziuai, int ziuaf) {

    vector<Tranzactie> oldList(repo.get_all(), repo.get_all() + repo.get_size());

    repo.delete_elem_interval(ziuai,ziuaf); // asta trebuie atat

    vector<Tranzactie> newList(repo.get_all(), repo.get_all() + repo.get_size());

    history.push(oldList);
}



void Service::delete_elem_tip_service( char *tip) {
    //repo.delete_elem_tip(const_cast<char *>(tip));

    vector<Tranzactie> oldList(repo.get_all(), repo.get_all() + repo.get_size());

    repo.delete_elem_tip(tip);  // asta trebuie atat

    vector<Tranzactie> newList(repo.get_all(), repo.get_all() + repo.get_size());

    history.push(oldList); // push old list onto history stack
}



void Service::update_elem_service(const Tranzactie &oldtr, const Tranzactie &newtr) {
//    Tranzactie* oldList = new Tranzactie[repo.get_size()];
//    for (int i = 0; i < repo.get_size(); i++) {
//        oldList[i] = repo.get_all()[i];
//    }
    vector<Tranzactie> oldList(repo.get_all(), repo.get_all() + repo.get_size());
    repo.update_elem(oldtr,newtr); // doar atat

    vector<Tranzactie> newList(repo.get_all(), repo.get_all() + repo.get_size());

    history.push(oldList); // push old list onto history stack

//    Tranzactie* newList = repo.get_all();
//    history.push(vector<Tranzactie>(oldList, oldList + repo.get_size()));
//    delete[] oldList;
//    delete[] newList;
}



void Service::update_elem_service2(int pos, int ziua, int suma, char *tip, char* descriere) {
    Tranzactie elem = Tranzactie(ziua,suma,tip,descriere);
    this->repo.update_elem2(pos, elem);
}





void Service::afisare_max_out_service(int ziua, char* tip) {
    return repo.afisare_max_out(ziua,tip);
}




bool Service::undo() {
    if (history.empty()) {
        cout << "Nothing to undo!" << endl;
        return false;
    }
    vector<Tranzactie> oldList = history.top();
    history.pop();
    repo.set_all(oldList);
    //cout << "Undo successful!" << endl;
    return true;
}









void Service::pt_inloc_suma(int ziua, int suma, char* tip, char* descriere) {
    vector<Tranzactie> trList = getAll_service();
    for (int i = 0; i < trList.size(); i++)
    {

        cout<<trList[i]<<endl;
        if (trList[i].get_ziua() == ziua && strcmp(trList[i].get_tip(), tip) == 0 &&
            strcmp(trList[i].get_descriere(), descriere) == 0) {
            Tranzactie t2(ziua, suma, tip, descriere);
            repo.update_elem(trList[i], t2);
            cout << "Tranzactia a fost actualizata cu succes!" << endl;
            return;
        }
    }

    cout << "Nu exista o tranzactie cu aceste date!" << endl;
}
