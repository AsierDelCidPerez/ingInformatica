/**
 * @file reparto.c
 *
 * @brief programa para simular un reparto de paquetes
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-10-01
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Máxima peso (en gramos) y volumen (en cm³) que puede transportar el camión.
#define MAX_WEIGHT 400000
#define MAX_VOLUME 5000000
// Mínimo y máximo peso de una caja (en gramos)
#define MIN_WEIGTH_BOX 95
#define MAX_WEIGHT_BOX 2500
// Volúmenes (en cm³) en función de los diferentes tamaños de caja
#define VOL_XS_BOX 8000
#define VOL_S_BOX  12000
#define VOL_M_BOX  18000
#define VOL_L_BOX  27000

/**
 * @brief: Obtiene un número aleatorio contenido en [a, b]
 * @param a es el límite inferior del intervalo (incluido).
 * @param b es el límite superior del intervalo (incluido).
 */
int obten_num_aleatorio (int a, int b);

/**
 * @brief: Obtiene el volumen del paquete a partir del tipo
 * @param modelo es el modelo de paquete que se usará
 */
int obten_volumen (int modelo);

int main (void) {
    // Establecemos la semilla de aleatorización
    srand (clock());
    // Declaración de variables para el programa
    int weight = 0, volume = 0, nPaquetes = 0, weight_new_package = 0, volume_new_package = 0, 
        type_package = 0;
    bool isFull = false;
        
    while (!isFull) {
        // Sumamos el peso, ya que no estamos llenos (con ese peso)
        weight += weight_new_package;
        volume += volume_new_package;
        // Elegimos tipo de paquete y su peso (aleatorio)
        type_package = obten_num_aleatorio (0, 4);
        weight_new_package = obten_num_aleatorio (MIN_WEIGTH_BOX, MAX_WEIGHT_BOX);
        // Asignamos el volumen en función del tipo de paquete
        volume_new_package = obten_volumen (type_package);
        
        ++nPaquetes;
        // Solo si el siguiente paquete se puede meter, no estará lleno
        if (weight + weight_new_package > MAX_WEIGHT || volume + volume_new_package > MAX_VOLUME)
            isFull = true;
    }
    
    printf ("Se transportan %d paquetes:\n", nPaquetes);
    printf ("\tMedia de peso -> %.2f gr\n", weight / (float) nPaquetes);
    printf ("\tMedia de volumen -> %.2f cm³", volume / (float) nPaquetes);
    
    return 0;
}

int obten_num_aleatorio(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int obten_volumen (int modelo) {
    switch (modelo) {
    case 0:
        return VOL_XS_BOX;
    case 1:
        return VOL_S_BOX;
    case 2:
        return VOL_M_BOX;
    case 3:
        return VOL_L_BOX;
    }
}