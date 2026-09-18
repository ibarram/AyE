#include<stdio.h>
#include"libarram.h"

#define N 4

int main(int argc, char *argv[])
{
	float altura[N] = {155, 165, 175, 185};
	int NP[N+1];
	float media, de;
	do{
		printf("Ingrese la estatura promedio: ");
		scanf("%f", &media);
	}while(media<1);
	do{
		printf("Ingrese la desviacion estandar: ");
		scanf("%f", &de);
	}while(de<0);

	return 0;
}