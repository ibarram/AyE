#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Función principal que calcula la aproximación del seno de un número utilizando
 * una serie de Taylor optimizada. Los parámetros se pasan como argumentos de la línea de comandos.
 * 
 * @param argc El número de argumentos pasados al programa.
 * @param argv El arreglo de argumentos pasados al programa.
 * @return 0 si el programa finaliza correctamente, 1 si hay un error en los argumentos.
 */
int main(int argc, char *argv[]) {
    double x, sx, fct;
    long int n, i;

    // Verifica que se pasen exactamente dos argumentos: el valor de x y el número de términos n
    if (argc != 3) {
        fprintf(stderr, "Uso: %s <valor de x> <número de términos>\n", argv[0]);
        return 1;
    }

    // Convierte los argumentos de la línea de comandos a sus respectivos tipos
    x = atof(argv[1]);
    n = atol(argv[2]);

    // Inicializa las variables para la serie de Taylor
    for (i = 0, fct = x, sx = 0; i < n; i++) {
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