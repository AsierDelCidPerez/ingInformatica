
#include <stdbool.h>
#define N_PARTICIPANTES   50
#define N_EQUIPOS         30
#define MAX_ID_TOURNAMENT 20

/**
 * @brief Devuelve la puntuación obtenido por el jugador de un equipo en un torneo. Si el
 * jugador ha sido descalificado en este torneo el valor devuelto será -1. Y los datos 
 * registrados en próximos torneos de este jugador podrían ser erróneos. Devolverá -2 si 
 * alguno de los IDs introducidos no es correcto.
 * @param jugador_id entero con el ID del jugador. El ID es un entero positivo contenido
 * en [1, N_PARTICIPANTES].
 * @param team_id entero con el ID del equipo. El ID del equipo un entero positivo contenido
 * en [1, N_EQUIPOS].
 * @param tournament_id entero con el ID del torneo. El ID del torneo un entero positivo contenido
 * en [1, MAX_ID_TOURNAMENT].
 * @return devuelve un entero con la puntuación del jugador de ese equpo en ese torneo.
 */
int get_score_tournament (int jugador_id, int team_id, int tournament_id);

/**
 * @brief Función que revisa si el número obtenido como flag es correcto o no.
 * @param flag el total de puntos obtenido por el jugador con ID 12 del equipo con ID 27 durante
 * el torneo.
 * @return true si la flag es correcta y false si no es correcta.
 */
bool check_first_flag (int flag);

/**
 * @brief Función que revisa si el número obtenido como flag es correcto o no.
 * @param flag el total de puntos obtenidos por el jugador que más puntos ha obtenido durante todo el torneo
 * del equipo con ID 21.
 * @return true si la flag es correcta y false si no es correcta.
 */
bool check_second_flag (int flag);

/**
 * @brief Función que revisa si el número obtenido como flag es correcto o no.
 * @param flag el total de puntos obtenidos por el equipo con ID 17 en el torneo: se calcula como la suma de la puntos
 * obtenidos por cada integrante del equipo a lo largo del torneo.
 * @return true si la flag es correcta y false si no es correcta.
 */
bool check_third_flag (int flag);

/**
 * @brief Función que revisa si el número obtenido como flag es correcto o no.
 * @param flag float con 2 decimales de precisión. La media aritmética entre las puntuaciones globales 
 * obtenidas a lo largo del concurso por todos los jugadores, de todos los equipos.
 * @return true si la flag es correcta y false si no es correcta.
 */
bool check_fourth_flag (float flag);

/**
 * @brief Función que revisa si el número obtenido como flag es correcto o no.
 * @param flag la mejor puntuación obtenida en el torneo con ID 9
 * @return true si la flag es correcta y false si no es correcta.
 */
bool check_fifth_flag (int flag);

/**
 * @brief Función que revisa si el número obtenido como flag es correcto o no.
 * @param flag la mejor puntuación obtenida en el torneo con ID 9
 * @return true si la flag es correcta y false si no es correcta.
 */
bool check_sixth_flag (int flag);