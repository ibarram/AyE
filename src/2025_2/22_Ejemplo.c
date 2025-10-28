#include <stdio.h>
#include "libarram.h"

#define N 20

int main(int argc, char *argv[])
{
	int indice, val[8] = {2,4647,3,7,571,169,3,2020}, ny, i;
	int val2[8] = {2,4653,3,22,571,169,1,2020};
	char file_r[N] = "datos.csv";
	double valor, **valor2;
	FILE *fp;
	lt_IHME *lt1;
	u_IHME *lt_measure;
	u_year *lt_year;
	if(argc!=3)
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
	lt_year = unique_year(lt1);
	imprimir_u_year(lt_year);
	ny = n_u_year(lt_year);
	printf("Numero de anio: %d\n", ny);
	valor = consulta_IHME(lt1, val);
	printf("%lf\n", valor);
//	2,4645,1,18,571,169,3,2020,
//  2,4647,3,7,571,169,3,2020,70.33780119676
	valor2 = (double**)malloc(2*sizeof(double*));
	if(valor2==NULL)
	{
		fclose(fp);
		return 5;
	}
	valor2[0] = (double*)malloc(2*ny*sizeof(double));
	if(valor2[0]==NULL)
	{
		fclose(fp);
		return 6;
	}
	valor2[1] = valor2[0]+ny;
	lt_year = inicio_year(lt_year);
	for(i=0; i<ny; i++)
	{
		valor2[0][i] = lt_year->y;
		val2[7] = lt_year->y;
		valor2[1][i] = consulta_IHME(lt1, val2);
		lt_year = lt_year->s;
	}
	fclose(fp);
	fp = fopen(file_r, "wt");
	if(fp==NULL)
		return 7;
	for(i=0; i<ny; i++)
		fprintf(fp, "%d,%lf\n", (int)valor2[0][i], valor2[1][i]);
	fclose(fp);
	reporte(file_r, argv[2]);
	return 0;
}