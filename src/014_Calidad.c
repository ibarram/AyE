#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
#define NE 10
#define NC 95

int main(int argc, char*argv[])
{
	float P[N];
	int C[N], E[NE], i;
	srand(time(NULL));
	for(i=0; i<N; i++)
		P[i] = (100.0*rand())/RAND_MAX;
	for(i=0; i<N; i++)
		C[i] = (P[i]<(100-NC)?0:1);
	for(i=0; i<NE; i++)
		E[i] = i*(N/NE)+rand()%(N/NE);
	for(i=0; i<NE; i++)
		printf("%d. %d - %d\n", i+1, C[E[i]], E[i]);
	return 0;
}
