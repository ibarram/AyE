#include <stdio.h>
#include <string.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	dato d;
	d.i = -40300;
	printf("%u\t%u\t%u\t%u\n", 
		(unsigned char)d.c[3], (unsigned char)d.c[2],
		(unsigned char)d.c[1], (unsigned char)d.c[0]);
	return 0;
}
