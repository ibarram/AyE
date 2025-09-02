#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "libarram.h"

#define NC_msg 20

int main(int argc, char *argv[])
{
	char clave[NC_msg], msg_1[NC_msg], msg_2[NC_msg];
	printf("Ingrese la clave: ");
	scanf("%s", clave);
	printf("Ingrese el mensaje: ");
	scanf("%s", msg_1);
	RC4(msg_1, clave, msg_2);
	printf("MSG: %s\n", msg_2);
	return 0;
}