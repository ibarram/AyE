#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int n, X, Y, A, B, i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d %d %d %d", &X, &Y, &A, &B);
		printf("%d\n", chocolate(X, Y, A, B));
	}
	return 0;
}
