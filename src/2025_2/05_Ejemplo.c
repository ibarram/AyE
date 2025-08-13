#include <stdio.h>

long int Fibonacci_BU(int n)
{
	long int F[3];
	int i;
	F[0] = 0;
	F[1] = 1;
	for(i=2; i<=n; i++)
		F[i%3] = F[(i-1)%3]+F[(i-2)%3];
	return F[n%3];
}

long int Fibonacci_TD(int n)
{
	if(n<2)
		return n;
	else
		return Fibonacci_TD(n-1)+Fibonacci_TD(n-2);
}

int main(int argc, char *argv[])
{
	int n;
	long int f1, f2;
	scanf("%d", &n);
	f1 = Fibonacci_BU(n);
	printf("F(%d) = %ld\n", n, f1);
	f2 = Fibonacci_TD(n);
	printf("F(%d) = %ld\n", n, f2);
	return 0;
}