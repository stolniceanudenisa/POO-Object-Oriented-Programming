#include "teste.h"

void Teste::testdomain()
{
	Hotel h;
	assert(h.getcamerasingle() == 0);
	assert(h.getcameradubla() == 0);
	assert(h.getapartament() == 0);
	assert(h.getcheckindate() == 0);
	assert(h.getnrzile() == 0);
	Hotel h1(1, 2, 3, 4, 5);
	assert(h1.getcamerasingle() == 1);
	assert(h1.getcameradubla() == 2);
	assert(h1.getapartament() == 3);
	assert(h1.getcheckindate() == 4);
	assert(h1.getnrzile() == 5);
	Hotel h2(h1);
	assert(h2.getcamerasingle() == 1);
	assert(h2.getcameradubla() == 2);
	assert(h2.getapartament() == 3);
	assert(h2.getcheckindate() == 4);
	assert(h2.getnrzile() == 5);
	h2.setcamerasingle(10);
	h2.setcameradubla(20);
	h2.setapartament(30);
	h2.setcheckindate(40);
	h2.setnrzile(50);
	assert(h2.getcamerasingle() == 10);
	assert(h2.getcameradubla() == 20);
	assert(h2.getapartament() == 30);
	assert(h2.getcheckindate() == 40);
	assert(h2.getnrzile() == 50);
	assert(h1.to_string() == "1 2 3 4 5");
}

void Teste::testrepo()
{
}

void Teste::testservice()
{
}

void Teste::testvalidator()
{
}

void Teste::run_all()
{
}
