#include <stdio.h>
#include <stdlib.h>

double f_seno(double x, int n)
{
	return 0;
}

int main(int argc, char  *argv[])
{
	int n;
	double x, sx;
	if(argc!=3)
		return -1;
	x = atof(argv[1]);
	n = atoi(argv[2]);
	sx = f_seno(x, n);
	printf("%lf = sin(%lf, %d)\n", sx, x, n);
	return 0;
}