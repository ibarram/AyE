#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define NE 10
#define NC 95

int main(int argc, char*argv[])
{
	float P[N];
	int C[N], E[NE][NE], i, j, k, aux, flag;
	srand(time(NULL));
	for(i=0; i<N; i++)
		P[i] = (100.0*rand())/RAND_MAX;
	for(i=0; i<N; i++)
		C[i] = (P[i]<(100-NC)?0:1);
	for(i=0; i<NE; i++)
	{
		E[i][0] = i*(N/NE)+rand()%(N/NE);
		j = 1;
		flag = 0;
		do{
			aux = i*(N/NE)+rand()%(N/NE);
			for(k=0; k<j-1; k++)
		}while(flag);
		E[i][j] = aux;
	}
	for(i=0; i<NE; i++)
		printf("%d. %d - %d\n", i+1, C[E[i]], E[i]);
	return 0;
}
