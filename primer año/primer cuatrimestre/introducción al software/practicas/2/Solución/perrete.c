/**
 * @file perrete.c
 *
 * @brief Un perrete dibujado con la librería de dibujo
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-09-24
 *
 **/

#include <stdio.h>
#include "dibujo.h"
#include "intro.h"

void mover(){

}

int main (void) {
    // Creación de la ventana
    crea_ventana ("Mi ventana", 400, 400);

    // Creación del tronco (cuerpo y cola)
    crea_linea (20, 50, 50, 50, "negro");
    crea_rectangulo (50, 50, 150, 100, "naranja");

    // Crear las patas
    crea_rectangulo (50, 100, 65, 120, "negro");
    crea_rectangulo (135, 100, 150, 120, "negro");

    // Creación de la cabeza
    crea_rectangulo (130, 10, 170, 50, "marron");
    crea_rectangulo (170, 30, 180, 50, "negro");
    crea_circulo(160, 25, 5, "negro");

    pinta_y_espera ();




    destruye_ventana();
    return 0;
}
