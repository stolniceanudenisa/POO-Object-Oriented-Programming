#include "subalg2.h"
int prim(int x)
{
	if (x < 2 || x>2 && x % 2 == 0)
		return 0;
	for (int d = 2; d * d <= x; d ++)
		if (x % d == 0)
			return 0;
	return 1;

}

int primulPrim(int x)
{
	int y = x + 1;
	while (prim(y) == 0)
		y++;
	return y;
}
