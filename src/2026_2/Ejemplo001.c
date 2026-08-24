#include <stdio.h>

int t2i(char *str)
{
	int n = 0, i = 0;
	while(str[i]>='0'&&str[i]<='9')
	{
		n*=10;
		n += str[i++]-'0';
	}
	return n;
}

float t2f(char *str)
{
	float x = 0, xf = 0, c = 10;
	int i = (str[0]=='-'?1:0);
	while(str[i]>='0'&&str[i]<='9')
	{
		x *= 10;
		x += str[i++]-'0';
	}
	if(str[i++] == '.')
	{
		while(str[i]>='0'&&str[i]<='9')
		{
			xf = str[i++]-'0';
			xf /= c;
			c *= 10;
			x += xf;
		}
	}
	return (str[0]=='-'?-x:x);
}

float fsin(float x, int n)
{
	int i, sg;
	float sx, fct;
	for(i=0, sx=0, fct=x, sg=1; i<n; i++)
	{
		sx += sg*fct;
		fct *= (x/(2*i+2))*(x/(2*i+3));
		sg *= -1;
	}
	return sx;
}

/*
float fsin(float x, int n)
{
	float sx;
	static float fct;
	if(n<1)
		return 0;
	else if(n==1)
	{
		fct = x;
		printf("fsin(%f, %d) = %f\tsx = %f\tfct = %f\t%d %d\n", x, n, x, sx, fct, n, n);
		return x;
	}
	else
	{
		fct *= (2*(n%2)-1)*(x/(2*(n-1)))*(x/(2*(n-1)+1));
		printf("fsin(%f, %d) = %f\tsx = %f\tfct = %f\t%f %f %d\n", x, n, sx, sx, fct, x/(2*(n-1)), x/(2*(n-1)+1), 2*(n%2)-1);
		return fsin(x, n-1)+fct;
	}
	return sx;
}
*/

int main(int argc, char *argv[])
{
	int n;
	float sx, x;
	if(argc!=3)
		return 1;
	x = t2f(argv[1]);
	n = t2i(argv[2]);
	sx = fsin(x, n);
	printf("sin(%f,%d) = %f\n", x, n, sx);
	return 0;
}