#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <ncurses.h>

#include "estructuras.h"
#include "semaforos.h"

#define TRUE 1
#define FALSE 0

int creaSemaforos(MAPA * mapa) {

	int i;
	int error = FALSE;
	//char nombreSemaforo[] = "semComeCocos-PSO-no.00"
	//nombreSemaforo[21] = '0';

	if(NULL == (mapa->semaforo.jugador = calloc(mapa->numJugadores, sizeof(sem_t)))) {		
		printf("Error de memoria (semaforos - jugadores)\n");
		error = TRUE;
	}
	if(NULL == (mapa->semaforo.fantasma = calloc(mapa->numFantasmas, sizeof(sem_t)))) {
		printf("Error de memoria (semaforos - fantasmas)\n");
		error = TRUE;
	}
	for(i = 0; (error == FALSE) && (i < mapa->numJugadores); i++) {
		if(0 != sem_init(&mapa->semaforo.jugador[i], 0, 0))
			printf("Error en semaforo.jugador[%d]\n", i);
			error = TRUE;
	}
	for(i = 0; (error == FALSE) && (i < mapa->numFantasmas); i++) {
		if(0 != sem_init(&mapa->semaforo.fantasma[i], 0, 0))
			printf("Error en semaforo.fantasma[%d]\n", i);
			error = TRUE;
	}	
	return error;
}

void eliminaSemaforos(MAPA * mapa) {
	int i;
	for(i = 0; i < mapa->numJugadores; i++) {
		sem_destroy(&mapa->semaforo.jugador[i]);
	}	
	for(i = 0; i < mapa->numFantasmas; i++) {
		sem_destroy(&mapa->semaforo.fantasma[i]);
	}
	if(NULL != mapa->semaforo.jugador) {
		free(mapa->semaforo.jugador);
		mapa->semaforo.jugador = NULL;
	}
	if(NULL != mapa->semaforo.fantasma) {
		free(mapa->semaforo.fantasma);
		mapa->semaforo.fantasma = NULL;
	}
}

void subirSemaforos(MAPA * mapa) {
	int i;
	for(i = 0; i < mapa->numJugadores; i++) {
		sem_post(&mapa->semaforo.jugador[i]);
	} 
	for(i = 0; i < mapa->numFantasmas; i++) {
		sem_post(&mapa->semaforo.fantasma[i]);
	}
}
