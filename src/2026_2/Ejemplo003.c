#include <stdio.h>
#include <math.h>
#include <time.h>

long int fibonacci_1(long int n)
{
	if(n<=1)
		return n;
	else
		return fibonacci_1(n-1)+fibonacci_1(n-2);
}

long int fibonacci_BU(long int n)
{
	long int dp[n+1];
	int i;
	if(n<=1)
		return n;
	dp[0] = 0;
	dp[1] = 1;
	for(i=2; i<=n; i++)
		dp[i] = dp[i-1] + dp[i-2];
	return dp[n];
}

long int fibonacci_3(long int n)
{
	return fibonacci_BU(n);
}

long int fibonacci_TD(long int n, long int m[])
{
	if(n<=1&&n>-1)
		return n;
	if(m[n]==-1)
		m[n] = fibonacci_TD(n-1, m)+fibonacci_TD(n-2, m);
	return m[n];
}

long int fibonacci_2(long int n)
{
	long int m[n+1];
	int i;
	for(i=0; i<=n; i++)
		m[i] = -1;
	return fibonacci_TD(n, m);
}

int main(int argc, char *argv[])
{
	long int n, fn1, fn2, fn3;
	double dt1, dt2, dt3;
	time_t t1, t2;
	printf("Ingrese el valor de n: ");
	scanf("%ld", &n);
	time(&t1);
	fn1 = fibonacci_1(n);
	time(&t2);
	dt1 = difftime(t2,t1);
	printf("F(%ld) = %ld (%lf)\n", n, fn1, dt1);
	time(&t1);
	fn2 = fibonacci_2(n);
	time(&t2);
	dt2 = difftime(t2,t1);
	printf("F(%ld) = %ld (%lf)\n", n, fn2, dt2);
	time(&t1);
	fn3 = fibonacci_3(n);
	time(&t2);
	dt3 = difftime(t2,t1);
	printf("F(%ld) = %ld (%lf)\n", n, fn3, dt3);	
	return 0;
}
