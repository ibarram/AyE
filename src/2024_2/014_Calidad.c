#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define NE 10
#define NC 95

int main(int argc, char*argv[])
{
	float P[N];
	int C[N], E[NE][NE], i, j, k, aux, flag, L[NE];
	srand(time(NULL));
	for(i=0; i<N; i++)
		P[i] = (100.0*rand())/RAND_MAX;
	for(i=0; i<N; i++)
		C[i] = (P[i]<(100-NC)?0:1);
	for(i=0; i<NE; i++)
	{
		E[i][0] = i*(N/NE)+rand()%(N/NE);
		for(j=1; j<NE; j++)
		{
			do{
				flag = 0;
				aux = i*(N/NE)+rand()%(N/NE);
				for(k=0; k<j-1; k++)
					if(aux==E[i][k])
					{
						flag = 1;
						break;
					}
			}while(flag);
			E[i][j] = aux;
		}
	}
	for(i=0; i<NE; i++)
		for(j=0, L[i]=0; j<NE; j++)
			if(!C[E[i][j]])
				L[i]++;
	for(i=0; i<NE; i++)
	{
		printf("%d. ", i+1);
		for(j=0; j<NE; j++)
			printf("%d, %.0f, %d\t", E[i][j], P[E[i][j]], C[E[i][j]]);
		printf("\n");
	}
	for(i=0; i<NE; i++)
		printf("L[%d] = %d\t", i+1, L[i]);
	printf("\n");
	return 0;
}
