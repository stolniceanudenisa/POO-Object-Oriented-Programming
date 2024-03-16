
#include "Service.h"

bool Service::findByCode(int code) {
    for (auto prod : repo.getAll())
        if (prod.first.getCod() == code)
            return true;
    return false;
}

void Service::addProd(int code, string nume, int pret, int nrUnit) {
    if (!findByCode(code)) {
        Produs p(code, nume, pret);
        pair<Produs, int> prod(p, nrUnit);
        repo.addEntity(prod);
    }
}

Service::Service(RepositoryFile& repo) {
    this->repo = repo;
}

Service::Service() {

}

Service& Service::operator=(const Service& service) {
    if (this != &service) {
        this->buget = 500;
        this->repo = service.repo;
    }
    return *this;
}

vector<pair<Produs, int>> Service::getAll() {
    return this->repo.getAll();
}

void Service::updateBuget(int buget) {
    this->buget = this->buget + buget;
}

int Service::getBuget() {
    return this->buget;
}

 
void Service::updateProd(int cod, string nume, int pret, int nrUnit) {
    for (int i = 0; i < repo.size(); i++) {
        if (repo.getAt(i).first.getCod() == cod) {
            cout << 1;
            Produs p(cod, nume, pret);
            pair<Produs, int> prod(p, nrUnit);
            Produs p1(repo.getAt(i).first);
            pair<Produs, int> prod2(p1, repo.getAt(i).second);
            repo.updateEntity(prod2, prod);
        }
    }
}

vector<pair<Produs, int>> Service::sortPrice() {
    vector<pair<Produs, int>> v;
    v = repo.getAll();
    for (int i = 0; i < repo.size() - 1; i++)
        for (int j = i + 1; j < repo.size(); j++) {
            if (v[i].first.getPret() > v[j].first.getPret()) {
                pair<Produs, int> aux(v[i].first, v[i].second);
                v[i] = v[j];
                v[j] = aux;
            }
        }
    return v;
}

vector<pair<Produs, int>> Service::sortUnit() {
    vector<pair<Produs, int>> v;
    v = repo.getAll();
    for (int i = 0; i < repo.size() - 1; i++)
        for (int j = i + 1; j < repo.size(); j++) {
            if (v[i].second > v[j].second) {
                pair<Produs, int> aux(v[i].first, v[i].second);
                v[i] = v[j];
                v[j] = aux;
            }
        }
    return v;
}

vector<pair<Produs, int>> Service::lowPrice(int price) {
    vector<pair<Produs, int>> v;
    for (auto prod : repo.getAll()) {
        if (prod.first.getPret() <= price)
            v.push_back(prod);
    }
    return v;
}

void Service::deleteProd(int cod) {
    for (int i = 0; i < repo.size(); i++) {
        if (repo.getAt(i).first.getCod() == cod) {
            repo.delEntity(repo.getAt(i));
            i = repo.size();
        }
    }
}

int Service::buyProdus(int cod, int& buget) {
    if (findByCode(cod)) {
        for (int i = 0; i < repo.size(); i++) {
            if (repo.getAt(i).first.getCod() == cod) {
                if (repo.getAt(i).second < 1)
                    return -2;
                else {
                    pair<Produs, int> prod1 = repo.getAt(i);
                    Produs p = repo.getAt(i).first;
                    pair<Produs, int> prod2(p, repo.getAt(i).second - 1);
                    repo.updateEntity(prod1, prod2);
                    if (buget - repo.getAt(i).first.getPret() >= 0) {
                        buget = buget - repo.getAt(i).first.getPret();
                        updateBuget(buget + repo.getAt(i).first.getPret());
                        return buget;
                    }
                    else {
                        return -3;
                    }
                }
            }
        }
    }
    else
        return -1;
}