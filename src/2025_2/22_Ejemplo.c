#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	lt_IHME *lt1;
	if(argc!=2)
		return 1;
	fp = fopen(argv[1], "rt");
	if(fp==NULL)
		return 2;
	lt1 = read_csv2(fp);
	if(lt1==NULL)
		retunr 3;
	printf("Num. registros: %d\n", num_registros(lt1));
	fclose(fp);
	return 0;
}