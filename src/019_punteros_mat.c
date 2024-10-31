#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int NC, NR, MC, MR;
	float **A, **B, **C;
	printf("Ingrese el numero de columnas: ");
	scanf("%d", &NC);
	printf("Ingrese el numero de renglones: ");
	scanf("%d", &NR);
	A = crearMC(NR, NC);
	printf("Ingrese el numero de columnas: ");
	scanf("%d", &MC);
	printf("Ingrese el numero de renglones: ");
	scanf("%d", &MR);
	B = crearMD(MR, MC);
	C = crearMC(NR, MC);
	capturarM(A, NR, NC);
	printf("-----------\n");
	imprimirM(A, NR, NC);
	capturarM(B, MR, MC);
	printf("-----------\n");
	imprimirM(B, MR, MC);
	multiplicar(A, B, C, NR, NC, MR, MC);
	printf("-----------\n");
	imprimirM(C, NR, MC);
	liberarC(A);
	liberarD2(B, MR);
	liberarC(C);
	return 0;
}
