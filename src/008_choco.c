#include<stdio.h>
#include"libarram.h"

int main(int argc, char *argv[])
{
	int X, Y, A, B, Z;
	scanf("%d %d %d %d", &X, &Y, &A, &B);
	Z = chocolate(X, Y, A, B);
	printf("%d\n", Z);
}