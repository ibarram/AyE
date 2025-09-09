#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	float **A, **B, **C;
	int nA, mA, nB, mB;
	do{
		printf("Ingrese el numero de renglones de A: ");
		scanf("%d", &nA);
		printf("Ingrese el numero de columnas de A: ");
		scanf("%d", &mA);
	}while(nA<1||mA<1);
	A = CrearMatrizO(nA, mA);
	if(A==NULL)
		return 1;
	imprimirMat(A, nA, mA, "A");
	do{
		printf("Ingrese el numero de renglones de B: ");
		scanf("%d", &nB);
		printf("Ingrese el numero de columnas de B: ");
		scanf("%d", &mB);
	}while(nB<1||mB<1);
	B = CrearMatrizD(nB, mB);
	if(B==NULL)
	{
		liberarO(A);
		return 2;
	}
	imprimirMat(B, nB, mB, "B");
	C = multiplicarMat(A, nA, mA, B, nB, mB);
	imprimirMat(C, nA, mB, "C");
	liberarO(A);
	liberarD(B, nB);
	return 0;
}