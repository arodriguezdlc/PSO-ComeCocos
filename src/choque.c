#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#include "estructuras.h"

#define NO 0
#define SI 1


int choque(MAPA * mapa, MAPAANT * mapaAnt, int i, int j){//funcion para ver si chocan el jugador y el fantasma

int resultado = NO;
while(j>0){
	while (i>0){
		if(((mapa->jugador[j].x)==(mapa->fantasma[i].x))&&((mapa->jugador[j].y)==(mapa->fantasma[i].y)))
		resultado=SI;
		if(((mapaAnt->jugador[j].x)==(mapa->fantasma[i].x))&&((mapaAnt->jugador[j].y)==(mapa->fantasma[i].y)))
		resultado=SI;
		i--;
		}
	j--;
	}

return resultado;
}

void guardamapa(MAPA * mapa, MAPAANT * mapaAnt, int i, int j){





}
