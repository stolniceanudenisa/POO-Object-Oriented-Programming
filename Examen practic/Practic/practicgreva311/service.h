#pragma once
#include "repofile.h"

class Service {
private:
	RepoFile& repo;
public:
	Service(RepoFile& repo);
	vector<Profesor> getAll();
	void addProfesor(string nume, string disciplina, string clase, string greva);
	~Service();

	int nr_profesori_greva();
	vector<Profesor> disciplina_cu_cei_mai_multi_profi_greva();
	// clasa cu cei mai multi profesori in greva
	vector<Profesor> clasa_cu_cei_mai_multi_profi_greva();

};