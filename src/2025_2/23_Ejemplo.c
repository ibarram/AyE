#include <stdio.h>
#include "libarram.h"

#define N 20

int main(int argc, char *argv[])
{
	int val[8] = {3,130,3,22,571,169,1,2020}, ny, nr, nl, i, j;
	double **valor, max, min, rg, *grafica;
	char **estados;
	FILE *fp;
	lt_IHME *lt1;
	u_IHME *lt_location;
	u_year *lt_year;
	if(argc!=4)
		return 1;
	fp = fopen(argv[1], "rt");
	if(fp==NULL)
		return 2;
	lt1 = read_csv2(fp);
	if(lt1==NULL)
	{
		fclose(fp);
		return 3;
	}
	fclose(fp);
	nr = num_registros(lt1);
	printf("Num. registros: %d\n", nr);
	lt_location = unique_IHME(lt1, 1);
	if(lt_location==NULL)
		return 4;
	lt_year = unique_year(lt1);
	if(lt_year==NULL)
		return 5;
	nl = n_u_IHME(lt_location)-1;
	ny = n_u_year(lt_year);
	printf("Numero de estados: %d\n", nl);
	printf("Numero de anio: %d\n", ny);
	valor = (double**)malloc(nl*sizeof(double*));
	if(valor==NULL)
		return 6;
	valor[0] = (double*)calloc(nl*ny,sizeof(double));
	if(valor[0]==NULL)
		return 7;
	for(i=1; i<nl; i++)
		valor[i] = valor[i-1]+ny;
	lt_year = inicio_year(lt_year);
	lt_location = inicio_u_IHME(lt_location);
	lt_location = lt_location->s;
	for(i=0; i<nl; i++)
	{
		val[1] = lt_location->id;
		for(j=0; j<ny; j++)
		{
			val[7] = lt_year->y;
			valor[i][j] = consulta_IHME(lt1, val);
			if(lt_year->s!=NULL)
				lt_year = lt_year->s;
		}
		lt_year = inicio_year(lt_year);
		if(lt_location->s!=NULL)
			lt_location = lt_location->s;
	}
	for(i=0; i<ny; i++)
	{
		for(j=1, max=valor[0][i], min=valor[0][i]; j<nl; j++)
		{
			if(valor[j][i]>max)
				max = valor[j][i];
			if(valor[j][i]<min)
				min = valor[j][i];
		}
		rg = max-min;
		for(j=0; j<nl; j++)
			valor[j][i] = (valor[j][i]-min)/rg;
	}
	grafica = (double*)calloc(3*nl,sizeof(double));
	if(grafica==NULL)
		return 8;
	for(i=0; i<nl; i++)
	{
		for(j=1, grafica[3*i]=valor[i][0], grafica[3*i+1]=valor[i][0], grafica[3*i+2]=valor[i][0]; j<ny; j++)
		{
			grafica[3*i]+=valor[i][j];
			if(grafica[3*i+1]>valor[i][j])
				grafica[3*i+1] = valor[i][j];
			if(grafica[3*i+2]<valor[i][j])
				grafica[3*i+2] = valor[i][j];
		}
		grafica[3*i]/=ny;
	}
	reporte_2(lt_location, grafica, argv[3]);
	fp = fopen(argv[2], "wt");
	if(fp==NULL)
		return 10;
	fprintf(fp, "Estados,");
	lt_year = inicio_year(lt_year);
	for(i=0; i<ny; i++)
	{
		if(i!=ny-1)
			fprintf(fp, "%d,", lt_year->y);
		else
			fprintf(fp, "%d\n", lt_year->y);
		if(lt_year->s!=NULL)
			lt_year = lt_year->s;
	}
	lt_location = inicio_u_IHME(lt_location);
	lt_location = lt_location->s;
	for(i=0; i<nl; i++)
	{
		fprintf(fp,"%s,", lt_location->name);
		for(j=0; j<ny-1; j++)
			fprintf(fp, "%lf,", valor[i][j]);
		fprintf(fp, "%lf\n", valor[i][j]);
		if(lt_location->s!=NULL)
			lt_location = lt_location->s;
	}
	fclose(fp);
	return 0;
}