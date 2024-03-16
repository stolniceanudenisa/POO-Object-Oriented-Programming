#pragma once

#include "Repository.h"

class Service
{
	Repository<Astronomer>& astro;
	Repository<Star>& stars;

public:
	Service(Repository<Astronomer>& r1, Repository<Star>& r2) : astro(r1), stars(r2) {}

	std::vector<Astronomer> getAstronomers() { return astro.getAll(); }
	std::vector<Star> getStars() { return stars.getAll(); }

	/*
	Function that adds a new star in the repository base on its attributes
		Input: attributes for the new star:
				- name:string
				- constellation:string
				- RA:int
				- Dec:int
				- diam:int -> the diameter
		Output: -
				the star is added in the repository of all stars
		Throws exception: if a star with this name already exists
	*/
	void addStar(std::string name, std::string constellation, int RA, int Dec, int diam);

	std::vector<Star> searchStar(std::string name);

	std::vector<Star> getStarsByConstellation(std::string c);
};




void testAddStar();
void testAddStarException();