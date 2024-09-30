/**
 * @file hola_grafico.c
 *
 * @brief Un hola mundo a través de la interfaz gráfica
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-09-24
 *
 **/

#include <stdio.h>
#include "dibujo.h"
#include "intro.h"

int main (void) {
    int width = 500, height = 400;
    int initX = 50, initY = 50, fontSize = 40;
    string title = "Mi hola mundo";
    
    // Creación de la ventana
    crea_ventana (title, width, height);
    
    // Creación del texto
    crea_texto (initX, initY, "Hola mundo", "negro", fontSize);
    
    // Esperamos para que no se cierre la ventana inmediatamente.
    pinta_y_espera();
    
    // Optimización
    destruye_ventana();
    
    return 0;
}
