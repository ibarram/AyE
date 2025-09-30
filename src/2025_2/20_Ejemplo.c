#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int i;
	lt1 *pH, *pN;
	pH = NULL;
	do{
		pN = crearNodo(pH);
		printf("Ingrese el valor de x: ");
		scanf("%f", &(pN->x));
		pH = unir_lt(pH, pN, 2);
	}while(pN->x>=0);
	imprimir_lt(pH);
	liberar_lt(pH);
	return 0;
}