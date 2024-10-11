/**
 * @file
 * @brief Librería para acceder a los datos simulados de los almacenes de la tienda online
 *
 * Author:  Intro_SW
 * Version: 2024
 *
*/

#include "intro.h"

#define NUM_ALMACENES   5

/**
 * @brief Obtiene el núm. de unidades de un producto que están disponibles en un almacén
 * @param ref Referencia del producto a consultar
 * @param almacen_id Identificador del almacen, rango [1 , NUM_ALMACENES]
 * @returns el num de unidades en el almacen, termina el programa en caso de error
 */
int obten_unidades_en_almacen (string ref, int almacen_id);
