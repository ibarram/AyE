#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "libarram.h"

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

int esValido(char str[])
{
	int n, nl, i, j, v, nse;
	char *pstr1, *pstr2, *pstr3;
	const char str_esp[] = "!#$%&'*+/=?^_{|}~.";
	nse = strlen(str_esp);
	n = strlen(str);
	if(n>N_MAX)
		return 0;
	pstr1 = strchr(str, '@');
	if(pstr1==NULL)
		return 0;
	pstr2 = strchr(pstr1+1, '@');
	if(pstr2!=NULL)
		return 0;
	nl = (int)(pstr1-str);
	if(nl>N_local)
		return 0;
	if((n-nl)>N_dominio)
		return 0;
	pstr2 = strchr(pstr1, '.');
	if(pstr2==NULL)
		return 0;
	pstr2 = strchr(str, '.');
	while(pstr2!=NULL)
	{
		pstr3 = strchr(pstr2+1, '.');
		if(pstr3!=NULL)
		{
			if((pstr3-pstr2)==1)
				return 0;
			else if((pstr3-pstr2)>N_punto)
				return 0;
		}
		pstr2 = pstr3;
	}
	i=1;
	while(pstr1[i]!='\0')
	{
		if(isalnum(pstr1[i])||pstr1[i]=='.')
			i++;
		else
			return 0;
	}
	i=0;
	while(str[i]!='@')
	{
		for(j=0, v=0; j<nse; j++)
			v += str[i]==str_esp[j]?1:0;
		if(isalnum(str[i])||v)
			i++;
		else
			return 0;
	}
	return 1;
}

int RC4(char msg_1[], char clave[], char msg_2[])
{
	int nc, i, j, k, nM, NS, NC;
	char *S;
	nc = strlen(msg_1);
	NC = strlen(clave);
	nM = 'Z'-'A'+1;
	for(i=0; i<nc; i++)
	{
		if(msg_1[i]<'a')
			msg_1[i]-='A';
		else
			msg_1[i]-=('a'-nM);
	}
	NS = 2*nM;
	S=(char*)malloc(NS*sizeof(char));
	if(S==NULL)
		return 1;
	for(i=0; i<NS; i++)
		S[i] = i;
	for(i=0, j=0; i<NS; i++)
	{
		j = (j+S[i]+clave[i%NC])%NS;
		SWAP(S[i], S[j]);
	}
	for(k=0, i=0, j=0; k<nc; k++)
	{
		i = ( i + 1 ) % NS;
		j = ( j + S[i] ) % NS;
		SWAP( S[i], S[j] );
		msg_2[k] = msg_1[k] ^ S[ ( S[i] + S[j] ) % NS ];
		printf("%d ", msg_2[k]);
		if(msg_2[k]<nM)
			msg_2[k]+='A';
		else
			msg_2[k]+=('a'-nM);
	}
	msg_2[k]='\0';
	printf("\n");
	free(S);
	return 0;
}

Complejo sumaC(Complejo Z1, Complejo Z2)
{
	Complejo Z3;
	Z3.a = Z1.a+Z2.a;
	Z3.b = Z1.b+Z2.b;
	return Z3;
}









