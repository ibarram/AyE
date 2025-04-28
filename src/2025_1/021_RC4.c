#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b)\
			aux = a;\
			a = b;\
			b = aux;

char* KSA(unsigned int NS, char *clave)
{
	char *S;
	int i;
	S = (char*)malloc(NS*sizeof(char));
	if(S==NULL)
		return S;
	for(i=0; i<NS; i++)
		S[i] = i;

	return S;
}

int main(int argc, char *argv[])
{
	char *S, *clave;
	unsigned int NS = 10;
	if(argc<3)
	{
		printf("%s clave msg\n", argv[0]);
		return 1;
	}
	clave=argv[1];
	S = KSA(NS, clave);
	return 0;
}
