#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libarram.h"

float suma(float a, float b)
{
	return a+b;
}

int cambio(int E, int A, int B)
{
	int Zi;
	Zi = (E/A)*B;
	return Zi?Zi+cambio(Zi+E-(Zi*A)/B,A,B):0;
}

int chocolate(int X, int Y, int A, int B)
{
	return X/Y+cambio(X/Y,A,B);
}

float potencia(float x, int n)
{
	return n?x*potencia(x,n-1):1;
}

long int factorial(long int n)
{
	return n?n*factorial(n-1):1;
}

float exp1(float x, int n)
{
	return n?potencia(x,n)/factorial(n)+exp1(x,n-1):1;
}

float fct(float x, int n)
{
	return n?(x/n)*fct(x,n-1):1;
}

float exp3(float x, int n)
{
	return n?fct(x,n)+exp3(x,n-1):1;
}

float exp4(float x, int n)
{
	static float fct1=1;
	static int i=0;
	float fct2;
	fct1*=(x/(i+1));
	fct2 = fct1;
	if(n-i++)
		return fct2+exp4(x,n);
	else
	{
		fct1=1;
		i=0;
		return 1;
	}
}

int swap(int *a, int *b)
{
	*a^=*b;
	*b^=*a;
	*a^=*b;
	return 0;
}

int du_sr(int x[], int n, int max, int min, unsigned int seed)
{
	int i, j;
	int m = max-min+1;
	int y[m];
	srand(seed);
	if(m<n)
		return 1;
	for(i=0; i<m; i++)
		y[i] = min+i;
	for(i=0; i<n; i++)
	{
		j = rand()%m;
		x[i] = y[j];
		m--;
		for( ; j<m; j++)
			y[j] = y[j+1];
	}
	return 0;
}

int imprimir(int x[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("x[%d] = %d\n", i+1, x[i]);
	return 0;
}

float media(int x[], int n)
{
	int i;
	float m;
	for(i=1, m=x[0]; i<n; i++)
		m += x[i];
	return m/n;
}

float varianza(int x[], int n)
{
	int i;
	float sx2, sx;
	for(i=1, sx2=(x[0]*x[0]), sx=x[0]; i<n; i++)
	{
		sx += x[i];
		sx2 += (x[i]*x[i]);
	}
	return sx2/n-(sx/n)*(sx/n);
}

int limite_inf(int x[], int n)
{
	return (int)(media(x, n)+0.5-sqrt(12*varianza(x, n)+1)/2);
}

int limite_sup(int x[], int n)
{
	return (int)(media(x, n)-0.5+sqrt(12*varianza(x, n)+1)/2);
}

int cardinalidad(int x[], int n)
{
	return limite_sup(x, n)-limite_inf(x, n)+1;
}

int normal(float x[], int n, float media, float de, unsigned int seed)
{
	int i;
	float U1, U2, Z0, Z1;
	srand(seed);
	for(i=0; i<n; i+=2)
	{
		U1 = (1.0*rand())/RAND_MAX;
		U2 = (1.0*rand())/RAND_MAX;
		Z0 = sqrt(-2*log(U1))*cos(2*PI*U2);
		Z1 = sqrt(-2*log(U1))*sin(2*PI*U2);
		x[i] = Z0;
		x[i+1] = Z1;
	}
	return 0;
}

float fnormal(float media, float de)
{
	float X, Z, U1, U2;
	U1 = (float)rand()/RAND_MAX;
	U2 = (float)rand()/RAND_MAX;
	Z = sqrt(-2*log(U1))*cos(2*PI*U2);
	X = media+de*Z;
	return X;
}