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
/* Número de mayúsculas antes de los números:
 * - Hay N_LETRAS_OF_REF de letras
 * - Hay LENGTH_OF_REF - N_LETRAS_OF_REF números
 * El formato en todo caso ha de ser AAA...A11...1
 */ 
#define N_LETRAS_OF_REF 2
#define A_MAYUSCULA     'A'
#define Z_MAYUSCULA     'Z'
#define CERO            '0'
#define NUEVE           '9'
// Mensajes para decir si hay stock o no
#define HAY_STOCK    "==> Existe stock suficiente para servir el pedido de forma inmediata"
#define NO_HAY_STOCK "==> Ahora mismo no se dispone de stock suficiente."

/**
 * @brief Mira el stock en todos los almacenes de un producto
 * @param ref referencia del producto a mirar stock
 * @returns int que alude al stock total de un producto
 */
int total_unidades_en_stock (string ref);

/**
 * @brief Revisa el formato de la referencia del producto
 * @param ref referencia del artículo
 * @returns devuelve true si el formato es correcto, si no false.
 */
bool check_format_of_ref (string ref);

/**
 * @brief Revisa el formato del input del usuario
 * @param ammount entero positivo (1-MAX_AMMOUNT) que desea el usuario 
 *        de un producto
 * @param ref referencia de un producto a modo de id.
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
        printf (HAY_STOCK);
    else
        printf (NO_HAY_STOCK);
    
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
    int i = 0;
    if (!(strlen (ref) == LENGTH_OF_REF)) {
        return false;
    }
    // Se miran si los caracteres hasta N_LETRAS_OF_REF son letras mayúsculas.
    for (; i < N_LETRAS_OF_REF; ++i) 
        if (ref[i] < A_MAYUSCULA || ref[i] > Z_MAYUSCULA) 
            return false;
    // Se miran si los caracteres hasta LENGTH_OF_REF (desde N_LETRAS_OF_REF) son números.
    for (; i < LENGTH_OF_REF; ++i) 
        if (ref[i] < CERO || ref[i] > NUEVE)
            return false;
    // En este punto i == LENGTH_OF_REF es true
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
