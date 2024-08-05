#include <stdio.h>
#include <math.h>

/**
 * Calcula el factorial de un número entero.
 * 
 * @param n El número entero del cual se quiere calcular el factorial.
 * @return El factorial del número dado.
 */
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

/**
 * Calcula la aproximación del seno de x usando la serie de Taylor.
 * 
 * @param x El valor en radianes del cual se quiere calcular el seno.
 * @param terms El número de términos de la serie de Taylor a usar en la aproximación.
 * @return La aproximación del seno de x.
 */
double taylor_sin(double x, int terms) {
    double result = 0.0;
    for (int n = 0; n < terms; n++) {
        double term = pow(-1, n) * pow(x, 2 * n + 1) / factorial(2 * n + 1);
        result += term;
    }
    return result;
}

/**
 * Función principal que solicita al usuario el valor de x y el número de términos,
 * y luego calcula y muestra la aproximación del seno usando la serie de Taylor 
 * y el valor real del seno utilizando la función sin() de la biblioteca math.h.
 * 
 * @return 0 si el programa finaliza correctamente.
 */
int main() {
    double x;
    int terms;

    // Solicita al usuario que introduzca el valor de x
    printf("Introduce el valor de x: ");
    scanf("%lf", &x);

    // Solicita al usuario que introduzca el número de términos de la serie de Taylor
    printf("Introduce el número de términos de la serie de Taylor: ");
    scanf("%d", &terms);

    // Calcula la aproximación de sin(x) usando la serie de Taylor
    double approx_sin = taylor_sin(x, terms);
    
    // Calcula el valor real de sin(x)
    double actual_sin = sin(x);

    // Imprime los resultados
    printf("Aproximación de sin(%.2f) usando %d términos: %.10f\n", x, terms, approx_sin);
    printf("Valor real de sin(%.2f): %.10f\n", x, actual_sin);

    return 0;
}