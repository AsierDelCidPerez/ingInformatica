/**
 * @file
 * @brief Librería para acceder a los datos simulados del recorrido de futbolistas en un partido
 * Limitaciones conocidas:
 *  - se consideran partidos exclusivamente de 40 minutos
 *  - los jugadores están en el campo los 40 minutos
 *
 * Author:  Intro_SW
 * Version: 2024
 *
*/
#define MAX_JUGADORES           10
#define NUM_COORDENADAS         2
#define MEDIDAS_POR_MINUTO      20
#define MINUTOS_POR_PARTIDO     40
#define MAX_MEDIDAS             (MINUTOS_POR_PARTIDO*MEDIDAS_POR_MINUTO)
                                ///< 20 veces por minuto, 40 minutos de partido

/** @typedef jugador_t
 *  @brief Tipo de dato que representa un jugador
 */
typedef struct jugador_t {
    int dorsal;                                 ///< Número de la camiseta
    int medidas[MAX_MEDIDAS][NUM_COORDENADAS];  ///< Lista de coordenadas (x e y, en metros)
} jugador_t;


/**
 * @brief Recupera los datos de los jugadores y los almacena en el array pasado como argumento
 * @param jugadores El array donde almacenar los datos de los jugadores
 * @returns el número de jugadores recuperados, 0 en caso de error
 */
int recupera_datos (jugador_t jugadores [MAX_JUGADORES]);
