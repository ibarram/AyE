#include <stdio.h>
#include <math.h>

typedef struct Z{
	float a;
	float b;
}Z;

Z capturar(void)
{
	Z aux;
	printf("Ingrese el real: ");
	scanf("%f", &aux.a);
	printf("Ingrese el imaginario: ");
	scanf("%f", &aux.b);
	return aux;
}

void imprimir(Z aux)
{
	printf("%f%+fi\n", aux.a, aux.b);
}

Z suma(Z aux1, Z aux2)
{
	Z aux3;
	aux3.a = aux1.a+aux1.b;
	aux3.b = aux1.b+aux1.b;
	return aux3;
}

Z multiplicacion(Z aux1, Z aux2)
{
	Z aux3;
	aux3.a = aux1.a*aux2.a-aux1.b*aux2.b;
	aux3.b = aux1.a*aux2.b+aux2.a*aux1.b;
	return aux3;
}

Z inverso(Z aux1)
{
	Z aux2;
	float mg;
	mg = aux1.a*aux1.a+aux1.b*aux1.b;
	aux2.a = (mg?aux1.a/mg:0);
	aux2.b = (mg?-aux1.b/mg:0);
	return aux2;
}

Z division(Z aux1, Z aux2)
{
	Z aux3;
	aux3 = multiplicacion(aux1, inverso(aux2));
	return aux3;
}

int main(int argc, char *argv[])
{
	Z Z1, Z2, Z3, Z4;
	Z1 = capturar();
	Z2 = capturar();
	printf("Z1 = ");
	imprimir(Z1);
	printf("Z2 = ");
	imprimir(Z2);
	Z3 = suma(Z1, Z2);
	printf("Z1 + Z2 = ");
	imprimir(Z3);
	Z4 = division(Z1, Z2);
	printf("Z1 / Z2 = ");
	imprimir(Z4);
	printf("sizeof(float) = %ld\n", sizeof(float));
	printf("sizeof(Z) = %ld\n", sizeof(Z));
	return 0;
}