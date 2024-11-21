/**
 * @file concursantes.c
 *
 * @brief Programa para consultar si un número es ganador o no, con 
 * respecto a un array de ganadores generados aleatoriamente.
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-10-01
 *
 **/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MIN_NUM 1
#define MAX_NUM 1000
#define NUM_GANADORES 100

/**
 * @brief Devuelve un entero pseudoaleatorio contenido en 
 * el rango [a, b] (ambos incluidos)
 * @param a menor número posible que se podría devolver
 * @param b mayor número posible que se podría devolver
 * @return número pseudoaleatorio contenido en [a, b]
 */
int get_random_from_range (int a, int b);

/**
 * @brief Inicializa la lista de números ganadores del concurso por
 * referencia. Esta lista podría contener números repetidos.
 * @param ganadores[NUM_GANADORES] array de int que representa la 
 * lista de mnúmeros ganadores. Debe tener tamaño NUM_GANADORES.
 */
void simula_lista_numeros (int ganadores[NUM_GANADORES]);

/**
 * @brief Determina si num es ganador, es decir, si el valor num 
 * se encuentra en el array ganadores.
 * @param ganadores[NUM_GANADORES] array de int que representa 
 * la lista de mnúmeros ganadores. Debe tener tamaño NUM_GANADORES.
 * @param num valor del que se desea determinar si es ganador o no.
 * @return true si es ganador y false si no es ganador.
 */
bool es_numero_ganador (int ganadores[NUM_GANADORES], int num);

int main() {
	srand(clock());
    int ganadores[NUM_GANADORES] = {0};
    simula_lista_numeros (ganadores);
    int numero;
    
    printf ("Introduzca el número a comprobar: ");
    scanf ("%d", &numero);
    
    if (es_numero_ganador (ganadores, numero)) {
        printf ("El número es ganador\n");
    } else {
        printf ("El número no es ganador\n");
    }

    
	return 0;
}

int get_random_from_range (int a, int b) {
    return rand() % (b - a + 1) + a;
}

void simula_lista_numeros (int ganadores[NUM_GANADORES]) {
    for (int i = 0; i < NUM_GANADORES; ++i) {
        ganadores[i] = get_random_from_range(MIN_NUM, MAX_NUM);
    }
}

bool es_numero_ganador (int ganadores[NUM_GANADORES], int num) {
    for (int i = 0; i < NUM_GANADORES; ++i) {
        if (num == ganadores[i]) {
            return true;
        }
    }
    return false;
}
