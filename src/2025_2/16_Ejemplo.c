#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "libarram.h"

#define NP 4

int main(int argc, char *argv[])
{
	float **A, **B, **C;
	int nA, mA, nB, mB;
	float** (*f)(int, int);
	do{
		printf("Ingrese el numero de renglones de A: ");
		scanf("%d", &nA);
		printf("Ingrese el numero de columnas de A: ");
		scanf("%d", &mA);
	}while(nA<1||mA<1);
	f = nA<NP?CrearMatrizO:CrearMatrizD;
	A = f(nA, mA);
	if(A==NULL)
		return 1;
	capturarMat(A, nA, mA, "A");
	imprimirMat(A, nA, mA, "A");
	do{
		printf("Ingrese el numero de renglones de B: ");
		scanf("%d", &nB);
		printf("Ingrese el numero de columnas de B: ");
		scanf("%d", &mB);
	}while(nB<1||mB<1);
	B = f(nB, mB);
	if(B==NULL)
	{
		if(f==CrearMatrizO)
			liberarO(A);
		else
			liberarD(A, nA);
		return 2;
	}
	capturarMat(B, nB, mB, "B");
	imprimirMat(B, nB, mB, "B");
	C = multiplicarMat(A, nA, mA, B, nB, mB);
	if(C==NULL)
	{
		if(f==CrearMatrizO)
		{
			liberarO(A);
			liberarO(B);
		}
		else
		{
			liberarD(A, nA);
			liberarD(B, nB);
		}
		return 3;
	}
	imprimirMat(C, nA, mB, "C");
	if(f==CrearMatrizO)
	{
		liberarO(A);
		liberarO(B);
		liberarO(C);
	}
	else
	{
		liberarD(A, nA);
		liberarD(B, nB);
		liberarD(C, nA);
	}
	return 0;
}