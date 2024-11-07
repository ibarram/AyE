#include <stdio.h>
#include "libarram.h"

#define NC 100

int main(int argc, char *argv[])
{
	FILE *fp;
	int cve_entidad, i;
	char c, str[NC];
	if(argc==2)
		fp = fopen(argv[1], "rt");
	else
		fp=fopen("edr_valor_00.csv", "rt");
	if(fp==NULL)
		return 1;
	fflush(fp);
	do{
		c = getc(fp);
	}while(c!=10);
	fscanf(fp, "%d", &cve_entidad);
	printf("%d\n", cve_entidad);
	getc(fp);
	i=0;
	do{
		str[i++] = getc(fp);
	}while(str[i-1]!=',');
	str[i-1] = '\0';
	printf("%s\n", str);
	return 0;
}