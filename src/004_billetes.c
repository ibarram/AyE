#include <stdio.h>

long int s2l(char *str)
{
	long int X=0;
	int i=0;
	while(str[i]>='0'&&str[i]<='9')
	{
		X*=10;
		X+=(str[i++]-'0');
	}
	return X;
}

int main(int argc, char *argv[])
{
	long int A, B, S, N, X;
	double Xf;
	if(argc!=5)
		return -1;
	A = s2l(argv[1]);
	B = s2l(argv[2]);
	S = s2l(argv[3]);
	N = s2l(argv[4]);
	X = (S-N*B)/(A-B);
	Xf = ((S-N*B)/((double)(A-B)));
	if(X!=Xf)
		printf("-1\n");
	else if(X<0||X>N)
		printf("-1\n");
	else
		printf("%ld\n", X);
	return 0;
}