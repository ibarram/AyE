#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

long int suma(long int x[], int n)
{
	return n?x[0]+suma(x+1,n-1):0;
}

long int suma2(long int x[], int n)
{
	return n?x[0]*x[0]+suma2(x+1,n-1):0;
}

float media(long int x[], long int n)
{
	return ((float)suma(x, n))/n;
}

float varianza(long int x[], long int n)
{
	return ((float)suma2(x, n))/n-media(x, n)*media(x, n);
}

int main(int argc, char *argv[])
{
	long int a, b, n, i, j, m, *x, *y, *dx, rnd, ea, eb;
	int fm, flag;
	float mx, s2x;
	printf("Ingrese el valor minimo: ");
	scanf("%ld", &a);
	printf("Ingrese el valor maximo: ");
	scanf("%ld", &b);
	if(a>b)
	{
		a^=b;
		b^=a;
		a^=b;
	}
	n = b-a+1;
	x = malloc(n*sizeof(long int));
	if(x==NULL)
		return 1;
	for(i=a; i<=b; i++)
		x[i-a] = i;
	do{
		printf("Ingrese el factor de muestreo: ");
		scanf("%d", &fm);
	}while(fm<2);
	m = ceil((double)n/fm);
	y = malloc(m*sizeof(long int));
	if(y==NULL)
	{
		free(x);
		return 2;
	}
	dx = malloc(m*sizeof(long int));
	if(dx==NULL)
	{
		free(x);
		free(y);
		return 3;
	}
	srand(time(NULL));
	for(i=0; i<m; i++)
	{
		do{
			flag = 0;
			rnd = rand()%n;
			for(j=i-1; j>-1; j--)
				if(y[j]==rnd)
				{
					flag = 1;
					break;
				}

		}while(flag);
		y[i] = rnd;
		dx[i] = x[y[i]];
	}
	printf("a = %ld\tb = %ld\tn = %ld\n", a, b, n);
	for(i=0; i<m; i++)
		printf("x[%ld] = %ld\n", y[i], dx[i]);
	mx = media(dx, m);
	printf("Media = %f\n", mx);
	s2x = varianza(dx, m);
	printf("Varianza = %f\n", s2x);
	ea = floor(mx+.5-sqrt(12*s2x+1)/2);
	eb = ceil(mx-.5+sqrt(12*s2x+1)/2);
	printf("a = %ld\tb = %ld\tm=%ld\n", ea, eb, m);
	free(y);
	free(x);
	free(dx);
	return 0;
}