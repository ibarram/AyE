#include <stdio.h>
#include <string.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	Z Z1, Z2, Z3;
	float x;
	Z1 = capturarZ();
	Z2 = capturarZ();
	printf("Z1 = %f%+fi\n", Z1.a, Z1.b);
	printf("Z2 = %f%+fi\n", Z2.a, Z2.b);
	Z3 = sumaZ(Z1, Z2);
	printf("Z3 = %f%+fi\n", Z3.a, Z3.b);
	Z3 = multiplicaZ(Z1, Z2);
	printf("Z3 = %f%+fi\n", Z3.a, Z3.b);
	Z3 = conjZ(Z1);
	printf("Z3 = %f%+fi\n", Z3.a, Z3.b);
	Z3 = invZ(Z2);
	printf("Z3 = %f%+fi\n", Z3.a, Z3.b);
	Z3 = divZ(Z1, Z2);
	printf("Z3 = %f%+fi\n", Z3.a, Z3.b);
	x = magZ(Z1);
	printf("|Z1|=%f\n", x);
	x = angZ(Z2);
	printf("ang(Z2) = %f\n", x);
	return 0;
}
