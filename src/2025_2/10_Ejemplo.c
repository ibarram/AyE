#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int n, min, max, *d, eN;
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1);
	printf("Ingrese el maximo: ");
	scanf("%d", &max);
	printf("Ingrese el minimo: ");
	scanf("%d", &min);
	if(max<min)
		SWAP(max, min);
	printf("[%d, %d]\n", min, max);
	d = DU(n, min, max);
	//imprimir_DU(d, n);
	eN = estN(d, n);
	printf("N = %d\n", eN);
	free(d);
	return 0;
}