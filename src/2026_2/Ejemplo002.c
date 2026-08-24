#include <stdio.h>

#define N 100

void evaluar(int n, int pesos[], int valores[], int i, int *peso_total, int *valor_total)
{
	int j;
	for(j=0, *peso_total=0, *valor_total=0; j<n; j++)
		if((i&(1<<j))!=0)
		{
			*peso_total+=pesos[j];
			*valor_total+=valores[j];
		}
}

int busqueda(int n, int pesos[], int valores[], int capacidad)
{
	int valor_max = 0, i, peso_total, valor_total;
	for(i=0; i<((1<<n)-1); i++)
	{
		evaluar(n, pesos, valores, i, &peso_total, &valor_total);
		if((peso_total<=capacidad)&&(valor_total>valor_max))
			valor_max = valor_total;
	}
	return valor_max;
}

int mochila(int n, int pesos[], int valores[], int capacidad)
{
	int valor_max = 0, i, peso_total, valor_total, j;
	for(i=0; i<((1<<n)-1); i++)
	{
		for(j=0, peso_total=0, valor_total=0; j<n; j++)
			if((i&(1<<j))!=0)
			{
				peso_total+=pesos[j];
				valor_total+=valores[j];
			}
		if((peso_total<=capacidad)&&(valor_total>valor_max))
			valor_max = valor_total;
	}
	return valor_max;
}

int main(int argc, char *argv[])
{
	int valores[N], pesos[N], capacidad, n, valor_max, maximo;
	int i;
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1||n>N);
	for(i=0; i<n; )
	{
		printf("P[%d] = ", i+1);
		scanf("%d", &pesos[i]);
		if(pesos[i]>0)
			i++;
	}
	for(i=0; i<n; )
	{
		printf("V[%d] = ", i+1);
		scanf("%d", &valores[i]);
		if(valores[i]>0)
			i++;
	}
	do{
		printf("Capacidad = ");
		scanf("%d", &capacidad);
	}while(capacidad<0);
	valor_max = mochila(n, pesos, valores, capacidad);
	printf("El valor maximo es %d\n", valor_max);
	maximo = busqueda(n, pesos, valores, capacidad);
	printf("El valor maximo es %d\n", maximo);
	return 0;
}