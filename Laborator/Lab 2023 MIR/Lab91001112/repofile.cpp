#include "repofile.h"
#include <fstream>

using namespace std;

RepositoryFile::RepositoryFile() {

}
RepositoryFile::RepositoryFile(string filename) {
    this->filename = filename;
    ifstream f(filename);
    while (!f.eof()) {
        int nrUnit, pret, cod;
        string nume;
        f >> nrUnit;
        f >> cod;
        f >> nume;
        f >> pret;
        Produs p(cod, nume, pret);
        pair<Produs, int> prod(p, nrUnit);
        elems.push_back(prod);
    }
    f.close();
}

void RepositoryFile::writeData() {
    ofstream f(filename);
    for (int i = 0; i < elems.size(); i++)
        f << elems[i].second << ' ' << elems[i].first.getCod() << ' ' << elems[i].first.getNume() << ' ' << elems[i].first.getPret() << endl;
    f.close();
}

int RepositoryFile::size()
{
   return Repository::size();
}

void RepositoryFile::addEntity(pair<Produs, int> entity) {
    Repository::addEntity(entity);
    this->writeData();
}

bool RepositoryFile::updateEntity(pair<Produs, int>& entity, pair<Produs, int>& new_entity) {
    bool res = Repository::updateEntity(entity, new_entity);
    this->writeData();
    return res;
}

bool RepositoryFile::delEntity(const pair<Produs, int>& old_entity) {
    bool res = Repository::delEntity(old_entity);
    this->writeData();
    return res;
}

bool RepositoryFile::findEntity(pair<Produs, int> entity) {
    return ~Repository::findEntity(entity);
}

RepositoryFile& RepositoryFile::operator=(const RepositoryFile& repo) {
    this->elems = repo.elems;
    this->filename = repo.filename;
    return *this;
}