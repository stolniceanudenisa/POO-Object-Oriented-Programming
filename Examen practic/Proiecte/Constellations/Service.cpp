#include "Service.h"
#include <assert.h>

using namespace std;

void Service::addStar(std::string name, std::string constellation, int RA, int Dec, int diam)
{
	Star star{ name, constellation, RA, Dec, diam };
	if (stars.checkExisting(star))
	{
		throw exception("Star already exists");
	}
	stars.add(star);
}

std::vector<Star> Service::searchStar(std::string name)
{
	std::vector<Star> found;
	std::vector<Star> all = this->stars.getAll();

	for (auto a : all)
	{
		if (a.getName().find(name) != std::string::npos )
			found.push_back(a);
		//if (str == a.getCategory() || str == a.getName())
			//found.push_back(a);
	}

	return found;
}

std::vector<Star> Service::getStarsByConstellation(std::string c)
{
	vector<Star> stars = this->stars.getAll();
	vector<Star> filtered;

	for (auto s : stars)
	{
		if (s.getConstellation() == c)
			filtered.push_back(s);
	}
	return filtered;
}

void testAddStar()
{
	std::ofstream file{ "Test.txt" };
	file << "";

	Repository<Star> repo{"Test.txt"};
	Repository<Astronomer> repo2{"Test.txt"};
	Service service{ repo2, repo };

	try {
		service.addStar("A", "b", 12, 12, 12);
		assert(service.getStars().size() == 1);
		assert(service.getStars()[0].getName() == "A");
	}
	catch (exception& ex)
	{
		return;   // this is in case the file Test is already created
	}
}

void testAddStarException()
{
	Repository<Star> repo{ "Test.txt" };
	Repository<Astronomer> repo2{ "Test.txt" };
	Service service{ repo2, repo };

	try
	{
		service.addStar("A", "b", 56, 56, 56);
		assert(false);
	}
	catch (exception& ex)
	{
		assert(strcmp(ex.what(), "Star already exists") == 0);
		assert(true);
	}
}
