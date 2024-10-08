/**
 * @file tragaperras.c
 *
 * @brief programa de simulación de una máquina tragaperras con un modelado de distribución normal al conseguir 3 sietes.
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-10-01
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include "intro.h"
#include <math.h>
#include <time.h>

#define siete      0
#define cereza     1
#define campana    2
#define base_price 10

int get_num_from_range (int a, int b) { // [a, b]
    return rand() % (b - a) + a;
}

int get_factor_aleatorio() {
    // Obtiene un factor aleatorio mediante el método de Box-Muller
    float num1 = rand() / (float) RAND_MAX, num2 = rand() / (float) RAND_MAX;
    // Fórmula para la obtención del factor
    float factor_aleatorio = sqrt (-2 * log (num1)) * cos (2 * M_PI * num2); 
    return factor_aleatorio + 4;
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
    // Establecemos la semilla para los nºs aleatorios.
    srand (clock());

    unsigned short num1 = get_num_from_range (0, 2);
    unsigned short num2 = get_num_from_range (0, 2);
    unsigned short num3 = get_num_from_range (0, 2);

    printf ("Result for the game: | %d | %d | %d |\n", num1, num2, num3);
    if (num1 == num2 && num2 == num3) {
        if (num1 == siete) {
            int factor = get_factor_aleatorio();
            int premio_especial = bet * base_price * factor;
            printf ("==> You win %d euros!\n", premio_especial);
            return 0;
        }
        printf ("==> You win %d euros!\n", bet * base_price);
    }
    else {
        printf ("==> You lost!\n");
    }

    return 0;
}
