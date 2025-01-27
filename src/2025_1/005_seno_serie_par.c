#include <stdio.h>
#include <stdlib.h>

float seno(float x, int n)
{
	int i, signo;
	float sx, factor;
	if(n<1)
		return 0;
	for(i=0, sx=0, signo=1, factor=x; i<n; i++)
	{
		sx += signo*factor;
		factor*=(x/(2*i+2))*(x/(2*i+3));
		signo*=-1;		
	}
	return sx;
}

int main(int argc, char *argv[])
{
	float x, sx;
	int n;
	switch(argc)
	{
	case 1:
		printf("Ingrese el valor de x: ");
		scanf("%f", &x);
		do{
			printf("Ingrese el numero de iteraciones: ");
			scanf("%d", &n);
		}while(n<1);
		break;
	case 2:
		printf("Ingrese el valor de x: ");
		scanf("%f", &x);
		n = atoi(argv[1]);
		break;
	case 3:
		n = atoi(argv[1]);
		x = atof(argv[2]);
		break;
	default:
		printf("Error en el numero de argumentos.\n");
		return 1;
	}
	sx = seno(x, n<1?10:n);
	printf("sen(%f) = %f\n", x, sx);
	return 0;
}