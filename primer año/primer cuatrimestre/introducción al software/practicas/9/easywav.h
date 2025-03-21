/**
 * @file
 * @brief Funciones de ayuda para gestionar audio con formato wav
 * Limitaciones conocidas:
 *  - la librería solo soporta audio con 2 canales.
 *  - la librería solo soporta audio con muestras de 16 bits.
 *  - la librería solo soporta audio wav con la cabecera creada correctamente.
 *  - la librería solo soporta cabeceras escritas con formato Little Endian
 *    (tal y como recomienda el formato RIFF/Wave)
 *  - la librería solo permite escribir audios con el mismo número de muestras que el audio de
 *    entrada
 *  - puede gestionar como máximo 10 audios
 *  - cada audio está limitado a un número de muestras igual a MAX_SAMPLES
 *
 * Author:  Intro_SW
 * Version: 1.0
 *
*/

#include "intro.h"
/**
 * @name Constantes de la librería
 * Indican el formato y el tamaño del identificador soportados por la librería
 * @{
 */

#define NUM_CHANNELS      2     /**< Máximo número de canales soportados */
#define MAX_SAMPLES  500000     /**< Máximo número de muestras soportado */

/** @} */

/**
 * @brief Lee un audio del disco duro, carga la información del audio (p.ej., la frecuencia de
 *        muestreo o el número de canales) en la librería y almacena las muestras de audio en el
 *        buffer. El audio debe estar en la misma carpeta que el programa que llama a la librería
 * @param filename Nombre del fichero wav con el audio
 * @param buffer Array donde se almacenan las muestras del audio
 * @returns Un número entero que identifica el audio cargado por la librería (rango [0, 9]),
 *          en caso de error el programa termina
 */
int read_audio (const string filename, short buffer [NUM_CHANNELS][MAX_SAMPLES]);

/**
 * @brief Escribe un audio wav en el disco duro con la misma información con la que se cargó en
 *        la librería. En caso de error el programa termina.
 * @param filename Nombre del fichero donde almacenar el audio wav
 * @param audio_id Número entero que identifica el audio cargado por la librería al leerse
 * @param buffer Array con la información del audio a escribir en el fichero
 */
void write_audio (const string filename, int audio_id, short buffer [NUM_CHANNELS][MAX_SAMPLES]);

/**
 * @brief Obtiene el número de muestras por canal que tiene el audio cargado. En caso de error el
 *        programa termina.
 * @param audio_id Número entero que identifica el audio cargado por la librería al leerse
 * @returns El número de muestras del audio original identificado por audio_id,
 *          en caso de error el programa termina
 */
int get_number_of_samples_per_channel (int audio_id);

/**
 * @brief Obtiene la frecuencia de muestreo que tiene el audio cargado. En caso de error el programa
 *        termina.
 * @param audio_id Número entero que identifica el audio cargado por la librería al leerse
 * @returns La frecuencia de muestreo del audio original identificado por audio_id,
 *          en caso de error el programa termina
 */
int get_sample_rate (int audio_id);
