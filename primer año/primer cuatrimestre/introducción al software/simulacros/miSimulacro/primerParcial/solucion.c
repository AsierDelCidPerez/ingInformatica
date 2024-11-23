#include <stdio.h>
#include "libfutbol.h"

int getPuntuacionJugador(int jugador_id, int team_id) {
    int tournament = 0;
    int sumatorio = 0;

    while(tournament < MAX_ID_TOURNAMENT && get_score_tournament(jugador_id+1, team_id+1, tournament+1) != -1) {
        sumatorio += get_score_tournament(jugador_id+1, team_id+1, tournament+1);
        tournament++;
    }
    return sumatorio;
}

int mejorJugadorPuntuacionEquipo (int team_id) {
    int mejorPuntuacion = getPuntuacionJugador(0, team_id);
    for(int i=1;i<N_PARTICIPANTES;i++){
        int nuevaPuntuacion = getPuntuacionJugador(i, team_id);
        if(mejorPuntuacion < nuevaPuntuacion) {
            mejorPuntuacion = nuevaPuntuacion;
        }
    }
    return mejorPuntuacion;
}

int puntuacionTotalEquipo (int team_id){
    int sumatorio = 0;
    for(int i=0;i<N_PARTICIPANTES;i++) {
        sumatorio += getPuntuacionJugador(i, team_id);
    }
    return sumatorio;
}

int obten_mejor_puntuacion_torneo (int tournament_id) {
    int mayor = get_score_tournament(1,1, tournament_id+1);
    for(int i=0;i<N_EQUIPOS;i++) {
        for(int j=1;j<N_PARTICIPANTES;j++){
            if(get_score_tournament(i+1,j+1, tournament_id+1) > mayor){
                mayor =get_score_tournament(i+1,j+1, tournament_id+1);
            }
        }
    }
    return mayor;
}

float puntuacion_media(){
    int puntuacion_total = 0;
    for(int i=0;i<30;i++){
        for(int j=0;j<50;j++){
            puntuacion_total += getPuntuacionJugador(j, i);
        }
    }
    return puntuacion_total / 1500.0;
}

int main(){
    printf("%d\n", getPuntuacionJugador(11, 26));
    printf("%d\n", mejorJugadorPuntuacionEquipo(20));
    printf("%d\n", puntuacionTotalEquipo(16));
    printf("%.2f\n", puntuacion_media());
    printf("%d\n", obten_mejor_puntuacion_torneo(0));

}