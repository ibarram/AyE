#include <stdio.h>
#include <stdint.h>
#include "libarram.h"

#define N 1000

int main(int argc, char *argv[])
{
	int16_t x[N], x1[N];
	FILE *fp;
	int i;
	fp = fopen("a01.dat", "rb");
	if(fp==NULL)
		return 1;
	fread(x, sizeof(int16_t), N, fp);
	for(i=0; i<N; i++)
	{
		x1[i] = x[i];
		printf("x[%d] = %d\n", i+1, x[i]);
	}
	ordenamiento_dir(x1, N);
	for(i=0; i<N; i++)
		printf("x[%d] = %d\n", i+1, x[i]);
	fclose(fp);
	return 0;
}