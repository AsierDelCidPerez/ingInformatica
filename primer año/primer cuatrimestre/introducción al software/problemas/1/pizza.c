/*
 * @file pizza.c
 *
 * @brief Calcular precio pizza a partir de precio/cm² y diámetro
 *
 * @author  ASIER <Introducción al Software>
 * @version 1.0
 */

#include <stdio.h>
#include <math.h>
#include <intro.h>

int main (void) {
    // Inicialización de variables
    float price_area, area, price; 
    int diam;
    
    // Input del programa
    printf ("Introduzca el precio/cm² de tu pizza: ");
    price_area = get_user_float();
    printf ("Introduzca el diámetro de tu pizza (cm²): ");
    diam = get_user_int();
    
    // Algoritmo del programa
    area = pow (diam / 2.0, 2) * M_PI;
    price = price_area * area;
    
    // Output del programa
    printf ("El precio de tu pizza es de: %.2f euros.", price);
    
    // Ante la ausencia de excepciones se devuelve una ejecución exitosa.
    return 0;
}

