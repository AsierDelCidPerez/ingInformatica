/**
 * @file roma.c
 *
 * @brief Programa convertidor de número romano a natural.
 *
 * @author  ASIER <Introducción al Software>
 * @version 2024-10-01
 *
 **/


#include <stdio.h>
#include <string.h>

#define N_CARACTERES_ROMANOS    7
#define MAX_CARACTERES          6

/**
 * @brief Devuelve el valor decimal de un caráctrer codificado en 
 * sistema romano. Si no se contempla el carácter dentro del sistema
 * romano devuelve -1.
 * @param letra char a obtener su valor numérico.
 * @return entero que refleja el valor decimal del carácter romano o 
 * -1 si no existe ese carácter en el sistema romano. Se asegura que
 * devuelve un entero positivo para todo caso que no sea error.
 */
int valor_letra_romana (char letra);

int main(int argc, char **argv)
{
	char numero[6];
    printf ("Escriba el número romano: ");
    scanf("%s", numero);
    
    int acumulado = 0;
    int index = 0;

    int valor_actual = valor_letra_romana (numero[index]);
    while (valor_actual != -1 && index < MAX_CARACTERES) {
        int next = -1;

        if (index + 1 < MAX_CARACTERES) {
            next = valor_letra_romana (numero[index+1]);
        }
        if (valor_actual < next) {
            acumulado += next - valor_actual;
            index += 2;
        } else {
            acumulado += valor_actual;
            ++index;
        }
        valor_actual = valor_letra_romana (numero[index]);
    }
    printf ("Valor en decimal del número romano: %d", acumulado);
	return 0;
}

int valor_letra_romana (char letra) {
    const char letras [N_CARACTERES_ROMANOS+1] = "IVXLCDM"; // Espacio para \0
    const int valores [N_CARACTERES_ROMANOS] = {1, 5, 10, 50, 100, 500, 1000};
    
    // Hacemos una búsqueda lineal para poder hacer un maping entre
    // la clave (nº romano) y valor (valor decimal de la letra).
    for (int i = 0; i < N_CARACTERES_ROMANOS; ++i) {
        if (letras[i] == letra) {
            return valores[i];
        }
    }
    return -1;
}
