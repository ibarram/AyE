#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	CURP User;
	User = capturarCURP();
	imprimirCURP(User);
	User = generarCURP(User);
	printf("CURP: %s\n", User.curp);
	return 0;
}