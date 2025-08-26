#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/*
float suma(float a, float b)
{
	return a+b;
}
*/

/*
long int factorial(long int n)
{
	if(n<=1)
		return 1;
	return n*factorial(n-1);
}
*/

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

float factor(float x, int n)
{
	return n?(x/n)*factor(x,n-1):1;
}

float exp3(float x, int n)
{
	return n?factor(x, n)+exp3(x,n-1):1;
}

float exp4(float x, int n)
{
	static int i = 0;
	static float fct = 1;
	i++;
	fct*=(x/i);
	if(n)
	{
		return fct+exp4(x,n-1);
	}
	else
	{
		i = 0;
		fct = 1;
		return 1;
	}
}

int* DU(int n, int min, int max)
{
	int *p, i, j, flag;
	srand(time(NULL));
	if(n)
	{
		p = (int*)malloc(n*sizeof(int));
		if(p==NULL)
			return p;
		p[0] = rand()%(max-min+1)+min;
		for(i=1; i<n; i++)
		{
			flag = 1;
			while(flag)
			{
				p[i] = rand()%(max-min+1)+min;
				for(j=0; j<i; j++)
					if(p[i]==p[j])
						break;
				if(j==i)
					flag = 0;
			}
		}
	}
	else
		p = NULL;
	return p;
}

void imprimir_DU(int *d, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("%d. %d\n", i+1, d[i]);
}

int suma(int *x, int n)
{
	if(n)
		return x[0]+suma(x+1,n-1);
	else
		return 0;	
}

int suma2(int *x, int n)
{
	if(n)
		return (x[0]*x[0])+suma2(x+1,n-1);
	else
		return 0;	
}

float media2(int *x, int n)
{
	int i;
	float md;
	for(i=1, md=x[0]; i<n; i++)
		md+=x[i];
	return md/n;
}

float media(int *x, int n)
{
	return ((float)suma(x, n))/n;
}

float varianza(int *x, int n)
{
	float md = media(x, n);
	return ((float)suma2(x, n))/n-md*md;
}

float varianza2(int *x, int n)
{
	float md, vr;
	int i;
	md =  media2(x, n);
	for(i=1, vr=x[0]*x[0]; i<n; i++)
		vr+=(x[i]*x[i]);
	return vr/n-md*md;
}

int estInf(float md, float vr)
{
	return floor(md+.5-sqrt(12*vr+1)/2);
}

int estSup(float md, float vr)
{
	return ceil(md-.5+sqrt(12*vr+1)/2);
}

int estN(int *x, int n)
{
	int N, b, a;
	float md, vr;
	md = media2(x, n);
	vr = varianza2(x, n);
	b = estSup(md, vr);
	a = estInf(md, vr);
	N = b - a + 1;
	return N;
}
