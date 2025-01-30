#include <stdio.h>

int str2int(char *str)
{
	int i, valor;
	i = str[0]=='-';
	valor = 0;
	while(str[i]>='0'&&str[i]<='9')
		valor = 10*valor + str[i++]-'0';
	return str[0]=='-'?-valor:valor;
}

int n_billetes(int A, int B, int S, int N)
{
	float X;
	X = ((float)(S-N*B))/(A-B);
	return ((int)X)==X?(X<0?-1:(X>N?-1:X)):-1;
}

int main(int argc, char *argv[])
{
	int A, B, S, N, X;
	if(argc!=5)
		return -1;
	A = str2int(argv[1]);
	B = str2int(argv[2]);
	S = str2int(argv[3]);
	N = str2int(argv[4]);
	X = n_billetes(A, B, S, N);
	printf("%d\n", X);
	return 0;
}