#include<stdio.h>
#include"libarram.h"

int main(int argc, char *argv[])
{
	float a, b, r;
	printf("Ingrese el valor de a: ");
	scanf("%f", &a);
	printf("Ingrese el valor de B: ");
	scanf("%f", &b);
	r = suma(a, b);
	printf("%f%+f=%f", a, b, r);
	return 0;
}