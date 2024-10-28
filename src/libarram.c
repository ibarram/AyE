#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "libarram.h"

float dist_norm(float md, float de)
{
	float U1, U2, Z1;
	U1 = (float)rand()/RAND_MAX;
	U2 = (float)rand()/RAND_MAX;
	Z1 = sqrt(-2*log(U1))*sin(2*PI*U2);
	return (Z1*de+md);
}

int imprimir2(float x[], int n)
{
	printf("%f\n", x[0]);
	if(n-1)
		return imprimir2(x+1, n-1);
	else
		return 0;
}

float suma_x(float x[], int n)
{
	//return n-1?x[0]+suma_x(x+1,n-1):x[0];
	if(n-1)
		return x[0]+suma_x(x+1,n-1);
	else
		return x[0];
}

float media2(float x[], int n)
{
	return suma_x(x, n)/n;
}

float media1(float x[], int n)
{
	int i;
	float md;
	for(i=1, md=x[0]; i<n; i++)
		md+=x[i];
	return md/n;
}

float suma_x2(float x[], float md, int n)
{
	if(n-1)
		return (x[0]-md)*(x[0]-md)+suma_x2(x+1, md, n-1);
	else
		return (x[0]-md)*(x[0]-md);
}

float varianza2(float x[], int n)
{
	float md;
	md = media2(x, n);
	return suma_x2(x, md, n)/(n-1);
}

float varianza1(float x[], int n)
{
	int i;
	float md, vr;
	for(i=0, md = media1(x, n), vr=0; i<n; i++)
		vr+=((x[i]-md)*(x[i]-md));
	return vr/(n-1);
}

void generar(float x[], int n, float min, float max)
{
	int i;
	for(i=0; i<n; i++)
		x[i] = (max-min)*((float)rand())/RAND_MAX+min;
}

void imprimir(float x[], int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("x[%d] = %f\n", i+1, x[i]);
}

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
	fct1*=(x/(i+1));
	if(n-i++)
		return fct1+exp4(x,n);
	else
	{
		fct1=1;
		i=0;
		return 1;
	}
}

int isce(char c)
{
	static int i = 0;
	if(c==CE[i])
	{
		i=0;
		return 1;
	}
	else if(CE[i]!='\0')
	{
		i++;
		return isce(c);
	}
	else
	{
		i=0;
		return 0;
	}
}

int ispnt(char c)
{
	static int i=-1, j=-1;
	i++;
	if(c=='.'&&i)
	{
		if((j+1)==i)
			return 0;
		else
		{
			j = i;
			return 1;
		}
	}
	else
		return 0;
}

int validar(char email[])
{
	int nc, da, i, nce;
	char *bc;
	nc = strlen(email);
	if(nc>EMAIL_MX)
		return 0;
	bc = strchr(email, '@');
	if(bc==NULL)
		return 0;
	da = (int)(bc-email);
	if(da>EMAIL_PL)
		return 0;
	for(i=0; i<da; i++)
		if(!ispnt(email[i])&&!isalnum(email[i])&&!isce(email[i]))
			return 0;
	return 1;
}

int KSA(unsigned char *clave, unsigned char *S)
{
	unsigned int i, j, NC;
	for(i=0; i<NS; i++)
		S[i]=i;
	NC = strlen(clave);
	for(i=0, j=0; i<NS; i++)
	{
		j = (j+S[i]+clave[i%NC])%NS;
		if(i!=j)
			INTER(S[i], S[j]);
	}
	return 0;
}

int PRGA(unsigned char *S, unsigned char *msg, unsigned char *msg2)
{
	unsigned int i, j, k, NM;
	NM = strlen(msg);
	for(k=0, i=0, j=0; k<NM; k++)
	{
		i = (i+1)%NS;
		j = (j+S[i])%NS;
		if(i!=j)
			INTER(S[i], S[j]);
		msg2[k]=msg[k]^(S[(S[i]+S[j])%NS]);
	}
	msg2[k]='\0';
}

