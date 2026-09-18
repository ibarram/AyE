#include <stdio.h>
#include <time.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int n;
	float x, ex1, ex3, ex4;
	time_t t1, t2;
	double dt1, dt3, dt4;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	t1 = time(0);
	ex1 = exp1(x, n);
	t2 = time(0);
	dt1 = difftime(t2, t1);
	printf("exp(%f) = %f\t%lf\n", x, ex1, dt1);
	t1 = time(0);
	ex3 = exp3(x, n);
	t2 = time(0);
	dt3 = difftime(t2, t1);
	printf("exp(%f) = %f\t%lf\n", x, ex3, dt3);
	t1 = time(0);
	ex4 = exp4(x, n);
	t2 = time(0);
	dt4 = difftime(t2, t1);
	printf("exp(%f) = %f\t%lf\n", x, ex4, dt4);
	return 0;
}