/**
 * @file
 * @brief Funciones de ayuda para gestionar audio con formato wav
 * Limitaciones conocidas:
 *  - la librería solo soporta audio con 2 canales.
 *  - la librería solo soporta audio con muestras de 16 bits.
 *  - la librería solo soporta audio wav con la cabecera creada correctamente.
 *  - la librería solo soporta cabeceras escritas con formato Little Endian
 *    (tal y como recomienda el formato RIFF/Wave)
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


#define NUM_CHANNELS      2     /**< Número de canales soportados */
#define MAX_SAMPLES  500000     /**< Máximo número de muestras soportado */

/** @} */

/**
 * @brief Cabecera para ficheros de audio wav
 */
typedef struct wav_header {
    char riff_id[4];                   /**< Identificador del contenedor de almacenamiento de datos */
    int overall_size;                  /**< Longitud del fichero (bytes) */
    char wave_id[4];                   /**< Identificador del tipo de fichero */
    char fmt_id_marker[4];             /**< Marcador del comienzo de datos de formato */
    int length_of_fmt;                 /**< Longitud de los datos de formato (bytes) */
    short format_type;                 /**< Formato de audio (1-PCM, 3-IEEE float, 6-8bit A law, 7-8bit mu law) */
    short num_channels;                /**< Canales de audio (1-Mono, 2-Estereo) */
    int sample_rate;                   /**< Frecuencia o muestras por segundo (Hz) */
    int byte_rate;                     /**< sample_rate * num_channels * bits_per_sample/8 */
    short block_align;                 /**< num_channels * bits_per_sample/8 */
    short bits_per_sample;             /**< Número de bits por muestra (8, 16, 32) */
    char data_id_marker [4];           /**< Marcador del comienzo de datos */
    int data_size;                     /**< Longitud de los datos (bytes) */
} wav_header_t;


/**
 * @brief Lee un audio del disco duro y almacena la información
 * en el buffer
 * @param filename Nombre del fichero wav con el audio
 * @param buffer Array donde se almacena la información del audio
 * @returns Una estructura con la cabecera del audio wav,
 *          en caso de error el programa termina
 */
wav_header_t read_audio (const string filename, short buffer [NUM_CHANNELS][MAX_SAMPLES]);


/**
 * @brief Escribe un audio wav en el disco duro. En caso de error el programa termina.
 * @param filename Nombre del fichero donde almacenar el audio wav
 * @param header Cabecera del audio wav
 * @param buffer Array con la información del audio
 */
void write_audio (const string filename, wav_header_t header, short buffer [NUM_CHANNELS][MAX_SAMPLES]);

