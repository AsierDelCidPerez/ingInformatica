/**
 * @file robot_cleaner.c
 *
 * @brief programa para calcular precio por limpieza
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-10-01
 *
 **/

#include <stdio.h>
#include <intro.h>

#define SURFACE_TARIFA 50 // Cada cuántos m² se pasa a otra tarifa.
// Todas las tarifas están en €/m²
#define TARIFA_BASE 10
#define TARIFA_1    2 
#define TARIFA_2    1
#define TARIFA_3    .5 // La mínima tarifa, no hay tarifas más baratas.

int main (void) {
    // Input del programa y tratamiento de errores.
    printf ("Introduzca superficie (en m²) a limpiar: ");
    const int surface = get_user_int();
    if (surface < 1 || surface > 350) {
        printf ("Superficie no válida (1<=X<=350)\n");
        return 1;
    }
    
    // Declaración de las variables a utilizar.
    unsigned int util_surface = surface;
    float price = TARIFA_BASE;
    unsigned int n_tarifa = 1; // Solo puede tomar valor 1, 2 o 3
    
    // Algoritmo del programa
    while (util_surface > 0) { // En el peor caso se ejecuta 3 veces -> DRY
        const unsigned int transf = 
            util_surface > SURFACE_TARIFA ? SURFACE_TARIFA : util_surface;
        if (n_tarifa == 3) {
            price += util_surface * TARIFA_3;
            util_surface = 0;
        }
        else if (n_tarifa == 2) {
            price += transf * TARIFA_2;
            util_surface -= transf;
        }
        else {
            price += transf * TARIFA_1;
            util_surface -= transf;
        }
        ++n_tarifa;
    }
    
    // Output del programa
    printf ("El precio es de %.2f euros.", price);
    return 0;
}

