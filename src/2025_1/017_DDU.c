#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main(int argc, char *argv[])
{
	long int a, b, n, i, j, m, *x, *y, rnd;
	int fm, flag;
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
	}
	printf("a = %ld\tb = %ld\tn = %ld\n", a, b, n);
	for(i=0; i<m; i++)
		printf("x[%ld] = %ld\n", y[i], x[y[i]]);
	free(y);
	free(x);
	return 0;
}