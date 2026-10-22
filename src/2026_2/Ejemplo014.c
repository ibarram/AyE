#include <stdio.h>
#include <stdlib.h>

float* capturar(int n)
{
	float *A;
	int i;
	A = (float*)malloc(n*sizeof(float));
	if(A==NULL)
		return NULL;
	for(i=0; i<n; i++)
	{
		printf("A[%d] = ", i+1);
		scanf("%f", A+i); // &A[i] == &*(A+i) == A+i
	}
	return A;
}

float suma(float *C, int n)
{
	return n?suma(C+1, n-1)+C[0]:0;
}

float fmedia(float *B, int n)
{
	return suma(B, n)/n;
}

int main(int argc, char *argv[])
{
	int n;
	float *X, media;
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1);
	X = capturar(n);
	if(X==NULL)
		return 1;
	media = fmedia(X, n);
	free(X);
	printf("Media = %f\n", media);
	return 0;
}