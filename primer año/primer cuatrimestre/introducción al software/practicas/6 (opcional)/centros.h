/**
 * @file
 * @brief Librería para acceder a los datos simulados de los centros de atención al cliente
 *
 * Author:  Intro_SW
 * Version: 2019
 *
*/

#include "intro.h"

#define NUM_CENTROS         5
#define CENTRO_PRINCIPAL    0

#define INCIDENCIAS     1
#define VENTAS          2
#define INFORMACION     3

/**
 * @brief Obtiene el factor de valoración de la llamada en el centro de atención indicado
 * @param centro_id Identificador del centro (rango 0 a NUM_CENTROS - 1)
 * @param tipo_llamada Identificador del tipo de llamada (INCIDENCIAS, VENTAS o INFORMACION)
 * @returns el factor de valoración de la llamada centro,  termina el programa en caso de error
 */
int obten_factor_centro (int centro_id, int tipo_llamada);
