/**
 * @file perrete_desp.c
 *
 * @brief Un perrete que se desplaza en función de las coordenadas iniciales
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-09-24
 *
 **/

#include <stdio.h>
#include "dibujo.h"
#include "intro.h"

int main (void) {

    int coordX = 150;
    int coordY = 150;

    // Creación de la ventana
    crea_ventana ("Mi ventana", 400, 400);

    // Creación del tronco (cuerpo y cola)
    crea_linea (coordX, coordY, coordX + 30, coordY, "negro");
    crea_rectangulo (coordX + 30, coordY, coordX + 130, coordY + 50, "naranja");

    // Crear las patas
    crea_rectangulo (coordX + 30, coordY + 50, coordX + 45, coordY + 70, "negro");
    crea_rectangulo (coordX + 115, coordY + 50, coordX + 130, coordY + 70, "negro");

    // Creación de la cabeza
    crea_rectangulo (coordX + 110, coordY - 40, coordX + 150, coordY, "marron");
    crea_rectangulo (coordX + 150, coordY - 20, coordX + 160, coordY, "negro");
    crea_circulo (coordX + 140, coordY - 25, 5, "negro");

    pinta_y_espera();

    destruye_ventana();
    return 0;
}
