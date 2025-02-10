#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n, *Pesos, *Valores, Capacidad, Valor_max, i, m, j, Peso_max, Valor_opt;
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1);
	Pesos = (int*)malloc(n*sizeof(int));
	if(Pesos == NULL)
		return 1;
	Valores = (int*)malloc(n*sizeof(int));
	if(Valores == NULL)
	{
		free(Pesos);
		return 2;
	}
	for(i=0; i<n; i++)
	{
		printf("Pesos[%d] = ", i+1);
		scanf("%d", Pesos+i);
		if(Pesos[i]<1)
			i--;
	}
	for(i=0; i<n; i++)
	{
		printf("Valores[%d] = ", i+1);
		scanf("%d", Valores+i);
		if(Valores[i]<1)
			i--;
	}
	do{
		printf("Ingrese la capacidad de la mochila: ");
		scanf("%d", &Capacidad);
	}while(Capacidad<1);
	m = 1<<n;
	for(i=0, Valor_opt = 0; i<m; i++)
	{
		for(j=0, Peso_max = 0, Valor_max = 0; j<n; j++)
			if(i&1<<j)
			{
				Peso_max += Pesos[j];
				Valor_max += Valores[j];
			}
		if(Peso_max<=Capacidad&&Valor_max>Valor_opt)
			Valor_opt = Valor_max;
		printf("%d. %d\t%d\t%d\n", i+1, Peso_max, Valor_max, Valor_opt);
	}
	printf("Valor Optimo: %d\n", Valor_opt);
	free(Pesos);
	free(Valores);
	return 0;
}