int RC4_cod(unsigned char *clave, unsigned char *msg, unsigned char *msg2)
{
	unsigned char S[NS];
	KSA(clave, S);
	PRGA(S, msg, msg2);
	return 0;
}

Z capturarZ(void)
{
	Z Z1;
	printf("Real: ");
	scanf("%f", &(Z1.a));
	printf("Imaginaria: ");
	scanf("%f", &(Z1.b));
	return Z1;
}

Z sumaZ(Z Z1, Z Z2)
{
	Z Z3;
	Z3.a = Z1.a+Z2.a;
	Z3.b = Z1.b+Z2.b;
	return Z3;
}

Z multiplicaZ(Z Z1, Z Z2)
{
	Z Z3;
	Z3.a = Z1.a*Z2.a-Z1.b*Z2.b;
	Z3.b = Z1.a*Z2.b+Z1.b*Z2.a;
	return Z3;
}

Z conjZ(Z Z1)
{
	Z Z3;
	Z3.a = Z1.a;
	Z3.b = -Z1.b;
	return Z3;
}

Z invZ(Z Z1)
{
	Z Z3;
	float r = Z1.a*Z1.a+Z1.b*Z1.b;
	if(r)
	{
		Z3.a = Z1.a/r;
		Z3.b = -Z1.b/r;
	}
	else
	{
		Z3.a = 0;
		Z3.b = 0;
	}
	return Z3;
}

Z divZ(Z Z1, Z Z2)
{
	return multiplicaZ(Z1, invZ(Z2));
}

float magZ(Z Z1)
{
	return sqrt(pow(Z1.a,2)+pow(Z1.b,2));
}

float angZ(Z Z1)
{
	return atanf(Z1.b/Z1.a);
}
float **crearMC(int NC, int NR)
{
	float **A, *pA;
	int i;
	pA = (float*)malloc(NC*NR*sizeof(float));
	if(pA==NULL)
		return NULL;
	A = (float**)malloc(NC*sizeof(float*));
	if(A==NULL)
	{
		free(pA);
		return NULL;
	}
	for(i=0; i<NC; i++)
		A[i] = pA+i*NR;
	return A;
}

float **crearMD(int NC, int NR)
{
	float **A;
	int i;
	A = (float**)malloc(NC*sizeof(float*));
	if(A==NULL)
		return NULL;
	for(i=0; i<NC; i++)
	{
		A[i] = (float*)malloc(NR*sizeof(float));
		if(A[i]==NULL)
		{
			for(i--;i<-1; i--)
				free(A[i]);
			free(A);
			return NULL;
		}
	}
	return A;
}

int freeMD(float** A, int NC)
{
	for(int i = 0; i < NC; i++)
		free(A[i]);
	free(A);
}

int freeMD2(float** A, int NC)
{
	NC--;
	free(A[NC]);
	if(NC)
		return freeMD2(A,NC);
	free(A);
	return 0;
}

int freeMC(float **A)
{
	free(A[0]);
	free(A);
}
int multiplicarM(float** A,float**B,float**C,int NC,int NR,int MC,int MR)
{
	int i, j, k;
	if(NC!=MR)
	{
		printf("no se puede realizar la multiplicacion");
		return 1;
	}
	for(i = 0; i < NR; i++)
		for(j = 0 ; j < MC; j++)
			for(k = 0, C[j][i] = 0; k<NC; k++)
				C[j][i] += A[k][i] * B[j][k];
	return 0;

}
void imprimirM(float **A,int NC,int MR)
{
	int i, j;
	for(i = 0; i<MR; i++)
	{
		for(j = 0; j<NC; j++)
			printf("%.4f\t",A[j][i]);
		printf("\n");
	}
}

void capturarM(float **A,int NC,int MR)
{
	int i, j;
	for(i = 0; i<MR; i++)
	{
		for(j = 0; j<NC; j++)
		{
			printf("A[%d][%d] = ", i,j);
			scanf_s("%f",(*(A+j) + i));
		}
	}
}