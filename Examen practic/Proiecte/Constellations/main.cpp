#include "GUI.h"
#include <QtWidgets/QApplication>

#include "Service.h"
#include "Model.h"



void testAdd()
{
    Repository<int> repo{ "TestRepo.txt" };

    repo.add(13);
    assert(repo.getAll()[repo.getAll().size() - 1] == 13);
}

int main(int argc, char* argv[])
{
    testAdd();  // for repo
    testAddStar();
    testAddStarException();   // for service (implemented in service.cpp + specifications service.h)

    QApplication a(argc, argv);

    Repository<Astronomer> repo1{ "Astronomers.txt" };
    Repository<Star> repo2{ "Stars.txt" };
    Service service{ repo1, repo2 };

    Model* model = new Model{ repo2 };
    
    std::vector<Star> s = service.getStars();

    std::vector<Astronomer> astro = service.getAstronomers();
    for (auto a : astro)
    {
        GUI* w = new GUI{ a, service, model };
        w->show();
    }

    return a.exec();
}


