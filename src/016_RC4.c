#include <stdio.h>
#include <string.h>
#include "libarram.h"

int main(int argc, char*argv[])
{
	unsigned char clave[30], msg[30];
	char *aux;
	unsigned char msg_cd[30], msg_dc[30];
	if(argc<3)
		return 1;
	aux=(char*)clave;
	strcpy(aux, argv[1]);
	aux=(char*)msg;
	strcpy(aux, argv[2]);
	RC4_cod(clave, msg, msg_cd);
	RC4_cod(clave, msg_cd, msg_dc);
	printf("MSG = %s\nMSG COD: %s\nMSG DEC: %s\n", msg, msg_cd, msg_dc);
	return 0;
}