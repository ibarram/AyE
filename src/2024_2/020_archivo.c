#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int n, i;
	float *x;
	FILE *fp;
	printf("Ingrese el numero de elementos: ");
	scanf("%d", &n);
	x = (float*)malloc(n*sizeof(float));
	if(x==NULL)
		return 1;
	srand(time(NULL));
	for(i=0; i<n; i++)
		x[i] = (20.0*rand())/RAND_MAX-10;
	if(argc>1)
		fp = fopen(argv[1], "w+t");
	else
		fp = fopen("Prueba.txt", "w+t");
	if(fp==NULL)
	{
		free(x);
		return 2;
	}
	for(i=0; i<n; i++)
	{
		printf("x[%d] = %f\n", i+1, x[i]);
		fprintf(fp, "%f\n", x[i]);
	}
	fclose(fp);
	free(x);
	return 0;
}