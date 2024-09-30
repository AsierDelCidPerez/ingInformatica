/*
 * @file dados.c
 *
 * @brief Juego de dados (aleatorios) para practicar condicionales.
 *
 * @author  ASIER <Introducción al Software>
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NFACES      6
#define MULTIPLE_OF 3
#define MSG_WIN     "¡Felicidades has ganado :)!"
#define MSG_LOSE    "Creo que has perdido... pero ¡no pasa nada! Puedes volver a intentarlo."

int get_random_from_range (int a, int b) { // [a, b]
    return rand() % (b - a) + a;
}

int main (void) {
    // Inicialización de variables
    
    int dice1, dice2, sum;
    srand (clock()); // Establecemos una seed en función de la hora para una 
    //                  conveniente aleatorización
    
    // Algoritmo del programa
    // Primera parte del juego: si la suma de las caras de los 2 al ser lanzados es múltiplo de
    // MULTIPLE_OF entonces gana:
    
    dice1 = get_random_from_range (1, NFACES);
    dice2 = get_random_from_range (1, NFACES);
    sum = dice1 + dice2;
    printf ("%d + %d = %d\n", dice1, dice2, sum);
    
    if (!(sum % MULTIPLE_OF)) {
        printf ("%s\n", MSG_WIN);
    }
    else {
        // Fase 2 del juego: solo gana si la suma de los dos dados a lanzar es igual a 
        // la suma de los dos anteriores.
        dice1 = get_random_from_range (1, NFACES);
        dice2 = get_random_from_range (1, NFACES);
        int sum2 = dice1 + dice2; // sum2 solo tiene sentido dentro de este ámbito
        printf ("%d + %d = %d\n", dice1, dice2, sum2);
        if (sum == sum2) {
            printf ("%s\n", MSG_WIN);
        }
        else {
            printf ("%s\n", MSG_LOSE);
        }
    }
    
    // Ante la ausencia de excepciones la salida es exitosa.
    return 0;
}

