#include <stdio.h>

#define N 100

int main(int argc, char *argv[])
{
	int n, i;
	float x[N];
	FILE *fp;
	if(argc!=2)
		return 1;
	fp = fopen(argv[1], "rt");
	if(fp==NULL)
		return 2;
	fscanf(fp, "%d\n", &n);
	for(i=0; i<n; i++)
	{
		fscanf(fp, "%f\n", &x[i]);
		printf("x[%d] = %f\n", i+1, x[i]);
	}
	fclose(fp);
	return 0;
}