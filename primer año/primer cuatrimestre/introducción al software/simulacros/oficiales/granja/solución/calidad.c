/**
 * @file granjas.c
 *
 * @brief Control de calidad de los huevos para las granjas licenciadas.
 *
 * @author  ASIER DEL CID PÉREZ <adp471@alumnos.unican.es>
 * @version 2024-12-10
 *
 **/

#include <stdio.h>
#include <stdbool.h>
#include "granja.h"

#define N_LIMITES_PESO 3
#define NUM_MESES      12
#define NUM_GRANJAS    825

/**
 * @brief Comprueba si el peso de un huevo se adecúa a su categoría.
 * @param categoria puntero de categoria_t que representa la categoría del hevo
 * @param peso int con el peso del huevo
 * @return true si se adecúa y false si no.
 */
bool is_valid_weight (categoria_t *categoria, int peso);

/**
 * @brief Comprueba si el etiquetado es válido: para ello se debe cumplir, el num_control
 * divide al granja_id, la categoría del huevo se adecúa al peso y la licencia es o bien APROBADA
 * o PENDIENTE.
 * @param etiqueta_huevo puntero de etiquetado_t con la etiqueta a analizar.
 * @return true si la etiqueta es válida y false si no.
 */
bool es_etiquetado_valido (etiquetado_t *etiqueta_huevo);

/**
 * @brief Calcula el porcentaje de etiquetas que son erróneas.
 * @param lista array de tipo etiquetado_t con la lista de controles del mes a analizar.
 * @return real con el porcentaje (formato porcentual).
 */
float porcentaje_etiquetas_erroneos (etiquetado_t lista[NUM_CONTROLES_MES]);

/**
 * @brief Calcula la cantidad de granjas sin controles.
 * @param controles array bidimensional por cada mes y por cada control.
 * @return entero con la cantidad de granjas diferentes no controladas.
 */
int num_granjas_sin_controles (etiquetado_t controles[NUM_MESES][NUM_CONTROLES_MES]);

int main (void) {
    mes_t mes;
    etiquetado_t lista [NUM_CONTROLES_MES];

    printf ("Introduzca el número del mes a estudiar del 1 al 12: ");
    scanf ("%d", &mes);
    mes--;

    if(!obten_datos(mes, lista)) {
        printf ("Ha habido un error al obtener los datos\n");
        return 1;
    }

    float porcentaje = porcentaje_etiquetas_erroneos (lista);

    printf ("Porcentaje de etiquetas erróneas: %.2f%%\n", porcentaje);


    etiquetado_t controles[NUM_MESES][NUM_CONTROLES_MES];

    // Recogemos los datos de tdo el año
    for(mes_t mes = ENERO; mes < NUM_MESES; mes++) {
        obten_datos(mes, controles[mes]);
    }

    printf("Número de granjas sin control %d\n", num_granjas_sin_controles(controles));

    return 0;
}

bool is_valid_weight (categoria_t *categoria, int peso) {
    const int LIMITES_PESO[N_LIMITES_PESO] = {53, 62, 72};

    categoria_t verdadera_categoria = -1;

    // Guardamos la categoría que debería tener el huevo para luego comparar
    if (peso < LIMITES_PESO[0])
        verdadera_categoria = S;
    else if (peso <= LIMITES_PESO[1])
        verdadera_categoria = M;
    else if (peso <= LIMITES_PESO[2])
        verdadera_categoria = L;
    else
        verdadera_categoria = XL;

    return (verdadera_categoria) == (*categoria);

}

bool es_etiquetado_valido (etiquetado_t *etiqueta_huevo) {
    bool valido = true;

    if(obten_licencia_granja (etiqueta_huevo->granja_id) == CADUCADA) {
        valido = false;
    }

    if ((etiqueta_huevo->granja_id % etiqueta_huevo->num_control) != 0) {
        valido = false;
    }

    valido = is_valid_weight (&(etiqueta_huevo->categoria), etiqueta_huevo->peso) ? valido: false;

    return valido;
}

float porcentaje_etiquetas_erroneos (etiquetado_t lista[NUM_CONTROLES_MES]) {
    int num_etiquetas_erroneas = 0;
    for (int i=0; i<NUM_CONTROLES_MES; i++){
        if (!es_etiquetado_valido(&lista[i]))
            num_etiquetas_erroneas++;
    }
    return (((float) num_etiquetas_erroneas) / NUM_CONTROLES_MES) * 100;
}

int num_granjas_sin_controles (etiquetado_t controles[NUM_MESES][NUM_CONTROLES_MES]) {
    bool granjas_controladas [NUM_GRANJAS] = {0};
    for (mes_t mes = ENERO; mes < NUM_MESES; mes++){
        for (int control = 0; control < NUM_CONTROLES_MES; control++) {
            granjas_controladas[--controles[mes][control].granja_id] = true;
        }
    }

    int no_controladas = 0;

    for (int i=0; i < NUM_GRANJAS; i++){
        if (!granjas_controladas[i]) no_controladas++;
    }

    return no_controladas;
}
