#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int n;
	float x;
	scanf("%d %f", &n, &x);
	printf("%f\n", exp1(x, n));
	printf("%f\n", exp3(x, n));
	printf("%f\n", exp4(x, n));
	printf("%f\n", exp4(x, n));
	return 0;
}