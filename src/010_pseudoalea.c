#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000

int main(int argc, char*argv[])
{
	int n, i, x[N], max, min;
	unsigned long int t;
	t = time(NULL);
	srand(t);
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	printf("Ingrese el valor maximo: ");
	scanf("%d", &max);
	printf("Ingrese el valor minimo: ");
	scanf("%d", &min);
	if(max<min)
	{
		max^=min;
		min^=max;
		max^=min;
	}
	printf("DDU [%d, %d], S=%lu\n", min, max, t);
	for(i=0; i<n; i++)
	{
		x[i] = rand()%(max-min+1)+min;
		printf("%d. %d\n", i+1, x[i]);
	}
	return 0;
}