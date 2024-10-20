/**
 * @file
 * @brief Librería para acceder a los datos simulados de la panadería
 *
 * Author:  Intro_SW
 * Version: 2024
 *
 */

#define PAN_NORMAL   1
#define PAN_ESPECIAL 2
#define PAN_MOLDE    3

/**
 * @brief Obtiene el tipo de pan que está en oferta en el día
 * @returns el identificador del pan en oferta  (PAN_NORMAL, PAN_ESPECIAL o PAN_MOLDE)
 */
int obten_pan_oferta (void);

/**
 * @brief Obtiene las unidades vendidas del pan solicitado en el día indicado
 * @param dia el número de día del mes. Valores posibles: 1 a 30
 * @param tipo_pan el tipo de pan solicitado.
 *        Valores posibles: PAN_NORMAL, PAN_ESPECIAL, PAN_MOLDE
 * @returns el número de unidades vendidas del tipo solicitado en el día indicado,
 *          termina en caso de error
 */
int obten_unidades_vendidas (int dia, int tipo_pan);
