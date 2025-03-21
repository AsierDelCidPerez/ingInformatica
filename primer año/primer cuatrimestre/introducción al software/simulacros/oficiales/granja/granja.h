/**
 * @file
 * @brief Librería para acceder a los datos simulados del ministerio
 *
 * Author:  Intro_SW
 * Version: 1.0
 *
*/
#include <stdbool.h>
#define NUM_CONTROLES_MES    90

/** Tipos de crianza posibles para las gallinas ponedoras */
typedef enum tipo_crianza_t {JAULA, SUELO, CAMPERA, ECOLOGICA} tipo_crianza_t;
/** Categorías posibles para los huevos destinados a la venta */
typedef enum categoria_t {S, M, L, XL} categoria_t;
/** Estados de la licencia de las granjas */
typedef enum licencia_t {APROBADA, PENDIENTE, CADUCADA} licencia_t;
/** Meses del año */
typedef enum mes_t {ENERO, FEBRERO, MARZO, ABRIL, MAYO, JUNIO, JULIO, AGOSTO, 
                    SEPTIEMBRE, OCTUBRE, NOVIEMBRE, DICIEMBRE} mes_t;

/** Estructura de datos que representa el etiquetado de un huevo */
typedef struct etiquetado_t {
    tipo_crianza_t crianza; // Tipo de crianza de la gallina
    int peso; // Peso en gramos
    categoria_t categoria; // Tamaño del huevo
    int granja_id; // Identificador de la granja
    int num_control; // Número de control
} etiquetado_t;

/**
* @brief Obtiene los datos del etiquetado del mes indicado
* @param mes El mes del que se quieren recuperar los datos
* @param datos Array donde almacenar los datos obtenidos. Su tamaño es fijo
*              e igual a NUM_CONTROLES_MES
* @returns true si se han podido recuperar los datos, false en caso contrario
*/
bool obten_datos (mes_t mes, etiquetado_t datos [NUM_CONTROLES_MES]);

/**
* @brief Obtiene el estado de la licencia de la granja indicada
* @param granja_id El identificador de la granja (rango [1, 825)]
* @returns el estado de la licencia de la granja indicada, termina en caso de error
*/
licencia_t obten_licencia_granja (int granja_id);
