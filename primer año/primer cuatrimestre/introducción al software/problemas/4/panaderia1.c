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
#include <intro.h>
#include <stdbool.h>
#include "pan.h"
 
#define DESCUENTO_DEL_DIA 0.07
#define DIAS_DE_UN_MES    30
// Parámetros definitorios del precio del pan
#define PRECIO_PAN_NORMAL   1.0
#define PRECIO_PAN_ESPECIAL 1.5
#define PRECIO_PAN_MOLDE    2.5

/**
 * @brief Asegura que el formato del tipo de pan es correcto.
 * @param tipo El tipo de pan que solicita el usuario.
 * @return true si es válido y false si no lo es.
 */
bool is_tipo_pan_valido (int tipo);

/**
 * @brief Obtiene l precio de un pedido (sin rebaja si la hubiera).
 * @param tipo El tipo de pan que solicita el usuario.
 * @param cantidad Cantidad de panes de ese tipo para el encargo.
 * @return un real que representa el precio no rebajado del pedido.
 */
float get_precio_sin_rebajar (int tipo, int cantidad);

/**
 * @brief Obtiene el precio de un pedido rebajado (si lo hubiera)
 * @param tipo El tipo de pan que solicita el usuario.
 * @param cantidad Cantidad de panes de ese tipo para el encargo.
 * @return un real que representa el precio rebajado (si aplica) del pedido.
 */
float get_precio_pedido (int tipo, int cantidad);

int main (void) {
    // Declaración de variables.
    int tipo, cantidad;
    float precio_pedido;
    // Input del programa
    printf ("Introduzca el tipo de pan que desea (1-3): ");
    tipo = get_user_int();
    printf ("Introduzca la cantidad de unidades que precisa: ");
    cantidad = get_user_int();
    
    // Gestión de errores del input
    if (!is_tipo_pan_valido (tipo)) {
        return 1;
    }
    
    precio_pedido = get_precio_pedido (tipo, cantidad);
    
    // Output del programa
    printf ("El precio final de tu pedido es: %.2f €.\n", precio_pedido);
}

bool is_tipo_pan_valido (int tipo) {
    // Nos aseguramos de que todos los tipos de pan están entre el tipo
    // de pan normal ... pan de molde.
    if (tipo < PAN_NORMAL || tipo > PAN_MOLDE) {
        printf ("[-] Error por tipo de pan incorrecto.\n");
        return false;
    }
    return true;
}

float get_precio_sin_rebajar (int tipo, int cantidad) {
    switch (tipo) {
        case PAN_NORMAL:
            return PRECIO_PAN_NORMAL;
        case PAN_ESPECIAL:
            return PRECIO_PAN_ESPECIAL;
        case PAN_MOLDE:
            return PRECIO_PAN_MOLDE;
    }
    return -1.0;
}

float get_precio_pedido (int tipo, int cantidad) {
    // Trabajamos con el coeficiente de descuento para luego multiplicarlo.
    const float COEF_REBAJA = 1 - DESCUENTO_DEL_DIA;
    // Obtenemos el pan que está de oferta.
    int tipo_pan_rebajado = obten_pan_oferta();
    float precio_compra = 0;
    
    precio_compra += get_precio_sin_rebajar (tipo, cantidad) * cantidad;
    
    if (tipo_pan_rebajado == tipo) {
        precio_compra *= COEF_REBAJA;
    }
    
    return precio_compra;
}
