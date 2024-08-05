#include <stdio.h>
#include <math.h>

/**
 * Función principal que solicita al usuario el valor de x y el número de términos,
 * y luego calcula y muestra la aproximación del seno usando una serie de Taylor
 * optimizada y el valor real del seno utilizando la función sin() de la biblioteca math.h.
 * 
 * @param argc El número de argumentos pasados al programa.
 * @param argv El arreglo de argumentos pasados al programa.
 * @return 0 si el programa finaliza correctamente.
 */
int main(int argc, char *argv[]) {
    double x, sx, fct;
    long int n, i;

    // Solicita al usuario que introduzca el valor de x
    printf("Introduce el valor de x: ");
    scanf("%lf", &x);

    // Solicita al usuario que introduzca el número de términos de la serie de Taylor
    printf("Introduce el número de términos de la serie de Taylor: ");
    scanf("%ld", &n);

    // Inicializa las variables para la serie de Taylor
    for(i = 0, fct = x, sx = 0; i < n; i++) {
        // Calcula la suma de la serie de Taylor para sin(x)
        sx += (2 * ((i + 1) % 2) - 1) * fct;
        // Calcula el siguiente término de la serie
        fct *= (x / (2 * i + 2)) * (x / (2 * i + 3));
    }

    // Almacena la aproximación de sin(x) usando la serie de Taylor
    double approx_sin = sx;
    // Calcula el valor real de sin(x)
    double actual_sin = sin(x);

    // Imprime los resultados
    printf("Aproximación de sin(%.2f) usando %ld términos: %.10f\n", x, n, approx_sin);
    printf("Valor real de sin(%.2f): %.10f\n", x, actual_sin);

    return 0;
}