#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	int indice, val[8] = {2,4647,3,7,571,169,3,2020};
	double valor;
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
	indice = 0;
	while(indice>-1&&indice<N_C_MAX)
	{
		lt_measure = unique_IHME(lt1, indice);
		if(lt_measure==NULL)
		{
			fclose(fp);
			return 4;
		}
		imprimir_u_IHME(lt_measure);
		printf("Ingrese el indice: ");
		scanf("%d", &indice);
	}
	valor = consulta_IHME(lt1, val);
	printf("%lf\n", valor);
//	2,4645,1,18,571,169,3,2020,
//  2,4647,3,7,571,169,3,2020,70.33780119676
	fclose(fp);
	return 0;
}