#include <stdio.h>
#include "libarram.h"

#define NC 100

int main(int argc, char *argv[])
{
	long int nr;
	bd_INEGI Datos;
	char fn[] = "edr_valor_00.csv", *filename;
	filename = (argc==2?argv[1]:fn);
	lectura_bd(filename, &Datos);
	return 0;
}