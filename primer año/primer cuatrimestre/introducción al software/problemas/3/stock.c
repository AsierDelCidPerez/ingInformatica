/**
 * @file stock.c
 *
 * @brief programa para la gestión de un almacén
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-10-01
 *
 **/

#include <stdio.h>
#include <intro.h>
#include <string.h>
#include <stdbool.h>
#include "almacen.h"

#define MAX_AMMOUNT   15
#define LENGTH_OF_REF 3
// Mensajes para decir si hay stock o no
#define HAY_STOCK    "==> Existe stock suficiente para servir el pedido de forma inmediata"
#define NO_HAY_STOCK "==> Ahora mismo no se dispone de stock suficiente."

/**
 * @brief Mira el stock en todos los almacenes de un producto
 * @param ref Referencia del producto a mirar stock
 * @returns int que alude al stock total de un producto
 */
int total_unidades_en_stock (string ref);

/**
 * @brief Revisa el formato de la referencia del producto
 * @param ref Referencia del artículo
 * @returns Devuelve true si el formato es correcto, si no false.
 */
bool check_format_of_ref (string ref);

/**
 * @brief Revisa el formato del input del usuario
 * @param ammount entero positivo (1-MAX_AMMOUNT) que desea el usuario 
 *        de un producto
 * @param ref Referencia de un producto a modo de id.
 * @returns true si el input se ajusta al formato.
 */
bool gestion_errores (int ammount, string ref);

int main (void) {
    // INPUT
    printf ("Introduzca la referencia del producto: ");
    string ref = get_user_string();
    printf ("Introduzca el número de productos a comprar (1-%d): ", MAX_AMMOUNT);
    int ammount = get_user_int();
    
    // ERROR-MGMT
    if (!gestion_errores (ammount, ref)) 
        return 1;
    
    // ALG
    int stock = total_unidades_en_stock (ref);
    printf ("Nº de unidades en stock: %d\n", stock);
    
    if (stock >= ammount) 
        printf ("==> Existe stock suficiente para servir el pedido de forma inmediata");
    else
        printf ("==> Ahora mismo no se dispone de stock suficiente.");
    
    return 0;
}

int total_unidades_en_stock (string ref) {
    int contador = 0;
    for (int almacen = 1; almacen <= NUM_ALMACENES; ++almacen) {
        contador += obten_unidades_en_almacen (ref, almacen);
    }
    return contador;
}

bool check_format_of_ref (string ref) {
    if (!(strlen (ref) == LENGTH_OF_REF)) 
        return false;
    
    return true;
}

bool gestion_errores (int ammount, string ref) {
    if (ammount < 1 || ammount > MAX_AMMOUNT) {
        printf ("Valor de cantidad incorrecto\n");
        return false;
    }

    if (!check_format_of_ref (ref)) {
        printf ("Formato de ref incorrecto\n");
        return false;
    }

    return true;
}
