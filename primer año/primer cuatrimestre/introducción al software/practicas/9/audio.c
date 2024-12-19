/**
 * @file audio.c
 *
 * @brief Programa para aplicar el efecto reverse a un audio.
 *
 * @author  ASIER <adp471@alumnos.unican.es>
 * @version 2024-11-19
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "wav.h"
#include "intro.h"
#define testing 0

/**
 * @brief Revertir las muestras de cada canal de una canción.
 * @param input array bidimensional de tipo short. La primera dimensión se refiere al número
 * de canales y la segunda dimensión se refiere al número de muestreos por canal.
 */

void reverse_audio_samples (short input[NUM_CHANNELS][MAX_SAMPLES],
                            int input_num_samples_per_channel,
                            short output[NUM_CHANNELS][MAX_SAMPLES]);

void show_info (wav_header_t header, int bytes_sample);

void fade_out (wav_header_t header, int first_faded_sample, int last_faded_sample, short input[NUM_CHANNELS][MAX_SAMPLES],
               short output[NUM_CHANNELS][MAX_SAMPLES]);

int main (int argc, string argv[]){
    if(argc < 3) {
        printf("Debe dar al menos dos argumentos\n");
        return 1;
    }
    
    string filepath = argv[1];
    string efecto = argv[2];
    float segundos = 1.5;
    
    if (argc >= 4) {
        segundos = atof(argv[3]);
    }
    
    short buffer [NUM_CHANNELS] [MAX_SAMPLES];
    wav_header_t cabecera = read_audio (filepath, buffer);
    
    int num_muestras = cabecera.data_size / (cabecera.num_channels * sizeof(buffer[0][0]));

    int first_faded_sample = num_muestras - segundos * cabecera.sample_rate;

    short salida[NUM_CHANNELS][MAX_SAMPLES];
    if(strcmp(efecto, "fadeout") == 0) {
        fade_out (cabecera, first_faded_sample, num_muestras, buffer, salida);
    }else if(strcmp(efecto, "reverse") == 0) {
        printf("Invirtiendo audio\n");
        reverse_audio_samples(buffer, num_muestras, salida);
    }else{
        printf("Efecto no disponible.\n");
        return 1;
    }

    show_info (cabecera, sizeof(buffer[0][0]));
    write_audio("./output.wav", cabecera, salida);
}

void reverse_audio_samples (short input[NUM_CHANNELS][MAX_SAMPLES],
                            int input_num_samples_per_channel,
                            short output[NUM_CHANNELS][MAX_SAMPLES]) {
    for (int canal = 0; canal < NUM_CHANNELS; canal++){
        for (int muestra = 0; muestra < input_num_samples_per_channel; muestra++) {
            output[canal][muestra] = input[canal][input_num_samples_per_channel - muestra - 1];
            output[canal][muestra] = input[canal][input_num_samples_per_channel - muestra - 1];
        }
    }
}

void show_info (wav_header_t header, int bytes_sample) {
    printf ("--------- Información del audio ---------\n");
    int num_muestras = header.data_size / (header.num_channels * bytes_sample);
    printf ("Número de muestras totales: %d (%d bits por muestra)\n", num_muestras, (bytes_sample*8));
    printf ("Frecuencia: %d Hz\n", header.sample_rate);
    printf ("Número de canales: %d\n", header.num_channels);
    printf ("Datos: %d bytes\n", header.data_size);
    printf ("Duración del audio (segundos): %.2f\n", (num_muestras * 1.0 / header.sample_rate));
}

void fade_out (wav_header_t header, int first_faded_sample, int last_faded_sample, short input[NUM_CHANNELS][MAX_SAMPLES],
               short output[NUM_CHANNELS][MAX_SAMPLES]) {
    int muestras_a_atenuar = (last_faded_sample - first_faded_sample);
    if (muestras_a_atenuar <= 0) {
        printf("El número total de muestras a las que aplicar el efecto debe ser positivo");
        return;
    }
    int num_muestras = header.data_size / (header.num_channels * sizeof(input[0][0]));
    for (int canal = 0; canal < NUM_CHANNELS; canal++) {
        int primer_indice_relativo = -1;
        for (int muestra = 0; muestra < num_muestras; muestra++) {
            if (first_faded_sample < muestra && muestra < last_faded_sample) {
                // Realizar efecto porque se encuentra en el intervalo
                if (primer_indice_relativo == -1)  {
                    primer_indice_relativo = muestra -1;
                }
                float factor_atenuante = 1 - (muestra * 1.0 - primer_indice_relativo) / muestras_a_atenuar;
                output[canal][muestra] = factor_atenuante * input[canal][muestra];
            }else{
                output[canal][muestra] = input[canal][muestra];
            }
        }
    }
}
