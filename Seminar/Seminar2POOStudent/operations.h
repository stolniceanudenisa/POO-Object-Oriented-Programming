#pragma once
#include "Student.h"
#include "Repo.h"
void filterStudents(Student students[], int n,
	const char* s, int a, Student studFilter[], int& m);
void filterStudentsWithRepo(Repo& rep, const char* s,
	int a, Student studFilter[], int& m);