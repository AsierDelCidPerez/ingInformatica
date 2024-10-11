/**
 * @file tragaperras.c
 *
 * @brief programa de simulación de una máquina tragaperras.
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-10-01
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include "intro.h"
#include <time.h>

#define SIETE       0
#define CEREZA      1
#define CAMPANA     2
#define PREMIO_BASE 5

/**
 * @brief: Devuelve un valor aleatorio x comprendido en [a, b] 
 * @param El parámetro a indica el límite inferior a <= x
 * @param El parámetro b indicia el límite superior b >= x
 * @returns devuelve x (valor aleatorio en [a, b])
 */
int get_num_from_range (int a, int b); // [a, b]

int main (void) {
    // Input del programa
    unsigned int bet, num1, num2, num3, won;
    // Control de errores: mínimo 1€ y máx 5€
    do {
        printf ("Place your bet (€): ");
        bet = get_user_int();
    } while (1 > bet || bet > 5);

    printf ("\n");
    srand (clock());

    won = 0;

    // Cada jugada es una vuelta en el bucle
    for (int round = 0; round < bet; ++round) {
        // Obtenemos una combinación aleatoria
        num1 = get_num_from_range (0, 2);
        num2 = get_num_from_range (0, 2);
        num3 = get_num_from_range (0, 2);

        printf ("Result for the game %d: | %d | %d | %d |\n\n", round + 1, num1, num2, num3);
        // Aplicamos la tabla de premios mediante IFs
        if (num1 == num2 && num2 == num3) 
            won += PREMIO_BASE;
        else if (num1 == SIETE && num2 == CAMPANA && num3 == CEREZA) 
            won += 2 * bet;
        else if (num1 == SIETE && num2 == SIETE) 
            won += 2;
        else if (num1 == SIETE) 
            ++won;
        else if (num2 == SIETE) 
            ++won;
    }

    if (won) 
        printf ("==> You win %d euros!\n", won);
    else 
        printf ("==> You lost!\n");

    return 0;
}

int get_num_from_range (int a, int b) { // [a, b]
    return rand() % (b - a) + a;
}
