#include <stdio.h>

int flog2(int x);

int main(int argc, char *argv[])
{
	int x, lx;
	x = 8;
	lx = flog2(x);
	printf("log2(%d) = %d\n", x, lx);
	x = 32;
	lx = flog2(x);
	printf("log2(%d) = %d\n", x, lx);
	return 0;
}

int flog2(int x)
{
	static int n = 0;
	int n2;
	if(x)
	{
		n++;
		return flog2(x>>1);
	}
	else
	{
		n2 = n;
		n = 0;
		return n2-1;
	}
}
