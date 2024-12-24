#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n, *pesos, *valores, capacidad, i, j, nb, comb_p, comb_v, mj_p, mj_v, mj_m;
	unsigned int mochila;
	nb = 8*sizeof(mochila);
	do{
		printf("Ingrese el numero de elementos: ");
		scanf("%d", &n);
	}while(n<1||n>nb);
	pesos = (int*)malloc(n*sizeof(int));
	if(pesos==NULL)
		return 1;
	valores = (int*)malloc(n*sizeof(int));
	if(valores==NULL)
	{
		free(pesos);
		return 2;
	}
	for(i=0; i<n; i++)
	{
		do{
			printf("Peso[%d] = ", i+1);
			scanf("%d", pesos+i);
		}while(pesos[i]<1);
		do{
			printf("Valor[%d] = ", i+1);
			scanf("%d", valores+i);
		}while(valores[i]<1);
	}
	do{
		printf("Ingrese la capacidad: ");
		scanf("%d", &capacidad);
	}while(capacidad<1);
	printf("Num\tPeso\tValor\n");
	for(i=0; i<n; i++)
		printf("%d\t%d\t%d\n", i+1, pesos[i], valores[i]);
	printf("Capacidad de %d Kg.\n", capacidad);
	for(i=0, mj_p=0, mj_v=0, mj_m=0; i<(1<<n); i++)
	{
		printf("%d\t", i);
		for(j=n-1; j>-1; j--)
			printf(i&(1<<j)?"1":"0");
		for(j=0, comb_p=0, comb_v=0; j<n; j++)
			if(i&(1<<j))
			{
				comb_p += pesos[j];
				comb_v += valores[j];
			}
		if((comb_v>mj_v)&&(comb_p<=capacidad))
		{
			mj_v = comb_v;
			mj_p = comb_p;
			mj_m = i;
		}
		printf("\t%d\t%d\n", comb_p, comb_v);
	}
	printf("Solucion: %d. %d Kg, $%d\n", mj_m, mj_p, mj_v);
	free(pesos);
	free(valores);
	return 0;
}