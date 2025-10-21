#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	lt_IHME *lt1;
	u_IHME *lt_measure;
	if(argc!=2)
		return 1;
	fp = fopen(argv[1], "rt");
	if(fp==NULL)
		return 2;
	lt1 = read_csv2(fp);
	if(lt1==NULL)
		return 3;
	printf("Num. registros: %d\n", num_registros(lt1));
	lt_measure = unique_IHME(lt1, 1);
	if(lt_measure==NULL)
	{
		lt_IHME(lt1);
		return 4;
	}
	imprimir_u_IHME(lt_measure);
	fclose(fp);
	return 0;
}