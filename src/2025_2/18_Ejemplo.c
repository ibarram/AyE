#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	INEGI info;
	long int nr;
	char c;
	info.fp = fopen("cpv_valor_00.csv", "rt");
	if(info.fp==NULL)
		return 1;
	info.nr = 0;
	info.data = NULL;
	nr=read_csv(&info);
	printf("Numero de registros: %ld\n", nr);
	free(info.data);
	fclose(info.fp);
	return 0;
}