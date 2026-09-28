#include <stdio.h>

#define N 100

int main(int argc, char *argv[])
{
	char filename[10] = "datos.txt";
	int n, i;
	float x[N];
	FILE *fp;
	do{
		printf("Ingrese el numero de datos: ");
		scanf("%d", &n);
	}while(n>N||n<1);
	fp = fopen(filename, "w+t");
	fprintf(fp, "%d\n", n);
	for(i=0; i<n; i++)
	{
		printf("x[%d] = ", i+1);
		scanf("%f", &x[i]);
		fprintf(fp, "%f\n", x[i]);
	}
	fclose(fp);
	return 0;
}