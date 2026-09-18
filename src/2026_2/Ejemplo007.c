#include<stdio.h>
#include"libarram.h"

#define N 1000

int main(int argc, char *argv[])
{
	int n, min, max;
	int x[N];
	do{
		printf("Ingrese el numero de muestras: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	printf("Minimo: ");
	scanf("%d", &min);
	printf("Maximo: ");
	scanf("%d", &max);
	if(min>max)
		swap(&min, &max);
	if(du_sr(x, n, max, min, 123)!=0)
		return 1;
	imprimir(x, n);
	printf("Media = %f\n", media(x, n));
	printf("Varianza = %f\n", varianza(x, n));
	printf("a = %d\n", limite_inf(x, n));
	printf("b = %d\n", limite_sup(x, n));
	printf("#x = %d\n", cardinalidad(x, n));
	return 0;
}