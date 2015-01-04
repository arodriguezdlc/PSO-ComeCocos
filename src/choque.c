#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <ncurses.h>

#include "estructuras.h"

#define NO 0
#define SI 1


int choque(MAPA * mapa, MAPAANT * mapaAnt, int i, int j){//funcion para ver si chocan el jugador y el fantasma

int resultado = NO;
j--;
i--;
while(j>=0){
	while (i>=0){
		if(((mapa->jugador[j].x)==(mapa->fantasma[i].x))&&((mapa->jugador[j].y)==(mapa->fantasma[i].y)))
		resultado=SI;
		if(((mapaAnt->jugador[j].x)==(mapa->fantasma[i].x))&&((mapaAnt->jugador[j].y)==(mapa->fantasma[i].y)))
		resultado=SI;
		i--;
		}
	j--;
	}
			mvprintw(mapa->dimensiones.y + 3,0, "posiciones Cnuevo = %d, %d Cant = %d, %d Fnuevo = %d, %d Fant %d, %d resultado %d", mapa->jugador[0].x,mapa->jugador[0].y, mapaAnt->jugador[0].x,mapaAnt->jugador[0].y, mapa->fantasma[0].x,mapa->fantasma[0].y, mapaAnt->fantasma[0].x,mapaAnt->fantasma[0].y, resultado);
refresh();
return resultado;
}

void guardamapa(MAPA * mapa, MAPAANT * mapaAnt){

	int i;
	mapaAnt->numFantasmas = mapa->numFantasmas;
	mapaAnt->numJugadores = mapa->numJugadores;
	for(i = 0; i < mapa->numJugadores; i++) {
		mapaAnt->jugador[i].x = mapa->jugador[i].x;
		mapaAnt->jugador[i].y = mapa->jugador[i].y;
	}
	for(i = 0; i < mapa->numFantasmas; i++) {
		mapaAnt->fantasma[i].x = mapa->fantasma[i].x;
		mapaAnt->fantasma[i].y = mapa->fantasma[i].y;
	}
}
