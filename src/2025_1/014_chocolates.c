#include <stdio.h>

int cambio(int E, int A, int B, int* pE)
{
	int Zi;
	Zi = (E/A)*B;
	if(Zi)
		*pE = E-(Zi*A)/B;
	return Zi?Zi+cambio(Zi+E-(Zi*A)/B,A,B,pE):0;
}

int chocolate(int X, int Y, int A, int B, int *pE)
{
	return X/Y+cambio(X/Y,A,B,pE);
}

int main(int argc, char *argv[])
{
	int X, Y, A, B, pE, T;
	scanf("%d %d %d %d", &X, &Y, &A, &B);
	T = chocolate(X, Y, A, B, &pE);
	printf("T = %d\nE = %d\n", T, pE);
	return 0;
}