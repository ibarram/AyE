#include <stdio.h>
#include "libreria.h"

int main(int argc, char *argv[])
{
	long int n, fn1, fn2;
	do{
		printf("Ingrese el termino: ");
		scanf("%ld", &n);
	}while(n<0);
	fn1 = Fibonacci_BU(n);
	fn2 = Fibonacci_TD(n);
	printf("F(%ld) = %ld\n", n, fn1);
	printf("F(%ld) = %ld\n", n, fn2);
	return 0;
}