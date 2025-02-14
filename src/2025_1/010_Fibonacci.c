#include <stdio.h>

long int Fibonacci_BU(long int n)
{
	long int i, fn, dp[3];
	if(n<2)
		return n;
	dp[0]=0;
	dp[1]=1;
	for(i=2; i<=n; i++)
		dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3];
	return dp[(i-1)%3];
}

long int Fibonacci_TD(long int n)
{
	if(n<2)
		return n;
	else
		return Fibonacci_TD(n-1)+Fibonacci_TD(n-2);
}

int main(int argc, char *argv[])
{
	long int n, fn1, fn2;
	do{
		printf("Ingrese el termino: ");
		scanf("%ld", &n);
	}while(n<0);
	fn1 = Fibonacci_BU(n);
	fn2 = Fibonacci_TD(n);
	printf("F(%ld) = %ld\n", n, fn1);
	printf("F(%ld) = %ld\n", n, fn2);
	return 0;
}