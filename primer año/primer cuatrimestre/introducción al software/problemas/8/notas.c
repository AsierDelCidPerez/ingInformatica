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


#include <stdio.h>
#include <string.h>
#include "educacion.h"

#define MIN_NOTA_PREMIO 70

typedef enum {false, true} bool;

int numero_alumnos_de_genero_en_centro (alumno_t lista[MAX_ALUMNOS], char codigo_centro[MAX_STRING],
                                        genero_t genero);

bool consigue_mencion_especial (alumno_t* alumno);

int main(int argc, char **argv)
{
	alumno_t lista_alumnos[MAX_ALUMNOS];
    
    if(obten_datos_alumnos(lista_alumnos) == -1) {
        printf("Error al cargar la información de los estudiantes.\n");
        return 1;
    }
    
    int id_alumno;
    printf ("Introduzca el id del alumno: ");
    scanf ("%d", &id_alumno);
    
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
            alumnos++;
        }
    }
    return alumnos;
}

bool consigue_mencion_especial (alumno_t* alumno) {
    for (int ev=0; ev < NUM_EVALUACIONES; ev++){
        for (int area = 0; area < NUM_AREAS; area++) {
            if (alumno->notas[ev][area] < MIN_NOTA_PREMIO) {
                return false;
            }
        }
    }
    return true;
}
