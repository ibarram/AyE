float suma(float a, float b)
{
	return a+b;
}

/*
long int factorial(long int n)
{
	if(n<=1)
		return 1;
	return n*factorial(n-1);
}
*/

int cambio(int E, int A, int B)
{
	int Zi;
	Zi = (E/A)*B;
	return Zi?Zi+cambio(Zi+E-(Zi*A)/B,A,B):0;
}

int chocolate(int X, int Y, int A, int B)
{
	return X/Y+cambio(X/Y,A,B);
}

float potencia(float x, int n)
{
	return n?x*potencia(x,n-1):1;
}

long int factorial(long int n)
{
	return n?n*factorial(n-1):1;
}

float exp1(float x, int n)
{
	return n?potencia(x,n)/factorial(n)+exp1(x,n-1):1;
}

float factor(float x, int n)
{
	return n?(x/n)*factor(x,n-1):1;
}

float exp3(float x, int n)
{
	return n?factor(x, n)+exp3(x,n-1):1;
}

float exp4(float x, int n)
{
	static int i = 0;
	static float fct = 1;
	i++;
	fct*=(x/i);
	if(n)
	{
		return fct+exp4(x,n-1);
	}
	else
	{
		i = 0;
		fct = 1;
		return 1;
	}
}
