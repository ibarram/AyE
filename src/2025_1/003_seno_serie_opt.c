#include <stdio.h>

int main()
{
	int n, i, signo;
	float x, sx, factor;
	printf("Ingrese el valor de x: ");
	scanf("%f", &x);
	do{
		printf("Ingrese el numero de iteraciones: ");
		scanf("%d", &n);
	}while(n<1);
	for(i=0, sx=0, signo=1, factor=x; i<n; i++)
	{
		sx += signo*factor;
		factor*=(x/(2*i+2))*(x/(2*i+3));
		signo*=-1;		
	}
	printf("sen(%f) = %f\n", x, sx);
	return 0;
}