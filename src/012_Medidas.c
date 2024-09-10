#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "libarram.h"

#define N 1000

int main(int argc, char *argv[])
{
	int n;
	float min, max, x[N], md1, md2, vr1, vr2;
	srand(time(NULL));
	do{
		scanf("%d %f %f", &n, &max, &min);
	}while(n<0||n>N);
	if(min>max)
	{
		max*=min;
		min=max/min;
		max/=min;
	}
	generar(x, n, min, max);
	imprimir(x, n);
	//imprimir2(x, n);
	md1 = media1(x, n);
	printf("Media = %f\n", md1);
	md2 = media2(x, n);
	printf("Media = %f\n", md2);
	vr1 = varianza1(x, n);
	printf("Varianza = %f\n", vr1);
	vr2 = varianza2(x, n);
	printf("Varianza = %f\n", vr2);
	return 0;
}