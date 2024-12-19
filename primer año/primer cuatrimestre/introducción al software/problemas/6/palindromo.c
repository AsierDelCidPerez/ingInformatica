/**
 * @file palindromo.c
 *
 * @brief Analizar si un string es o no palíndromo.
 *
 * @author  ASIER <adp471@alumnos.unican.es>
 * @version 2024-11-12
 *
 **/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_TEXTO 100

/**
 * @brief Reemplaza (por referencia) los espacios de la cadena por el primer
 * carácter no espacio siguiente al carácter reempleazado. Se refiere al carácter
 * espacio como el carácter ASCII 32. El resultado útil de esta transformación
 * es el contenido hasta el primer \0 (podría haber ruido por este algoritmo
 * de transformación).
 * @param texto cadena de caracteres (por referencia) a la que someter la 
 * transformación
 */
void quita_espacios (char texto[]);

/**
 * @brief Analiza si una cadena de texto es palíndromo o no (es equivalente a su
 * forma invertida/reverse). Se considera la cadena vacía como palíndroma, ya que
 * es equivalente a su forma invertida (la cadena vacía). La función es 
 * case-sensitive además de ser sensible a caracteres no alfabéticos (es ASCII
 * sensitive).
 * @param texto cadena de tetxo a analizar.
 * @return true si es palíndromo y false si no lo es.
 */

bool es_palindromo (char texto[]);

int main (void) {
    // Input
    char texto[MAX_TEXTO + 1] = "dabale arroz a la zorra el abad";
    // Algoritmo
    quita_espacios (texto);
    if (es_palindromo (texto)) {
        printf ("Es palíndromo\n");
    }
    else {
        printf ("No es palíndromo\n");
    }
    return 0;
}

void quita_espacios (char texto[]) {
    int contador = 0;
    /*
     * mediante una búsqueda lineal si el carácter actual es un espacio
     * entonces lo reemplaza con el próximo carácter no espacio.
     */
    for (int i = 0; i < strlen (texto); i++) {
        if (texto[i] != ' ') {
            texto[contador] = texto[i];
            contador++;
        }
    }
    texto[contador] = '\0';
    // Hasta \0 la transformación solicitada es correcta (puede haber ruido).
}

bool es_palindromo (char texto[]) {
    int mitad_texto = strlen (texto) / 2 + 1;
    
    /*
     * Se usa el algoritmo de two-pointers para la solución de este problema:
     * mediante una búsqueda lineal hasta la mitad del texto se itera (con it)
     * y se compara que texto[it] sea igual a texto[it_dual] donde it_dual es el
     * iterador simétrico respecto a la cadena.
     */
    
    for (int it = 0; it < mitad_texto; it++) {
        int it_dual = strlen (texto) - it - 1;
        if (texto[it] != texto[it_dual]) {
            return false;
        }
    }
    
    return true;
}
