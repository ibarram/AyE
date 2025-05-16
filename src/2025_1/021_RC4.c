#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b)\
			a^=b;;\
			b^=a;\
			a^=b;

char* KSA(unsigned int NS, char *clave)
{
	char *S;
	int i, j, NC;
	NC = strlen(clave);
	S = (char*)malloc(NS*sizeof(char));
	if(S==NULL)
		return S;
	for(i=0; i<NS; i++)
		S[i] = i;
	for(i=0; i<NS; i++)
		printf("%d ", S[i]);
	printf("\n");
	for(i=0, j=0; i<NS; i++)
	{
		j = (j+S[i]+clave[i%NC])%NS;
		if(i!=j)
			SWAP(S[i], S[j]);
	}
	for(i=0; i<NS; i++)
		printf("%d ", S[i]);
	printf("\n");
	return S;
}

char* PRGA(char *S, unsigned int NS, char *msg)
{
	char *S1;
	int NM, i, j, k;
	NM = strlen(msg);
	S1 = (char*)malloc(NM*sizeof(char));
	if(S1==NULL)
		return S1;
	for(k=0, i=0, j=0; k<NM; k++)
	{
		i = (i+1)%NS;
		j = (j+S[i])%NS;
		if(i!=j)
			SWAP(S[i], S[j]);
		S1[k] = S[(S[i]+S[j])%NS];
		printf("%d. %d->%d, %d->%d %d %d\n", k, i, j, S[i], S[j], S[i]+S[j], S1[k]);
	}
	for(i=0; i<NM; i++)
		printf("%d ", S1[i]);
	printf("\n");
	return S1;
}

int main(int argc, char *argv[])
{
	char *S, *S1, *clave;
	unsigned int NS = 10;
	if(argc<3)
	{
		printf("%s clave msg\n", argv[0]);
		return 1;
	}
	clave=argv[1];
	S = KSA(NS, clave);
	S1 = PRGA(S, NS, argv[2]);	
	return 0;
}
