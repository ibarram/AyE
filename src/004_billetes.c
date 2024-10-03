#include <stdio.h>

/**
 * Función: s2l
 * ----------------------------
 *   Convierte una cadena de caracteres (string) que representa un número
 *   en su valor numérico equivalente de tipo `long int`.
 * 
 *   Parámetros:
 *       char *str: La cadena de caracteres que contiene un número en formato de texto.
 * 
 *   Retorna:
 *       long int: El número convertido de la cadena.
 */
long int s2l(char *str)
{
	long int X = 0;   // Variable que almacena el resultado numérico
	int i = 0;        // Índice para iterar sobre la cadena de caracteres

	// Recorre la cadena mientras cada carácter sea un dígito ('0' a '9')
	while(str[i] >= '0' && str[i] <= '9')
	{
		// Multiplica el resultado anterior por 10 y suma el valor numérico del carácter actual
		X *= 10;
		X += (str[i++] - '0');  // Convierte el carácter a su valor numérico restando '0'
	}
	return X;  // Retorna el valor convertido
}

/**
 * Función principal: main
 * ----------------------------
 *   El programa calcula la cantidad de billetes de valor A para pagar la cantidad S.
 *   Considera que solo tiene dos cantidades A y B y ambas son diferentes, además que
 *   solo cuenta con N billetes exactamente para pagar. En el caso que el problema no
 *   tenga solución regresa el valor de -1.
 *   El problema implementa la fórmula:
 * 
 *       X = (S - N * B) / (A - B)
 * 
 *   Se verifican las condiciones necesarias para que el valor de X sea válido
 *   y si no se cumplen, el programa retorna -1.
 * 
 *   Parámetros:
 *       int argc: Número de argumentos proporcionados en la línea de comandos.
 *       char *argv[]: Arreglo que contiene los argumentos como cadenas de texto.
 * 
 *   Retorna:
 *       int: Código de estado de salida (0 para éxito, -1 para error).
 */
int main(int argc, char *argv[])
{
	// Declaración de variables
	long int A, B, S, N, X;  // Variables de tipo entero largo
	double Xf;               // Variable de tipo doble para almacenar el resultado de X en formato de punto flotante

	// Verifica si el número de argumentos es correcto (deben ser 4 argumentos)
	if(argc != 5)
		return -1;

	// Convierte los argumentos de la línea de comandos a enteros largos
	A = s2l(argv[1]);
	B = s2l(argv[2]);
	S = s2l(argv[3]);
	N = s2l(argv[4]);

	// Calcula el valor de X (en formato entero) y Xf (en formato de punto flotante)
	X = (S - N * B) / (A - B);  // Cálculo en enteros
	Xf = ((S - N * B) / ((double)(A - B)));  // Cálculo en punto flotante

	// Verifica si X es igual a Xf (es decir, si el resultado entero es igual al resultado de punto flotante)
	if(X != Xf)
		printf("-1\n");  // Si no son iguales, significa que el valor no es un número entero exacto

	// Verifica si X está dentro de los límites aceptables (entre 0 y N)
	else if(X < 0 || X > N)
		printf("-1\n");  // Si X está fuera de los límites, se imprime -1

	// Si X es válido, se imprime el valor de X
	else
		printf("%ld\n", X);

	return 0;  // Retorna 0 para indicar éxito
}
