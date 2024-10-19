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
        type_package = rand() % 4;
        weight_new_package = rand() % (MAX_WEIGHT_BOX - MIN_WEIGTH_BOX + 1) + MIN_WEIGTH_BOX;
        // Asignamos el volumen en función del tipo de paquete
        switch (type_package) {
        case 0:
            volume_new_package = VOL_XS_BOX;
            break;
        case 1:
            volume_new_package = VOL_S_BOX;
            break;
        case 2:
            volume_new_package = VOL_M_BOX;
            break;
        default:
            volume_new_package = VOL_L_BOX;
        }
        
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
