/*
 * libfutbol.
 * 
 * Copyright 2024 Asier Del Cid Pérez <adelcidp@kali>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include "futbol.h"

int get_puntuacion_jugador(int jugador_id, int team_id) {
    int sumatorio = 0;
    for(int i=1;i<=MAX_ID_TOURNAMENT;i++){
        sumatorio += get_score_tournament(jugador_id, team_id, i);
    }
    return sumatorio;
}

int mejor_puntuacion_mejor_jugador_del_equipo (int team_id) {
    int mayor = get_puntuacion_jugador (1, team_id);
    for(int i=2;i<=N_PARTICIPANTES;i++){
        if(mayor < get_puntuacion_jugador(i, team_id)){
            mayor = get_puntuacion_jugador(i, team_id);
        }
    }
    return mayor;
}

int total_puntos_obtenidos_por_equipo (int team_id){
    int sumatorio = 0;
    for(int i=1;i<=N_PARTICIPANTES;i++){
        sumatorio += get_puntuacion_jugador(i, team_id);
    }
    return sumatorio;
}

float puntuacion_media () {
    int sumatorio = 0;
    for(int i=1;i<=N_EQUIPOS; i++) {
        for(int j=1; j<= N_PARTICIPANTES; j++) {
            sumatorio += get_puntuacion_jugador (j, i);
        }
    }
    return sumatorio / (N_EQUIPOS*N_PARTICIPANTES*1.0);
}

int mejor_puntuacion_en_torneo(int tourn_id) {
    int mayor = get_score_tournament(1, 1, tourn_id);
    for (int i=1;i<=N_EQUIPOS;i++){
        for(int j=1;j<=N_PARTICIPANTES;j++){
            int nuevo = get_score_tournament(j, i, tourn_id);
            if(nuevo > mayor){
                mayor = nuevo;
            }
        }
    }
    return mayor;
}

int main(int argc, char **argv)
{
	printf("%d\n", get_puntuacion_jugador(12, 27));
    printf("%d\n", mejor_puntuacion_mejor_jugador_del_equipo(21));
    printf("%d\n", total_puntos_obtenidos_por_equipo(17));
    printf("%.2f\n", puntuacion_media());
    printf("%d\n", mejor_puntuacion_en_torneo(9));
	return 0;
}

