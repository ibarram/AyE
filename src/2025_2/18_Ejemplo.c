#include <stdio.h>
#include "libarram.h"

int main(int argc, char *argv[])
{
	INEGI info;
	long int nr;
	char c;
	int anio[6] = {1990, 1995, 2000, 2005, 2010, 2020}, i, j;
	/*
	1002000058,Población de 0 a 4 años
	1002000088,Población de 5 a 9 años
	1002000061,Población de 10 a 14 años
	1002000067,Población de 15 a 19 años
	1002000070,Población de 20 a 24 años
	1002000073,Población de 25 a 29 años
	1002000076,Población de 30 a 34 años
	1002000079,Población de 35 a 39 años
	1002000082,Población de 40 a 44 años
	1002000085,Población de 45 a 49 años
	1002000091,Población de 50 a 54 años
	1002000094,Población de 55 a 59 años
	1002000097,Población de 60 a 64 años
	1002000100,Población de 65 a 69 años
	1002000103,Población de 70 a 74 años
	1002000106,Población de 75 a 79 años
	1002000109,Población de 80 a 84 años
	1002000112,Población de 85 a 89 años
	1002000115,Población de 90 a 94 años
	1002000118,Población de 95 a 99 años
	1002000064,Población de 100 años y más
	*/
	long int id[21] = {	1002000058, 1002000088, 1002000061, 1002000067, 
						1002000070, 1002000073, 1002000076, 1002000079, 
						1002000082, 1002000085, 1002000091, 1002000094,
						1002000097, 1002000100, 1002000103, 1002000106,
						1002000109, 1002000112, 1002000115, 1002000118, 
						1002000064};
	double *ev_pob, *pot_tot, valor;
	info.fp = fopen("cpv_valor_00.csv", "rt");
	if(info.fp==NULL)
		return 1;
	info.nr = 0;
	info.data = NULL;
	printf("Lectura de datos.\n");
	nr=read_csv(&info);
	printf("Numero de registros: %ld\n", nr);
	ev_pob = (double*)calloc(66, sizeof(double));
	if(ev_pob==NULL)
	{
		free(info.data);
		fclose(info.fp);
		return 2;
	}
	pot_tot = (double*)calloc(6, sizeof(double));
	if(pot_tot==NULL)
	{
		free(ev_pob);
		free(info.data);
		fclose(info.fp);
		return 3;
	}
	printf("Consulta de informacion.\n");
	for(i=0; i<6; i++)
		for(j=0; j<21; j++)
		{
			valor = consulta(&info, 11, 0, id[j], anio[i]);
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
	if(argc==2)
	{
		info.fp = fopen(argv[1], "wb");
		if(info.fp==NULL)
		{
			free(pot_tot);
			free(ev_pob);
			free(info.data);
			return 4;
		}
		fwrite(&info.nr, sizeof(long int), 1, info.fp);
		fwrite(info.data, sizeof(INEGI_CSV), info.nr, info.fp);
	}
	fclose(info.fp);
	free(pot_tot);
	free(ev_pob);
	free(info.data);
	return 0;
}