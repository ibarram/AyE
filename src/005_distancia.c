#include <stdio.h>

#define SWAP1(a, b)\
{\
	a+=b;\
	b=a-b;\
	a-=b;\
}

#define SWAP2(a, b)\
{\
	a^=b;\
	b^=a;\
	a^=b;\
}

long int s2l(char *str)
{
	long int X=0, S=1;
	int i=0;
	if(str[i]=='-')
	{
		S=-1;
		i++;
	}
	while(str[i]>='0'&&str[i]<='9')
	{
		X*=10;
		X+=(str[i++]-'0');
	}
	return S*X;
}

int main(int argc, char *argv[])
{
	long int A, B, C, D, X;
	if(argc!=5)
		return 1;
	A = s2l(argv[1]);
	B = s2l(argv[2]);
	C = s2l(argv[3]);
	D = s2l(argv[4]);
	printf("%ld\t%ld\t%ld\t%ld\n", A, B, C, D);
	if(A>B)
		SWAP1(A,B);
	if(C>D)
		SWAP1(C,D);
	if(A>C)
		SWAP2(A,C);
	if(B>D)
		SWAP2(B,D);
	X = D-A;
	printf("%ld\t%ld\t%ld\t%ld\n", A, B, C, D);
	printf("%ld\n", X);
	return 0;
}