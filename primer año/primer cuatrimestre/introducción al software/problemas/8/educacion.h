/**
 * @file
 * @brief Librería para acceder a los datos simulados del premio de educación
 *
 * Author:  Intro_SW
 * Version: 1.0
 *
*/
#define MAX_ALUMNOS       500
#define MAX_STRING          6
#define NUM_AREAS           4
#define NUM_EVALUACIONES    2

typedef enum evaluacion_t {BACHILLERATO, EXAMEN} evaluacion_t;

typedef enum area_t {CIENCIAS, CIENCIAS_SOCIALES, LETRAS, IDIOMAS} area_t;

typedef enum genero_t {HOMBRE, MUJER} genero_t;

typedef struct alumno_t {
    char codigo_centro [MAX_STRING];
    genero_t genero;
    // Los indices del array siguen el orden de los enumerados correspondientes
    int notas[NUM_EVALUACIONES][NUM_AREAS]; // 0 - 100
} alumno_t;

/**
* @brief Obtiene los datos de los alumnos presentados al premio. Como máximo
* se pueden presentar MAX_ALUMNOS
* @param lista Array donde almacenar los datos de los alumnos. Como máximo, se almacenan MAX_ALUMNOS
* @returns el número de alumnos presentados, -1 en caso de error
*/
int obten_datos_alumnos (alumno_t lista[MAX_ALUMNOS]);
