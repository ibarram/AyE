#include<stdio.h>
#include"libarram.h"

int main(int argc, char*argv[])
{
	float a = 2.3, b = -4.5;
	printf("%f%+f=%f\n", a, b, suma(a,b));
	return 0;
}