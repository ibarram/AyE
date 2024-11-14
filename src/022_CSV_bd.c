#include <stdio.h>
#include "libarram.h"

#define NC 100

int main(int argc, char *argv[])
{
	long int nr, reg;
	bd_INEGI Datos;
	char fn[] = "edr_valor_00.csv", *filename;
	filename = (argc==2?argv[1]:fn);
	lectura_bd(filename, &Datos);
	do{
		printf("Ingrese el registro para consultar: ");
		scanf("%ld", &reg);
	}while(reg<0||reg>=Datos.nr);
	printf("CVE entidad: %s (%d)\n", Datos.desc_entidad.palabra[Datos.cve_entidad[reg]], Datos.cve_entidad[reg]);
	printf("CVE municipio: %d\n", Datos.cve_municipio[reg]);
	printf("ID indicador: %ld\n", Datos.id_indicador[reg]);
	printf("Año: %d\n", Datos.anio[reg]);
	printf("Valor : %ld\n", Datos.valor[reg]);
	printf("%ld\n", Datos.desc_entidad.np);
	liberar_bd(Datos);
	return 0;
}