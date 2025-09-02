#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	Complejo Z1, Z2, Z3;
	printf("Ingrese el valor real: ");
	scanf("%f", &(Z1.a));
	printf("Ingrese el valor imaginario: ");
	scanf("%f", &(Z1.b));
	printf("Ingrese el valor real: ");
	scanf("%f", &(Z2.a));
	printf("Ingrese el valor imaginario: ");
	scanf("%f", &(Z2.b));
	Z3 = sumaC(Z1, Z2);
	printf("Z3 = %f%+fi\n", Z3.a, Z3.b);
	return 0;
}