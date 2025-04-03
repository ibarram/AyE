#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MD 170.0
#define DE 10.0
#define PI 3.141592653589793

int pos(float x, float *m)
{
	int id, C[4], B[3], i;
	for(i=0; i<4; i++)
		C[3-i] = x<m[i];
	B[0] = ((!C[3])&&C[2])||((!C[1])&&C[0]);
	B[1] = (!C[2])&&C[0];
	B[2] = !C[0];
	id = (B[2]<<2)|(B[1]<<1)|B[0];
	//printf("%d %d %d %d\n", C[3], C[2], C[1], C[0]);
	//printf("%d %d %d\n", B[2], B[1], B[0]);
	return id;
}

void gen_normal(float *x, int n, float md, float de)
{
	int i;
	float U1, U2, Z;
	srand(time(NULL));
	for(i=0; i<n; i++)
	{
		U1 = ((float)rand())/RAND_MAX;
		U2 = ((float)rand())/RAND_MAX;
		Z = sqrt(-2*log(U1))*cos(2*PI*U2);
		x[i] = Z*de+md;
	}
}

void tallas(float *x, int n, int *NE, float *M)
{
	int i;
	for(i=0; i<5; i++)
		NE[i] = 0;
	for(i=0; i<n; i++)
		NE[pos(x[i], M)]++;
}

int main(int argc, char *argv[])
{
	float M[4] = {155, 165, 175, 185}, *x;
	int NE[5];
	int n, i;
	do{
		printf("Ingrese el numero de muestras: ");
		scanf("%d", &n);
	}while(n<1);
	x = (float*)malloc(n*sizeof(float));
	if(x==NULL)
		return 1;
	gen_normal(x, n, MD, DE);
	tallas(x, n, NE, M);
	for(i=0; i<n; i++)
		printf("x[%d] = %f\n", i+1, x[i]);
	for(i=0; i<5; i++)
		printf("M[%d] = %d\n", i+1, NE[i]);
	free(x);
	return 0;
}