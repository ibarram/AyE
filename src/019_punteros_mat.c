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
	A = crearMC(NC, NR);
	capturarM(A,NC,NR);
	imprimirM(A,NC,NR);
	printf("Ingrese el numero de columnas: ");
	scanf("%d", &MC);
	printf("Ingrese el numero de renglones: ");
	scanf("%d", &MR);
	B = crearMC(MC, MR);
	capturarM(B,MC,MR);
	imprimirM(B,MC,MR);

	C = crearMC(MC, NR);

	multiplicarM(A,B,C,NC,NR,MC,MR);
	printf("multiplicacion es igual a :\n");
	imprimirM(C,MC,NR);
	freeMC(A);

	freeMC(C);

	freeMD2(B, MC);
	
	return 0;
}