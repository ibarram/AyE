#include <stdio.h>

#define N 100

int main(int argc, char *argv[])
{
	int n, i;
	float x[N];
	FILE *fp;
	if(argc!=2)
		return 1;
	fp = fopen(argv[1], "rb");
	if(fp==NULL)
		return 2;
	fread(&n, sizeof(int), 1, fp);
	fread(x, sizeof(float), n, fp);
	for(i=0; i<n; i++)
		printf("x[%d] = %f\n", i+1, x[i]);
	fclose(fp);
	return 0;
}