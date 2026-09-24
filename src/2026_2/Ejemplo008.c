#include<stdio.h>
#include<stdlib.h>
#include"libarram.h"

#define N 4

int main(int argc, char *argv[])
{
	float altura[N] = {155, 165, 175, 185};
	int NP[N+1], m, i, M[N+1], id, c[N], b[N-1];
	float media, de, X;
	do{
		printf("Ingrese la estatura promedio: ");
		scanf("%f", &media);
	}while(media<1);
	do{
		printf("Ingrese la desviacion estandar: ");
		scanf("%f", &de);
	}while(de<0);
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &m);
	}while(m<1);
	srand(123);
	for(i=0; i<N+1; i++)
		M[i] = 0;
	for(i=0; i<m; i++)
	{
		X = fnormal(media, de);
		c[0] = X<altura[3];
		c[1] = X<altura[2];
		c[2] = X<altura[1];
		c[3] = X<altura[0];
		b[0] = !c[3]&c[2]|!c[1]&c[0];
		b[1] = !c[3]&c[1];
		b[2] = !c[0];
		id = (b[2]<<2)|(b[1]<<1)|(b[0]);
		M[id]++;
		printf("%d, %f, %d%d%d%d, %d (%d%d%d)\n", 
			i, X, c[3], c[2], c[1], c[0], id, b[2], b[1], b[0]);
	}
	for(i=0; i<N+1; i++)
		printf("M[%d] = %d\n", i+1, M[i]);
	return 0;
}