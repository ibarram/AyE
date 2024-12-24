#include<stdio.h>
#include<math.h>
#include<time.h>
#include"libarram.h"

int main(int argc, char *argv[])
{
	int i, n;
	float x, exr, ex1, ex2, ex3, err1, err2, err3;
	clock_t ini, fin;
	double t1, t2 ,t3;
	scanf("%f %d", &x, &n);
	exr = exp(x);
	for(i=1; i<n; i<<=1)
	{
		ini = clock();
		ex1 = exp1(x, i);
		fin = clock();
		err1 = fabs(exr-ex1);
		t1 = ((double) (fin - ini))/CLOCKS_PER_SEC;
		ini = clock();
		ex2 = exp3(x, i);
		fin = clock();
		err2 = fabs(exr-ex2);
		t2 = ((double) (fin - ini))/CLOCKS_PER_SEC;
		ini = clock();
		ex3 = exp4(x, i);
		fin = clock();
		t3 = ((double) (fin - ini))/CLOCKS_PER_SEC;
		err3 = fabs(exr-ex3);		
		printf("%d\t%.4f (%.4lf)\t%.4f (%lf)\t%.4f (%lf)\n", i, err1, t1, err2, t2, err3, t3);
	}
	return 0;
}