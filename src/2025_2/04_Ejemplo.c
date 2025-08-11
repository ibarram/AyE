#include <stdio.h>
#include <stdlib.h>

#define GET_BIT(x, n) x&(1<<n)

int main(int argc, char *argv[])
{
	int *Pesos, *Valores, Capacidad, n, i, j, m, V_actual, P_actual, V_max, P_max, i_max;
	scanf("%d", &n);
	Pesos = (int*)malloc(n*sizeof(int));
	if(Pesos==NULL)
		return 1;
	Valores = (int*)malloc(n*sizeof(int));
	if(Valores==NULL)
	{
		free(Pesos);
		return 2;
	}
	for(i=0; i<n; i++)
		scanf("%d", Pesos+i);
	for(i=0; i<n; i++)
		scanf("%d", Valores+i);
	scanf("%d", &Capacidad);
	m = 1<<n;
	V_max = 0;
	P_max = 0;
	i_max = 0;
	for(i=0; i<m-1; i++)
	{
		V_actual = 0;
		P_actual = 0;
		for(j=0; j<n; j++)
			if(GET_BIT(i, j))
			{
				V_actual += Valores[j];
				P_actual += Pesos[j];
			}
		if((P_actual<=Capacidad)&&(V_actual>V_max))
		{
			P_max = P_actual;
			V_max = V_actual;
			i_max = i;
		}
		printf("%d. P: %d V: %d - %d - Pm: %d Vm %d %d\n", 
			i, P_actual, V_actual, P_actual<=Capacidad, P_max, V_max, i_max);
	}
	printf("Valor maximo %d (", V_max);
	for(i=n-1; i>-1; i--)
		printf("%d", GET_BIT(i_max, i)?1:0);
	printf(")\n");
	free(Pesos);
	free(Valores);
	return 0;
}