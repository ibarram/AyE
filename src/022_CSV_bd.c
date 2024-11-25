#include <stdio.h>
#include "libarram.h"

#define NC 100

int main(int argc, char *argv[])
{
	long int nr, reg, reg_mun;
	bd_INEGI Datos;
	char fn[] = "edr_valor_00.csv", *filename;
	filename = (argc==2?argv[1]:fn);
	lectura_bd(filename, &Datos);
	do{
		printf("Ingrese el registro para consultar: ");
		scanf("%ld", &reg);
	}while(reg<0||reg>=Datos.nr);
	printf("CVE entidad: %s (%d)\n", Datos.desc_entidad.palabra[Datos.cve_entidad[reg]], Datos.cve_entidad[reg]);
	printf("%d\t%d\t%ld\n", Datos.cve_entidad[reg], Datos.cve_municipio[reg], Datos.desc_municipio.id[Datos.cve_entidad[reg]][Datos.cve_municipio[reg]]);
	reg_mun = Datos.desc_municipio.id[Datos.cve_entidad[reg]][Datos.cve_municipio[reg]];
	printf("%ld\n", reg_mun);
	printf("CVE municipio: %s (%d)\n", Datos.desc_municipio.palabra[reg_mun], Datos.cve_municipio[reg]);
	printf("ID indicador: %s (%ld)\n", buscar(Datos.indicador, Datos.id_indicador[reg]), Datos.id_indicador[reg]);
	printf("Año: %d\n", Datos.anio[reg]);
	printf("Valor : %ld\n", Datos.valor[reg]);
	liberar_bd(Datos);
	return 0;
}