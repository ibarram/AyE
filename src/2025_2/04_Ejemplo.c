#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int *Pesos, *Valores, Capacidad, n, i, j, m;
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
	for(i=0; i<m-1; i++)
	{
		
	}
	free(Pesos);
	free(Valores);
	return 0;
}