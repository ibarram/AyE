#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "libarram.h"

#define NC	100

int main(int argc, char *argv[])
{
	int16_t *x, *x1;
	long int i, n, ns;
	int flag_update=0;
	FILE *fp;
	double tmp;
	char fn_d[NC] = "a01.dat", *filename;
	clock_t t1, t2;
	if(argc>1)
		filename = argv[1];
	else
		filename = fn_d;
	fp = fopen(filename, "rb");
	if(fp==NULL)
		return 1;
	n = file_size_bytes(fp)/sizeof(int16_t);
	if(argc>2)
	{
		ns = atol(argv[2]);
		if(ns>n)
			ns = n;
	}
	else
		ns = n;
	printf("Num. muestras: %ld (%ld)\n", n, ns);
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
	if(argc>3)
		flag_update = atoi(argv[3]);
	t1 = clock();
	ordenamiento_dir(x1, ns, flag_update);
	t2 = clock();
	tmp = (double)(t2-t1)/CLOCKS_PER_SEC;
	printf("Tiempo: %lf\n", tmp);
/*
	for(i=0; i<20; i++)
		printf("[%ld]\t%d\t%d\n", i+1, x[i], x1[i]);
*/
	return 0;
}
