#include <stdio.h>
#include "libarram.h"

int main(int argc, char*argv[])
{
	char *email;
	if(argc<2)
		return 1;
	email=argv[1];
	if(validar(email))
		printf("El e-mail es correcto.\n");
	else
		printf("El email es incorrecto.\n");
	return 0;
}