#include <stdio.h>
#include <time.h>

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

int main(int argc, char *argv[])
{
	int n;
	float x, ex1, ex2, ex3;
	double dt1, dt2, dt3;
	clock_t t1, t2;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	do{
		printf("Ingrese el numero de terminos: ");
		scanf("%d", &n);
	}while(n<1);
	t1 = clock();
	ex1 = exp1(x, n);
	t2 = clock();
	dt1 = ((double)(t2-t1))/CLOCKS_PER_SEC;
	t1 = clock();
	ex2 = exp3(x, n);
	t2 = clock();
	dt2 = ((double)(t2-t1))/CLOCKS_PER_SEC;
	t1 = clock();
	ex3 = exp4(x, n);
	t2 = clock();
	dt3 = ((double)(t2-t1))/CLOCKS_PER_SEC;
	printf("exp(%.4f) = %.4f\t%lf\n", x, ex1, dt1);
	printf("exp(%.4f) = %.4f\t%lf\n", x, ex2, dt2);
	printf("exp(%.4f) = %.4f\t%lf\n", x, ex3, dt3);
}