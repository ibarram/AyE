#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	long int n, fn;
	do{
		printf("Ingrese el valor de n: ");
		scanf("%ld", &n);
	}while(n<0);
	fn = factorial(n);
	printf("%ld!=%ld\n", n, fn);
	return 0;
}