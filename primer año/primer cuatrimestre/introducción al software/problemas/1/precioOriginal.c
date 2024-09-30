/*
 * @file precioOriginal.c
 *
 * @brief Calcular precio original a partir del rebajado y su descuento.
 *
 * @author  ASIER <Introducción al Software>
 * @version 1.0
 */

#include <stdio.h>
#include <math.h>
#include <intro.h>

int main (void) {
    // Inicialización de las variables a utilizar.
    float precio, descuento;
	
    // Input del programa
    printf ("Introduzca el precio rebajado del producto (en euros): ");
    precio = get_user_double();
    printf ("Introduzca el descuento aplicado (en porcentaje): ");
    descuento = get_user_double();
    
    // Algoritmo del programa
    printf ("El precio original del producto era %.2f euros", precio / (1 - descuento / 100));
	
    // Ante la ausencia de excepciones la salida del programa es correcta
    return 0;
}

