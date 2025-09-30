#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	INEGI info;
	long int nr;
	int anio[6] = {1990, 1995, 2000, 2005, 2010, 2020}, i, j;
	long int id[21] = {	1002000058, 1002000088, 1002000061, 1002000067, 
						1002000070, 1002000073, 1002000076, 1002000079, 
						1002000082, 1002000085, 1002000091, 1002000094,
						1002000097, 1002000100, 1002000103, 1002000106,
						1002000109, 1002000112, 1002000115, 1002000118, 
						1002000064};
	double *ev_pob, *pot_tot, valor;
	if(argc!=2)
		return 1;
	printf("Lectura de datos.\n");
	info.fp = fopen(argv[1], "rb");
	if(info.fp==NULL)
		return 2;
	fread(&info.nr, sizeof(long int), 1, info.fp);
	info.data = (INEGI_CSV*)calloc(info.nr, sizeof(INEGI_CSV));
	if(info.data==NULL)
	{
		fclose(info.fp);
		return 3;
	}
	fread(info.data, sizeof(INEGI_CSV), info.nr, info.fp);
	printf("Numero de registros: %ld\n", info.nr);
	ev_pob = (double*)calloc(66, sizeof(double));
	if(ev_pob==NULL)
	{
		free(info.data);
		fclose(info.fp);
		return 4;
	}
	pot_tot = (double*)calloc(6, sizeof(double));
	if(pot_tot==NULL)
	{
		free(ev_pob);
		free(info.data);
		fclose(info.fp);
		return 5;
	}
	printf("Consulta de informacion.\n");
	for(i=0; i<6; i++)
		for(j=0; j<21; j++)
		{
			valor = consulta(&info, 0, 0, id[j], anio[i]);
			ev_pob[11*i+j/2] += valor;
			pot_tot[i] += valor;
		}
	printf("Impresion.\n");
	printf("\t");
	for(i=0; i<6; i++)
		printf("%04d\t", anio[i]);
	printf("\n");
	for(i=0; i<11; i++)
	{
		printf("%0*d-%0*d\t", 2+i/10, i*10, 2+i/10, (i+1)*10);
		for(j=0; j<6; j++)
		{
			ev_pob[11*j+i] /= pot_tot[j];
			printf("%2.2lf\t", 100*ev_pob[11*j+i]);
		}
		printf("\n");
	}
	fclose(info.fp);
	free(pot_tot);
	free(ev_pob);
	free(info.data);
	return 0;
}