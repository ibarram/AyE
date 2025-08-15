#include<stdio.h>
#include"libarram.h"

int main(int argc, char *argv[])
{
	float a, b, c;
	printf("Ingrese el valor de a: ");
	scanf("%f", &a);
	printf("Ingrese el valor de b: ");
	scanf("%f", &b);
	c = suma(a,b);
	printf("%f%+f=%f\n", a, b, c);
	return 0;
}