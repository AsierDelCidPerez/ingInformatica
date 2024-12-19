/**
 * @file
 * @brief Librería para acceder a los datos simulados del mundial de F1
 *
 * Author:  Intro_SW
 * Version: 1.0
 *
*/

#include <stdbool.h>

#define MAX_CARRERAS         6
#define MAX_PILOTOS          8
#define MAX_ESCUDERIAS       4
#define MAX_STRING          20

typedef enum nombre_escuderia {FERRARI, MERCEDES, RED_BULL, MCLAREN} escuderia_t; // Escuderias en la formula 1

// Tipo de dato que representa los datos de interés de un piloto en una carrera
typedef struct piloto_f1 {
    char id[MAX_STRING];         // identificador único del piloto
    escuderia_t escuderia;       // escuderia donde corre
    int posicion;                // posicion en la carrera
    float vuelta_rapida;         // tiempo de su vuelta rapida en la carrera (en segundos)
} piloto_t;

/**
* @brief Recupera los datos del mundial de formula 1 y los almacena en datos_mundial
* @param datos_mundial Array bidimensional donde almacenar las estadisticas de cada piloto para cada
* carrera del mundial. Para cada carrera, se incluyen las estadisticas de todos los pilotos
* @returns true si se han podido recuperar los datos, false en caso de error
*/
bool recupera_datos_mundial (piloto_t datos_mundial[MAX_CARRERAS][MAX_PILOTOS]);
