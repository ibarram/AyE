#include <stdio.h>

int main(int argc, char *argv[])
{
	int A, B, S, N, X, Y;
	float Xf;
	scanf("%d %d %d %d", &A, &B, &S, &N);
	X = (S-N*B)/(A-B);
	Xf = (1.0*S-N*B)/(A-B);
	if(X!=Xf)
		printf("%d\n", -1);
	else if(0>X||X>N)
		printf("%d\n", -1);
	else
		printf("%d\n", X);
	return 0;
}