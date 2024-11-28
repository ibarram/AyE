#include <stdio.h>
#include "libarram.h"

#define NC 100

int main(int argc, char *argv[])
{
	long int nr, reg, reg_ent, reg_mun;
	bd_INEGI Datos;
	char fn[] = "edr_valor_00.csv", *filename;
	filename = (argc==2?argv[1]:fn);
	lectura_bd(filename, &Datos);
	//imprimir_dr(Datos.desc_entidad);
	//imprimir_di(Datos.indicador);
	//imprimir_dd(Datos.desc_municipio);
	do{
		printf("Ingrese el registro para consultar: ");
		scanf("%ld", &reg);
	}while(reg<0||reg>=Datos.nr);
	reg_ent = Datos.cve_entidad[reg];
	if(Datos.cve_entidad[reg]==36)
		reg_ent=33;
	if(Datos.cve_entidad[reg]==99)
		reg_ent=34;
	printf("CVE entidad: %s (%d)\n", Datos.desc_entidad.palabra[reg_ent], Datos.cve_entidad[reg]);
	reg_mun = Datos.desc_municipio.id[Datos.cve_entidad[reg]][Datos.cve_municipio[reg]];
	printf("CVE municipio: %s (%d)\n", Datos.desc_municipio.palabra[reg_mun], Datos.cve_municipio[reg]);
	printf("ID indicador: %s (%ld)\n", buscar(Datos.indicador, Datos.id_indicador[reg]), Datos.id_indicador[reg]);
	printf("Año: %d\n", Datos.anio[reg]);
	printf("Valor : %ld\n", Datos.valor[reg]);
	liberar_mem(&Datos);
	//liberar_bd(Datos);
	//printf("%ld\n", Datos.nr);
	return 0;
}