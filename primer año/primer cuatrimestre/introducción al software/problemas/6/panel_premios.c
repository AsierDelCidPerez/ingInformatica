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
	const int panel [FILAS][COLUMNAS] = {
        {1, 3, 0, 10, 5, 5},
        {5, 1, 0, 0, 1, 1},
        {2, 10, 7, 3, 0, 0},
        {2, 5, 10, 0, 1, 7},
        {1, 3, 0, 10, 5, 0},
        {1, 3, 0, 10, 3, 4}
    };
    
    printf ("Introduzca la fila elegida: ");
    char fila = get_user_char();
    printf ("Introduzca la columna elegida: ");
    int col = get_user_int();
    
    printf ("Felicidades, has ganado %d €.\n", calcuta_premio(panel, fila, col));
	return 0;
}

int max (int x, int y) {
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
    
    for (int i=0; i < max (FILAS, COLUMNAS); i++) {
        if (i < COLUMNAS) {
            sumatorio += panel [fila] [i];
        }
        if (i < FILAS) {
            sumatorio += panel[i][columna_elegida];
        }
    }
    
    sumatorio -= panel [fila] [columna_elegida];
    return sumatorio;
}
