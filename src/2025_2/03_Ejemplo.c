#include <stdio.h>

#define SWAP(a, b) {\
a^=b;\
b^=a;\
a^=b;\
}

int main(int argc, char *argv[])
{
	long int a, b, c, d;
	scanf("%ld %ld %ld %ld", &a, &b, &c, &d);
	if(a>b)
		SWAP(a,b);
	if(c>d)
		SWAP(c,d);
	if(a>c)
		SWAP(a,c);
	if(b>d)
		SWAP(b,d);
	printf("%ld\n", d-a);
	return 0;
}