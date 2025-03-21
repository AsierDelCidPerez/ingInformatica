/**
 * @file notas.c
 *
 * @brief Programa para gestionar los premios extraordinarios de 
 * bachillerato.
 *
 * @author  ASIER DEL CID PÉREZ <adp471@alumnos.unican.es>
 * @version 2024-11-19
 *
 **/

<<<<<<< HEAD
=======

>>>>>>> 6f93167f37978951134311528067853b691e0721
#include <stdio.h>
#include <string.h>
#include "educacion.h"

#define MIN_NOTA_PREMIO 70

<<<<<<< HEAD
typedef enum { false, true } bool;

/**
 * @brief Calcula el número de alumnos que comparten género y centro pasados
 * como parámetros, dentro de una lista de estudiantes.
 * @param lista array de tipo alumno_t de estudiantes donde buscar las coincidencias.
 * Su tamaño máximo ha de ser el indicado por MAX_ALUMNOS (librería educacion.h).
 * @param codigo_centro array de tipo char que contiene el código del centro. 
 * Debe tener longitud máxima MAX_STRING (indicada en la librería educacion.h).
 * @param genero dato de tipo genero_t que indica el género del alumno.
 * @return entero (int) siempre mayor o igual que cero con el número de
 * coincidencias.
 */
int numero_alumnos_de_genero_en_centro (alumno_t lista[MAX_ALUMNOS], 
                                        char codigo_centro[MAX_STRING], genero_t genero);

/**
 * @brief Indica si un alumno pasado como referencia tiene derecho a la
 * mención especial cuando todas sus notas son iguales o superiores a 
 * MIN_NOTA_PREMIO.
 * @param alumno referencia a dato de tipo alumno_t con el alumno a analizar.
 * @return bool que tomará valor true (1) si tiene derecho y false (0) si no
 * tiene derecho a la mención especial.
 */
bool consigue_mencion_especial (alumno_t *alumno);

int main (int argc, char **argv) {
    alumno_t lista_alumnos[MAX_ALUMNOS];
    
    // Si el valor devuelto por la función es -1 error
    if (obten_datos_alumnos (lista_alumnos) == -1) {
        printf ("Error al cargar la información de los estudiantes.\n");
=======
typedef enum {false, true} bool;

int numero_alumnos_de_genero_en_centro (alumno_t lista[MAX_ALUMNOS], char codigo_centro[MAX_STRING],
                                        genero_t genero);

bool consigue_mencion_especial (alumno_t* alumno);

int main(int argc, char **argv)
{
	alumno_t lista_alumnos[MAX_ALUMNOS];
    
    if(obten_datos_alumnos(lista_alumnos) == -1) {
        printf("Error al cargar la información de los estudiantes.\n");
>>>>>>> 6f93167f37978951134311528067853b691e0721
        return 1;
    }
    
    int id_alumno;
    printf ("Introduzca el id del alumno: ");
    scanf ("%d", &id_alumno);
    
<<<<<<< HEAD
    // El id debe encontrarse en el rango [0, MAX_ALUMNOS)
    if (id_alumno < 0 || id_alumno >= MAX_ALUMNOS) {
        printf ("El índice no se encuentra dentro del rango [0, %d] permitido", MAX_ALUMNOS - 1);
    }
    
    alumno_t *alumno = &lista_alumnos[id_alumno];
    
    // Buscamos los alumnos que comparten centro y género con el alumno cuyo id nos
    // es provisto.
    int alumnos_comparten = 
        numero_alumnos_de_genero_en_centro (lista_alumnos, alumno->codigo_centro, 
                                            alumno->genero);
    
    // pasamos la información del enum género a string legible al usuario.
    char *genre = alumno->genero == HOMBRE ? "HOMBRE" : "MUJER";
    
    printf ("El número de alumnos %s en el centro educativo %s es de %d.\n", genre, 
            alumno->codigo_centro, alumnos_comparten);
    
    // Pasamos la información del bool a info legible para el usuario
    char *mencion = consigue_mencion_especial (alumno) ? "SÍ" : "NO";
    
    printf ("Mención especial para el alumno con id = %d: %s", id_alumno, mencion);
    
    return 0;
}

int numero_alumnos_de_genero_en_centro (alumno_t lista[MAX_ALUMNOS], 
                                        char codigo_centro[MAX_STRING], genero_t genero) {
    int alumnos = 0;
    // Se recorren todos los alumnos y solo nos quedamos con aquellos que coinciden con 
    // el género y código de centro que buscamos.
    for (int i = 0; i < MAX_ALUMNOS; i++) {
        if (lista[i].genero == genero && strcmp (lista[i].codigo_centro, codigo_centro) == 0) {
=======
    if (id_alumno < 0 || id_alumno >= MAX_ALUMNOS) {
        printf ("El índice no se encuentra dentro del rango [0, %d] permitido", MAX_ALUMNOS-1);
    }
    
    alumno_t* alumno = &lista_alumnos[id_alumno];
    
    int alumnos_comparten = numero_alumnos_de_genero_en_centro (lista_alumnos, alumno->codigo_centro, alumno->genero);
    
    char* genre = alumno->genero == HOMBRE ? "HOMBRE" : "MUJER";
    
    printf ("El número de alumnos %s en el centro educativo %s es de %d.\n", genre, alumno->codigo_centro, alumnos_comparten);
    
    char* mencion = consigue_mencion_especial (alumno) ? "SÍ" : "NO";
    
    printf ("Mención especial para el alumno con id = %d: %s", id_alumno, mencion);
    
	return 0;
}

int numero_alumnos_de_genero_en_centro (alumno_t lista[MAX_ALUMNOS], char codigo_centro[MAX_STRING],
                                        genero_t genero) {
    int alumnos = 0;
    for (int i=0; i < MAX_ALUMNOS; i++) {
        if (lista[i].genero == genero && strcmp(lista[i].codigo_centro, codigo_centro) == 0) {
>>>>>>> 6f93167f37978951134311528067853b691e0721
            alumnos++;
        }
    }
    return alumnos;
}

<<<<<<< HEAD
bool consigue_mencion_especial (alumno_t *alumno) {
    // Se miran todas sus notas en todas sus evaluaciones y si alguna es
    // inferior a MIN_NOTA_PREMIO no se le concede, en caso contrario sí.
    for (int ev = 0; ev < NUM_EVALUACIONES; ev++) {
=======
bool consigue_mencion_especial (alumno_t* alumno) {
    for (int ev=0; ev < NUM_EVALUACIONES; ev++){
>>>>>>> 6f93167f37978951134311528067853b691e0721
        for (int area = 0; area < NUM_AREAS; area++) {
            if (alumno->notas[ev][area] < MIN_NOTA_PREMIO) {
                return false;
            }
        }
    }
    return true;
}
