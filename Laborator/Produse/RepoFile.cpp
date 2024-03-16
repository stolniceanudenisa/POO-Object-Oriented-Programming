//
// Created by 40766 on 05.05.2023.
//
#include "RepoFile.h"
#include "produs.h"
#include <fstream>
#include <sstream>

//RepoFile::RepoFile(string fileName, ValidatorProdus* validator) : Repo(validator)
//{
//    this->fileName = fileName;
//    this->loadFromFile();
//}


RepoFile::RepoFile(string fileName)
{
    this->fileName = fileName;
    this->loadFromFile();
}



RepoFile::~RepoFile()
{
}

void RepoFile::addProdus(Produs* p)
{
    Repo::addProdus(p);
    this->saveToFile();
}


void RepoFile::loadFromFile()
{
    ifstream f(this->fileName);
    if (f.is_open()) {
        string line;
        while (getline(f, line)) {
            stringstream ss(line);
            string id_str, nume, pret_str;
            getline(ss, id_str, ',');
            getline(ss, nume, ',');
            getline(ss, pret_str, ',');
            int id = stoi(id_str);
            double pret = stod(pret_str);
            this->addProdus(new Produs(id, nume, pret));
        }
        f.close();
    }

//    ifstream f(this->fileName);
//    if (f.is_open())
//    {
//        string linie;
//        Produs* p = nullptr;
//        while (!f.eof())
//        {
//            getline(f, linie);
//            // if (linie != "") -> ca sa nu mai prelucreze si ultima linie, care este goala
//            if (linie.find("P") == 0)
//            {
//                p = new Produs();
//            }
//
//            if (p != nullptr)
//            {
//                p->read(linie);
//                Repo::addProdus(p);
//                delete p;
//                p = nullptr;
//            }
//        }
//        f.close();
//    }

//        ifstream fin(fileName);
//        if (fin.is_open()) {
//            string line;
//            while (getline(fin, line)) {
//                stringstream ss(line);
//                int cod, pret;
//                string nume;
//                ss >> cod >> nume >> pret;
//                Produs* p = new Produs(cod, nume, pret);
//                Repo::addProdus(p);
//            }
//            fin.close();
//    }

}

void RepoFile::saveToFile()
{
    ofstream f(this->fileName);
    if (f.is_open()) {
        const auto& produse = this->getAll();
        for (const auto& produs : produse) {
            f << produs->getCod() << ',' << produs->getNume() << ',' << produs->getPret() << '\n';
        }
        f.close();
    }



//    ofstream f(this->fileName);
//    for (int i = 0; i < this->produse.size(); i++)
//    {
//        f << this->produse[i]->write() << endl;
//    }
//    f.close();

//    ofstream fout(this->fileName);
//    if (fout.is_open()) {
//        for (auto p : Repo::getAll()) {
//            fout << p->getCod() << " " << p->getNume() << " " << p->getPret() << endl;
//        }
//        fout.close();
//    }

}