/**
 * @file panel_premios.c
 *
 * @brief Analizar si un string es o no palíndromo.
 *
 * @author  ASIER <adp471@alumnos.unican.es>
 * @version 2024-11-12
 *
 **/

#include <stdio.h>
#include "intro.h"
#define FILAS    6
#define COLUMNAS 6

/**
 * @brief Devuelve el valor máximo entre dos valores.
 * @param x primer valor
 * @param y segundo valor
 * @return el valor máximo entre x e y (max{x, y}).
 */
int max (int x, int y);

/**
 * @brief Calcula el premio en base a una tabla de premios. El premio
 * para un elemento (i, j) se calcula como la suma de todos los valores
 * de los elementos con los que que comparten fila o columna, no repetidos.
 * @param panel matriz de enteros (como referencia constante) que corresponde
 * a la tabla de premios.
 * @param fila_elegida carácter ASCII (letra mayúscula) que corresponde 
 * la fila elegida.
 * @param columna_elegida entero que representa la columna elegida.
 * @return entero que corresponde al premio calculado de la forma previamente
 * especificada.
 */
int calcuta_premio (const int panel[FILAS][COLUMNAS], char fila_elegida, int columna_elegida);

int main (void) {
    // Declaramos el panel como constante del main.
    const int panel[FILAS][COLUMNAS] = {{1, 3, 0, 10, 5, 5}, {5, 1, 0, 0, 1, 1},
                                        {2, 10, 7, 3, 0, 0}, {2, 5, 10, 0, 1, 7},
                                        {1, 3, 0, 10, 5, 0}, s{1, 3, 0, 10, 3, 4}};
    
    // Input del programa.
    printf ("Introduzca la fila elegida: ");
    char fila = get_user_char();
    printf ("Introduzca la columna elegida: ");
    int col = get_user_int();
    
    // Output del programa.
    printf ("Felicidades, has ganado %d €.\n", calcuta_premio (panel, fila, col));
    return 0;
}

int max (int x, int y) {
    // Asumimos que y es el mayor mientras no se descubra lo contrario.
    int mayor = y;
    if (x > y) {
        mayor = x;
    }
    return mayor;
}

int calcuta_premio (const int panel[FILAS][COLUMNAS], char fila_elegida, int columna_elegida) {
    int fila = fila_elegida - 'A';
    int sumatorio = 0;
    columna_elegida--;
    
    /*
     * Por optimización se reduce dos búsquedas lineales a una búsqueda lineal
     * sobre el máximo. De manera que en el mejor caso FILAS=COLUMNAS, en este caso
     * este algoritmo itera la mitad de veces (tomamos ambos valores de órdenes
     * suficientemente elevados para despreciar los ifs). Por reducir, resulta obvio
     * que a mayor sea (min(FILAS, COLUMNAS)/max(FILAS, COLUMNAS)) la optimización del
     * algoritmo será más considerable en comparación con la complejidad 
     * constituida por dos búsquedas lineales.
     */
    for (int i = 0; i < max (FILAS, COLUMNAS); i++) {
        if (i < COLUMNAS) {
            sumatorio += panel[fila][i];
        }
        if (i < FILAS) {
            sumatorio += panel[i][columna_elegida];
        }
    }
    
    sumatorio -= panel[fila][columna_elegida];
    return sumatorio;
}
