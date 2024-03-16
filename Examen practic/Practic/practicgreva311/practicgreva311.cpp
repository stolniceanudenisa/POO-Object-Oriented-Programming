 #include <iostream>
#include"profesor.h"
#include"repofile.h"
#include"validator.h"
#include"teste.h"
#include"service.h"
#include "ui.h"
#include <string>
using namespace std;


int main()
{
  	Teste t;
	t.run_all();
	cout << "Testele au trecut! " << '\n';
	Validator validator;
	RepoFile repo("profesori.txt", validator);
	Service service(repo);
	UI ui(service);
	ui.run_menu();
	 
	return 0;
}
 