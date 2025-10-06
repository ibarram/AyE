#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int i, op;
	lt2 *pH, *pN;
	printf("Selecciones el orden: ");
	scanf("%d", &op);
	pH = NULL;
	do{
		pN = crearNodo2(pH);
		printf("Ingrese el valor de x: ");
		scanf("%f", &(pN->x));
		pH = unir_lt2(pH, pN, op<2);
	}while(pN->x>=0);
	pH = op?inicio(pH):fin(pH);
	imprimir_lt2(pH, op);
	liberar_lt2(pH);
	return 0;
}