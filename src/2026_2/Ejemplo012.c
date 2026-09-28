#include <stdio.h>

#define N 100

int main(int argc, char *argv[])
{
	char filename[10] = "datos.bin";
	int n, i;
	float x[N];
	FILE *fp;
	do{
		printf("Ingrese el numero de datos: ");
		scanf("%d", &n);
	}while(n>N||n<1);
	fp = fopen(filename, "w+b");
	fwrite(&n, sizeof(int), 1, fp);
	for(i=0; i<n; i++)
	{
		printf("x[%d] = ", i+1);
		scanf("%f", &x[i]);
	}
	fwrite(x, sizeof(float), n, fp);
	fclose(fp);
	return 0;
}