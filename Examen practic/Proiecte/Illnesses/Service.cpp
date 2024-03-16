#include "Service.h"

std::vector<Item> Service::search(std::string str)
{
	std::vector<Item> found;
	std::vector<Item> all = this->repository.get_all();

	for (auto a : all)
	{
		if (a.getCategory().find(str)!=std::string::npos || a.getName().find(str)!=std::string::npos)
			found.push_back(a);
		//if (str == a.getCategory() || str == a.getName())
			//found.push_back(a);
	}

	return found;
}
