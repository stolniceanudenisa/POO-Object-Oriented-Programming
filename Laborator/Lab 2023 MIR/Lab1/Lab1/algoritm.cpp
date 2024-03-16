int prim(int x)
{
	if (x < 2 || x>2 && x % 2 == 0)
		return 0;
	for (int d = 2; d * d <= x; d++)
		if (x % d == 0)
			return 0;
	return 1;
}


void factoriprimi(int n, int& p1, int& p2)
{
    p1 = p2 = 0;
    for (int i = 2; i <= n / 2; i++)
    {
        if (prim(i) && prim(n - i))
        {
            p1 = i;
            p2 = n - i;
            return;
        }
    }
}
