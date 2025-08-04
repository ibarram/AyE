#include <stdio.h>
#include <stdlib.h>

double f_seno(double x, int n)
{
	int i;
	float sx, fct;
	for(i=0, fct=x, sx=0; i<n; i++)
	{
		sx+=((2*((i+1)%2)-1)*fct);
		fct*=(x/(2*i+2))*(x/(2*i+3));
		printf("%d\t%d\t%d\t%d\t%lf\t%lf\n", i, 2*((i+1)%2)-1, 2*i+2, 2*i+3, fct, sx);
	}
	return sx;
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