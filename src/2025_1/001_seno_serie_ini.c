#include <stdio.h>

int main()
{
	int n, i, j, signo;
	long int den;
	float x, sx, factor, num;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	do{
		printf("Ingrese el numero de iteraciones: ");
		scanf("%d", &n);
	}while(n<1);
	for(i=0, sx=0, signo=1; i<n; i++)
	{
		for(j=0, num=1, den=1; j<2*i+1; j++)
		{
			num*=x; // num = num * x;
			den*=(j+1); // den = den * (j+1);
		}
		factor = signo*(num/den);
		signo*=-1;
		sx += factor; // sx = sx + factor;
	}
	printf("sen(%f) = %f\n", x, sx);
	return 0;
}