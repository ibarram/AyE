#include <stdio.h>
#include "libarram.h"

#define N 20

int main(int argc, char *argv[])
{
	int val[8] = {2,130,3,22,571,169,3,2023}, nl, nr, i;
	char **estados;
	double *dato, d_max, d_min, rg, *color;
	FILE *fp;
	lt_IHME *lt1;
	u_IHME *lt_location;
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
	nl = n_u_IHME(lt_location)-1;
	printf("Num. Estados: %d\n", nl);
	estados = (char**)malloc(nl*sizeof(char*));
	if(estados==NULL)
		return 5;
	dato = (double*)malloc(nl*sizeof(double));
	if(dato==NULL)
	{
		free(estados);
		return 6;
	}
	color = (double*)malloc(nl*sizeof(double*));
	if(color==NULL)
	{
		free(estados);
		free(dato);
		return 7;
	}
	lt_location = inicio_u_IHME(lt_location);
	lt_location = lt_location->s;
	for(i=0; i<nl; i++)
	{
		estados[i] = lt_location->name;
		val[1] = lt_location->id;
		dato[i] = consulta_IHME(lt1, val);
		if(!i)
		{
			d_min = dato[i];
			d_max = dato[i];
		}
		else
		{
			if(d_min>dato[i])
				d_min = dato[i];
			if(d_max<dato[i])
				d_max = dato[i];
		}
		if(lt_location->s!=NULL)
			lt_location = lt_location->s;
	}
	rg = d_max-d_min;
	for(i=0; i<nl; i++)
		color[i] = (dato[i]-d_min)/rg;
	fp = fopen(argv[2], "wt");
	if(fp==NULL)
		return 11;
	for(i=0; i<nl; i++)
		fprintf(fp, "%s,%lf\n", estados[i], color[i]);
//		fprintf(fp, "%s,%lf,%lf\n", estados[i], dato[i], color[i]);
	fclose(fp);
	free(estados);
	free(dato);
	free(color);
	return 0;
}