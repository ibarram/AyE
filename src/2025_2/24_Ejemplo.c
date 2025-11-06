#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int16_t *x, *x1;
	long long int n;
	FILE *fp;
	int i;
	fp = fopen("a01.dat", "rb");
	if(fp==NULL)
		return 1;
	n = file_size_bytes(fp)/sizeof(int16_t);
	printf("Num. muestras: %lld\n", n);
	x = (int16_t*)malloc(n*sizeof(int16_t));
	if(x==NULL)
	{
		fclose(fp);
		return 2;
	}
	fread(x, sizeof(int16_t), n, fp);
	fclose(fp);
	x1 = (int16_t*)malloc(n*sizeof(int16_t));
	if(x1==NULL)
	{
		free(x);
		return 3;
	}
	for(i=0; i<n; i++)
		x1[i] = x[i];
	ordenamiento_dir(x1, n);
	for(i=0; i<10; i++)
		printf("[%d]\t%d\t%d\n", i+1, x[i], x1[i]);
	return 0;
}