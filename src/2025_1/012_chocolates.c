#include <stdio.h>

int cambio(int E, int A, int B)
{
	int Zi;
	Zi = (E/A)*B;
	return Zi?Zi+cambio(Zi+E-(Zi*A)/B,A,B):0;
}
int chocolate(int X, int Y, int A, int B)
{
	return X/Y+cambio(X/Y,A,B);
}

int main(int argc, char *argv[])
{
	int X, Y, A, B, T;
	scanf("%d %d %d %d", &X, &Y, &A, &B);
	T = chocolate(X, Y, A, B);
	printf("T = %d\n", T);
	return 0;
}