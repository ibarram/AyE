#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	if(argc!=2)
		return 1;
	if(esValido(argv[1]))
		printf("El correo %s es correcto.\n", argv[1]);
	else
		printf("Correo incorrecto.\n");
	return 0;
}