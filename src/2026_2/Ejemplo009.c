#include<stdio.h>
#include<stdlib.h>
#include"libarram.h"

#define N 4

int main(int argc, char *argv[])
{
	float altura[N] = {155, 165, 175, 185};
	int m, i, M[N+1], id;
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
		id = ((X>=altura[3])<<2)|
			(((X>=altura[1])&(X<altura[3]))<<1)|
			(((X>=altura[0])&(X<altura[1]))|
				((X>=altura[2])&(X<altura[3])));
		M[id]++;
	}
	for(i=0; i<N+1; i++)
		printf("M[%d] = %d\n", i+1, M[i]);
	return 0;
}