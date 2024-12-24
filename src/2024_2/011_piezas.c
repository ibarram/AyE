#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "libarram.h"

#define N_max 1000000

int main(int argc, char *argv[])
{
	unsigned long int i, a, b, ae, be, n, ne, x[N_max], nm;
	double mx, s2;
	srand(time(NULL));
	printf("Ingrese el valor inicial: ");
	scanf("%lu", &a);
	printf("Ingrese el valor final: ");
	scanf("%lu", &b);
	n = b-a+1;
	printf("Producidas: %lu\n", n);
	printf("Numero de muestras: ");
	scanf("%lu", &nm);
	for(i=0; i<nm; i++)
		x[i] = rand()%(b-a+1)+a;
	for(i=1, mx=x[0]; i<nm; i++)
		mx+=x[i];
	mx/=nm;
	for(i=1, s2=x[0]*x[0]; i<nm; i++)
		s2+=(x[i]*x[i]);
	s2/=nm;
	s2-=(mx*mx);
	ae = floor(mx+.5-sqrt(12*s2+1)/2);
	be = ceil(mx-.5+sqrt(12*s2+1)/2);
	ne = be-ae+1;
	printf("Numero de piezas: %lu\n", ne);
	return 0;
}
