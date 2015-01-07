#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <ncurses.h>
#include <fcntl.h>

#include "estructuras.h"
#include "semaforos.h"

#define TRUE 1
#define FALSE 0

int creaSemaforos(MAPA * mapa) {

	int i;
	int error = FALSE;
	char nombreSemaforoJug[] = "ComeCocosJug-0";
	char nombreSemaforoFant[] = "ComeCocosFant-0";

	eliminaSemaforos(mapa, TRUE);

	for(i = 0; i < mapa->numJugadores; i++) {
		if(NULL == (mapa->semaforo.jugador = calloc(mapa->numJugadores, sizeof(sem_t *)))) {
			printf("Error de memoria (semaforo - jugador)\n");
			error = TRUE;
		}			
	}
	for(i = 0; i < mapa->numFantasmas; i++) {
		if(NULL == (mapa->semaforo.fantasma = calloc(mapa->numFantasmas, sizeof(sem_t *)))) {
			printf("Error de memoria (semaforo - fantasma)\n");
			error = TRUE;
		}			
	}

	for(i = 0; (error == FALSE) && (i < mapa->numJugadores); i++) {		
		if(SEM_FAILED == (mapa->semaforo.jugador[i] = sem_open(nombreSemaforoJug, O_CREAT, 0700, 0))) { 
			printf("Error en semaforo.jugador[%d]\n", i);
			error = TRUE;
		}
		nombreSemaforoJug[13]++;
	}
	for(i = 0; (error == FALSE) && (i < mapa->numFantasmas); i++) {
		if(SEM_FAILED == (mapa->semaforo.fantasma[i] = sem_open(nombreSemaforoFant, O_CREAT, 0700, 0))) {
			printf("Error en semaforo.fantasma[%d]\n", i);
			error = TRUE;
		}
		nombreSemaforoFant[14]++;
	}	
	return error;
}

void eliminaSemaforos(MAPA * mapa, int primeraVez) {
	int i;
	char nombreSemaforoJug[] = "ComeCocosJug-0";
	char nombreSemaforoFant[] = "ComeCocosFant-0";
	for(i = 0; i < mapa->numJugadores; i++) {
		if(primeraVez == FALSE) {
			sem_close(mapa->semaforo.jugador[i]);
		}
		sem_unlink(nombreSemaforoJug);
		nombreSemaforoJug[13]++;
	}	
	for(i = 0; i < mapa->numFantasmas; i++) {
		if(primeraVez == FALSE) {
			sem_close(mapa->semaforo.fantasma[i]);
		}
		sem_unlink(nombreSemaforoFant);
		nombreSemaforoFant[14]++;
	}
	for(i = 0; i < mapa->numJugadores; i++) {
		if(NULL != mapa->semaforo.jugador) {
			free(mapa->semaforo.jugador);
			mapa->semaforo.jugador = NULL;
		}
	}
	for(i = 0; i < mapa->numFantasmas; i++) {
		if(NULL != mapa->semaforo.fantasma) {
			free(mapa->semaforo.fantasma);
			mapa->semaforo.fantasma = NULL;
		}
	}
}

void subirSemaforos(MAPA * mapa) {
	int i;
	for(i = 0; i < mapa->numJugadores; i++) {
		sem_post(mapa->semaforo.jugador[i]);
	} 
	for(i = 0; i < mapa->numFantasmas; i++) {
		sem_post(mapa->semaforo.fantasma[i]);
	}
}
