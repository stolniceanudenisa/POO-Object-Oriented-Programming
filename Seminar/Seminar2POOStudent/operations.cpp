#include "operations.h"
#include <string.h>


// filter all the students of a given name and older than a given limit
// In: an array of students and their number (integer), a name (String), an age (integer)
// Out: an array of filtered students and their number (integer)
void filterStudents(Student students[], int n, const char* s, int a, Student studFilter[], int& m) {
	m = 0;
	for (int i = 0; i < n; i++) {
		if ((strcmp(s, students[i].get_name()) == 0) && (students[i].get_age() >= a)) {
			studFilter[m++] = students[i];
		}
	}

}
// filter all the students of a given name and older than a given limit
// In: an array of students and their number (integer), a name (String), an age (integer)
// Out: an array of filtered students and their number (integer)
void filterStudentsWithRepo(Repo& rep, const char* s, int a, Student studFilter[], int& m) {
	for (int i = 0; i < rep.getSize(); i++) {
		Student crtStudent = rep.getItemFromPos(i);
		if ((strcmp(s, crtStudent.get_name()) == 0) && (crtStudent.get_age() >= a)) {
			studFilter[m++] = crtStudent;
		}
	}
}