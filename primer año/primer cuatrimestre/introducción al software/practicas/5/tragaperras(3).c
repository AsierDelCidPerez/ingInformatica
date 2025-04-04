/**
 * @file tragaperras.c
 *
 * @brief programa de simulación de una máquina tragaperras.
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-10-01
 *
 **/

#include "intro.h"
#include "maquina.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CEREZA      0
#define CAMPANA     1
#define SIETE       2
#define PREMIO_BASE 5

/**
 * @brief Devuelve un valor aleatorio x comprendido en [a, b]
 * @param a El parámetro a indica el límite inferior a <= x
 * @param b El parámetro b indicia el límite superior b >= x
 * @returns devuelve x (valor aleatorio en [a, b])
 */

int get_num_from_range (int a, int b); // [a, b]

/**
 * @brief Devuelve el preio del usuario dada la combinación y su apuesta
 * @param symbol_reel1 ódigo numérico del símbolo obtenido en la columna 1 (rango [0,2])
 * @param symbol_reel2 código numérico del símbolo obtenido en la columna 2 (rango [0, 2])
 * @param symbol_reel3 código numérico del símbolo obtenido en la columna 3 (rango [0, 2])
 * @param bet apuesta del cliente (en €); que pague.
 * @returns Premio en euros de la combinación y la apuesta del usuario.
 */
int get_prize (int symbol_reel1, int symbol_reel2, int symbol_reel3, int bet);

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

    // Nos aseguramos de que se inicia bien la máquina.
    if (!start_machine()) 
        return 1;

    // Cada jugada es una vuelta en el bucle
    for (int round = 0; round < bet; ++round) {
        // Obtenemos una combinación aleatoria
        num1 = get_num_from_range (0, 2);
        num2 = get_num_from_range (0, 2);
        num3 = get_num_from_range (0, 2);

        move_reels (num1, num2, num3);

        printf ("Result for the game %d: | %d | %d | %d |\n\n", round + 1, num1, num2, num3);
        // Aplicamos la tabla de premios mediante IFs
        won += get_prize (num1, num2, num3, bet);
    }

    if (won)
        printf ("==> You win %d euros!\n", won);
    else
        printf ("==> You lost!\n");

    stop_machine();
    return 0;
}

int get_num_from_range (int a, int b) { // [a, b]
    return rand() % (b - a) + a;
}

int get_prize (int symbol_reel1, int symbol_reel2, int symbol_reel3, int bet) {
    if (symbol_reel1 == symbol_reel2 && symbol_reel2 == symbol_reel3)
        return PREMIO_BASE;
    else if (symbol_reel1 == SIETE && symbol_reel2 == CAMPANA && symbol_reel3 == CEREZA)
        return 2 * bet;
    else if (symbol_reel1 == SIETE && symbol_reel2 == SIETE)
        return 2;
    else if (symbol_reel1 == SIETE)
        return 1;
    else if (symbol_reel2 == SIETE)
        return 1;
    return 0;
}
