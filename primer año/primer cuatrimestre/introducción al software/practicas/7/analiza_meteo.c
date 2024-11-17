/**
 * @file medir_meteo.c
 *
 * @brief Analizar mediante arrays las condiciones climatológicas.
 *
 * @author  ASIER <adp471@alumnos.unican.es>
 * @version 2024-11-12
 *
 **/

#include <stdio.h>
#include "meteo.h"
#include "grafica_x_y.h"

const string NOMBRE_MES[NUM_MESES] = {"Enero",      "Febrero", "Marzo",     "Abril",
                                      "Mayo",       "Junio",   "Julio",     "Agosto", 
                                      "Septiembre", "Octubre", "Noviembre", "Diciembre"};

/**
 * @brief Imprime por consola una condición climatológica medida a lo largo de un
 * año. Por lo tanto el array recogido debe tener tamaño como tamaño mínimo 
 * NUM_MESES. En caso contrario puede arrojar una excepción por index out of
 * bounds. Algorítmicamente esta función recorre el array suponiendo que tiene
 * NUM_MESES número de elementos.
 * @param condicion_clima array de tipo float que contiene una medición de 
 * la condición climática correspondiente por cada NUM_MESES
 */
void imprime_array_year (float condicion_clima[NUM_MESES]);

/**
 * @brief Devuelve el índice de un elemento de un array de floats cuyo valor es
 * máximo respecto al array de tipo float. En caso de existir varios elementos
 * con valor máximo se devolverá aquel cuyo índice sea menor. El array debe tener
 * al menos tamaño 1. Si el array está vacío se devuelve un error por index out of bounds.
 * @param lista array de tipo float con al menos un elemento.
 * @return int, index del elemento con valor máximo de la lista (y si hubiese más aquel
 * con menor índice).
 */
int obten_indice_valor_maximo (float lista[]);

/**
 * @brief Función que muestra en un gráfico de estilo lineal los valores de un 
 * array (de tamaño NUM_MESES) de tipo float con valores en el eje X contenidos
 * en el rango de enteros [1, NUM_MESES]. También se puede especificar el título
 * del gráfico así como la leyenda que se desea poner en el eje de la Y.
 * @param titulo string que corresponde al titulo de la ventana
 * @param leyendaEjeY string que corresponde a la leyenda/etiqueta que se desea
 * poner en el eje de la Y.
 * @param lista array de tipo float que contiene NUM_MESES número de elementos donde
 * el i-ésimo elemento corresponde al valor de la i-ésima muestra.
 */
void muestra_grafica (string titulo, string leyendaEjeY, float lista[NUM_MESES]);

int main (void) {
    float velocidades[NUM_MESES], direcciones[NUM_MESES], precipitaciones[NUM_MESES],
        temperaturas[NUM_MESES];

    obten_velocidades (velocidades);
    obten_direcciones (direcciones);
    obten_precipitaciones (precipitaciones);
    obten_temperaturas (temperaturas);
    
    // Imprimimos el array de las precipitaciones
    imprime_array_year (precipitaciones);
    printf ("\n");
    
    // Obtenemos y mostramos los datos del mes con más precipitaciones.
    int index_mayor_velocidad = obten_indice_valor_maximo (velocidades);
    printf ("Máxima velocidad del viento=%.1f km/h, en %s, direccion=%.1fº",
            velocidades[index_mayor_velocidad], NOMBRE_MES[index_mayor_velocidad],
            direcciones[index_mayor_velocidad]);
    
    // Mostramos la gráfica de temperaturas.
    muestra_grafica ("Temperatura máxima", "ºC", temperaturas);

    return 0;
}

void imprime_array_year (float condicion_clima[NUM_MESES]) {
    // Recorrido lineal del array.
    printf ("Precipitaciones mensuales extremas, en mm\n");
    for (int mes = 0; mes < NUM_MESES; ++mes) {
        printf ("%-12s%-5.1f mm\n", NOMBRE_MES[mes], condicion_clima[mes]);
    }
}

int obten_indice_valor_maximo (float lista[]) {
    int maxIndice = 0;
    float maxValor = lista[0];
    for (int i = 1; i < NUM_MESES; ++i) {
        if (maxValor < lista[i]) {
            // Si el elemento actual es mayor que el almacenado cambiamos.
            maxValor = lista[i];
            maxIndice = i;
        }
    }
    return maxIndice;
}

void muestra_grafica (string titulo, string leyendaEjeY, float lista[NUM_MESES]) {
    pon_titulos (titulo, "Mes", leyendaEjeY);
    pon_leyenda ("Máxima temperatura por mes");

    pon_estilo (ESTILO_LINEAS);

    for (int mes = 0; mes < NUM_MESES; ++mes) {
        // Añadimos los puntos del gráfico recorriendo el array de temperaturas.
        inserta (mes + 1, lista[mes]);
    }

    pinta();
}
