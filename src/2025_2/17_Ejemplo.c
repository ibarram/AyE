#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	fp = fopen(argc==1?"Prueba.txt":argv[1], "w+t");
	if(fp==NULL)
		return 1;
	fprintf(fp, "Hola mundo.\n");
	fclose(fp);
	return 0;
}