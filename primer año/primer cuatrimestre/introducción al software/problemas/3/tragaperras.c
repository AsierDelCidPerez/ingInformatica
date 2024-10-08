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

#define siete   0
#define cereza  1
#define campana 2

// Genera un número aleatorio dentro del intervalo
int get_num_from_range (int a, int b) { // [a, b]
    return rand() % (b - a) + a;
}

int main (void) {
    // Input del algoritmo
    printf ("Place your bet: ");
    unsigned short bet = get_user_int();

    if (1 > bet || bet > 5) {
        printf ("Your bet is out of range");
        return EXIT_FAILURE;
    }

    printf ("\n");
    srand (clock());

    // Obtenemos los números aleatoriamente para la máquina
    unsigned short num1 = get_num_from_range (0, 2);
    unsigned short num2 = get_num_from_range (0, 2);
    unsigned short num3 = get_num_from_range (0, 2);

    printf ("Result for the game: | %d | %d | %d |\n", num1, num2, num3);
    if (num1 == num2 && num2 == num3) {
        printf ("==> You win %d euros!\n", bet * 10);
    }
    else {
        printf ("==> You lost!\n");
    }

    return 0;
}
