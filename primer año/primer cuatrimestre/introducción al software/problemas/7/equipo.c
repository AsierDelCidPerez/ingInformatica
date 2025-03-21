/**
 * @file equipo.c
 *
 * @brief 
 *
 * @author  ASIER <adp471@alumnos.unican.es>
 * @version 2024-11-12
 *
 **/

#include <stdio.h>
#include <math.h>
#include "datos.h"

#define DORSAL_BUSCAR 4

/**
 * @brief A partir de un tipo struct jugador_t obtiene la distancia
 * total recorrida por el jugador mediante la fórmula:
 * dist = \sum_{i=0}^{n-1} (\sqrt{(x_{i+1} - x_i)^2 + (y_{i+1} - y_i)^2})
 * Con n el número total de medidas tomadas a lo largo del partido.
 * @param jugador dato de tipo struct jugador_t sobre el que se desea
 * realizar el cálculo.
 * @return real con el total de la distancia recorrida por el jugador.
 */
float distancia_total_recorrida (jugador_t jugador);

/**
 * @brief A partir de un array de tipo struct jugador_t devuelve el
 * índice del jugador que ha recorrido la menor distancia a lo largo
 * del partido. En caso de que varios jugadores hayan recorrida la menor
 * distancia, se devuelve aquel cuyo índice sea menor.
 * @param jugadores array de tipo struct jugador_t.
 * @return entero que representa el índice del jugador que ha recorrido
 * la menor distancia 
 */
int jugador_menos_distancia_recorrida (jugador_t jugadores[MAX_JUGADORES]);

int main (void) {
    jugador_t metricas_jugadores[MAX_JUGADORES];
    if (recupera_datos (metricas_jugadores) == 0) {
        printf ("Ha ocurrido un error al recuperar los datos\n");
        return 1;
    }
    
    // Obtenemos el índice del jugador con dorsal buscado
    
    int index_buscado = -1;
    for (int i = 0; i < MAX_JUGADORES; i++) {
        if (metricas_jugadores[i].dorsal == DORSAL_BUSCAR) {
            index_buscado = i;
            break;
        }
    }
    
    // Podría ser que el dorsal que se busca no se encuentre.
    if (index_buscado != -1) {
        // Si no se encuentra
        printf ("Distancia total recorrida por el dorsal %d: %f\n", DORSAL_BUSCAR,
                distancia_total_recorrida (metricas_jugadores[index_buscado]));
    } 
    else {
        printf ("El dorsal que ha solicitado buscar no existe\n");
    }
    printf ("Dorsal con menor distancia recorrida: %d\n", 
            metricas_jugadores[jugador_menos_distancia_recorrida (metricas_jugadores)].dorsal);
    
    return 0;
}

float distancia_total_recorrida (jugador_t jugador) {
    float distancia = 0;
    // Recorrido lineal del array y aplicamos la fórmula
    for (int muestra = 0; muestra < MAX_MEDIDAS - 1; muestra++) {
        distancia += 
            sqrt (pow (jugador.medidas[muestra + 1][0] - jugador.medidas[muestra][0], 2) + 
                  pow (jugador.medidas[muestra + 1][1] - jugador.medidas[muestra][1], 2));
    }
    return distancia;
}

int jugador_menos_distancia_recorrida (jugador_t jugadores[MAX_JUGADORES]) {
    int menor_distancia_index = 0;
    float menor_distancia_recorrida = distancia_total_recorrida (jugadores[0]);
    // Algoritmo para obtener el mínimo por recorrido lineal.
    for (int jugador = 1; jugador < MAX_JUGADORES; jugador++) {
        float actual_distancia = distancia_total_recorrida (jugadores[jugador]);
        // Si la distancia recorrida es 0 es portero o está en banquillo.
        if (actual_distancia < menor_distancia_recorrida && actual_distancia != 0.0) {
            // Actualizamos el índice y el valor del mínimo.
            menor_distancia_index = jugador;
            menor_distancia_recorrida = actual_distancia;
        }
    }
        
    return menor_distancia_index;
}
