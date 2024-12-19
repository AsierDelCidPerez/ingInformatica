/**
 * @file draw_tool.c
 *
 * @brief Graficar la onda de sonido de un audio.
 *
 * @author  ASIER <>
 * @version 2024-11-19
 *
 **/

#include <stdio.h>
#include "easywav.h"
#include "grafica_x_y.h"

/**
 * @brief Función que dado un buffer de muestras te dibuja una gráfica con la onda del archivo
 * de sonido.
 * @param buffer array (unidimensional) con las muestras tomadas de un canal.
 * @param titulo_ventana string con el título de la ventana.
 * @param titulo_eje_x string con la leyenda del eje x.
 * @param titulo_eje_y string con la leyenda del eje y.
 */

void dibuja_grafica (short buffer[MAX_SAMPLES], int num_muestras_canal, string titulo_ventana, 
                     string titulo_eje_x, string titulo_eje_y);

int main (int argv, string argc[]) {
    // Gestión de errores para los argumentos pasados.
    if (argv < 2) {
        printf ("ERROR: filepath of wav is needed.");
        return 1;
    }
    const string FILEPATH = argc[1];
    // Algunas constantes para la interfaz gráfica.
    const string TITLE_VENTANA = "Onda del audio 1";
    const string TITLE_EJE_X = "muestra";
    const string TITLE_EJE_Y = "nivel";
    short buffer[NUM_CHANNELS][MAX_SAMPLES];
    // Leemos el audio y obtenemos su cabecera.
    int audio_id = read_audio (FILEPATH, buffer);
    dibuja_grafica (buffer[0], get_number_of_samples_per_channel (audio_id), TITLE_VENTANA,
                    TITLE_EJE_X, TITLE_EJE_Y);
    return 0;
}

void dibuja_grafica (short buffer[MAX_SAMPLES], int num_muestras_canal, string titulo_ventana, 
                     string titulo_eje_x, string titulo_eje_y) {
    pon_titulos (titulo_ventana, titulo_eje_x, titulo_eje_y);
    for (int muestra = 0; muestra < num_muestras_canal; muestra++) {
        // Por cada muestra se inserta un punto en la gráfica.
        inserta (muestra + 1, (float) buffer[muestra]);
    }
    pinta();
}
