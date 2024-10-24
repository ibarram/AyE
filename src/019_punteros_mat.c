#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int NC, NR, MC, MR;
	float **A, **B;
	printf("Ingrese el numero de columnas: ");
	scanf("%d", &NC);
	printf("Ingrese el numero de renglones: ");
	scanf("%d", &NR);
	A = crearMC(NC, NR);
	printf("Ingrese el numero de columnas: ");
	scanf("%d", &MC);
	printf("Ingrese el numero de renglones: ");
	scanf("%d", &MR);
	B = crearMD(MC, MR);
	return 0;
}
