#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#include "estructuras.h"
#include "fantasma.h"
#include "jugador.h"
#include "hilos.h"

#define TRUE 1
#define FALSE 0

/*
*	Funcion de inicio del hilo de jugador
*	Descripcion: llama y gestiona la temporizacion de la logica
*		del jugador
*	Parametros: estructura jugador
*	Return: nada
*/
void * hiloJugador (void * pjugador) {
	JUGADOR jug = 	{	((JUGADOR *) pjugador)->id, 
						{ 	((JUGADOR *) pjugador)->controles.arriba,
						  	((JUGADOR *) pjugador)->controles.abajo,
						  	((JUGADOR *) pjugador)->controles.derecha,
						  	((JUGADOR *) pjugador)->controles.izquierda,
						},  
						((JUGADOR *) pjugador)->mapa };

	char  tablaControles[4] = 	{ 	jug.controles.derecha, 
									jug.controles.izquierda,
									jug.controles.arriba,
									jug.controles.abajo
								} ;

	//sigset_t set;	
	//int sig;	
	//manejaSenial(&set); 
	
	while(1) {						
		sem_wait(jug.mapa->semaforo.jugador[jug.id]);
		jugador(jug.mapa, 1, tablaControles, jug.id,NULL);			
	}
	pthread_exit(NULL);
}

/*
*	Funcion de inicio del hilo de fantasma
*	Descripcion: llama y gestiona la temporizacion de la logica
*		del fantasma
*	Parametros: estructura fantasma
*	Return: nada
*/
void * hiloFantasma (void * pfantasma)  {
	FANTASMA fant = { ((FANTASMA *) pfantasma)->id, ((FANTASMA *) pfantasma)->mapa }; 	
	
	int cla = 0;
	while(1) {		
		sem_wait(fant.mapa->semaforo.fantasma[fant.id]);		
		fantasma(fant.mapa, fant.id, &cla,NULL);
	}
	pthread_exit(NULL);
} 

/*
*	Funcion creaHilos
*	Descripcion: crea los hilos de los jugadores y los fantasmas
*	Parametros: puntero a estructura MAPA y puntero a estructura HILOS
*	Return: si ha habido error de memoria devuelve TRUE, en caso contrario
*		devuelve FALSE
*/
int creaHilos(MAPA * mapa, HILOS * hilos) {

	int i;	
	int error = FALSE;
	JUGADOR * pjugador = NULL;
	JUGADOR jugador = {0, {'w', 's', 'd', 'a'}, mapa};
	FANTASMA * pfantasma = NULL;
	FANTASMA fantasma = {0, mapa};

	if (NULL == (pjugador = calloc(mapa->numJugadores, sizeof(JUGADOR)))) {
		error = TRUE;
		printf("error de memoria\n");
	} else if (NULL == (pfantasma = calloc(mapa->numFantasmas, sizeof(FANTASMA)))) {
		error = TRUE;
		printf("error de memoria\n");
	} else if (NULL == (hilos->jugador = calloc(mapa->numJugadores, sizeof(pthread_t)))) {
		error = TRUE;
		printf("error de memoria\n");
	} else if (NULL == (hilos->fantasma = calloc(mapa->numFantasmas, sizeof(pthread_t)))) {
		error = TRUE;
		printf("error de memoria\n");		
	} else {
		for(i = 0; i < mapa->numJugadores; i++) {
			dupStructJug(jugador, &pjugador[i]);
			pjugador[i].id = i;
			pthread_create(&(hilos->jugador[i]), NULL, hiloJugador,  &pjugador[i]);
		}
		for(i = 0; i < mapa->numFantasmas; i++) {
			dupStructFant(fantasma, &pfantasma[i]);
			pfantasma[i].id = i;
			pthread_create(&(hilos->fantasma[i]), NULL, hiloFantasma, &pfantasma[i]);
		}
	}
	if(error == TRUE) {
		liberaHilos(hilos);
	}
	if(NULL != pjugador) {
		free(pjugador);
		pjugador = NULL;
	}
	if(NULL != pfantasma) {
		free(pfantasma);
		pfantasma = NULL;
	}
	return error;
}

/*
*	Funcion liberaHilos
*	Descripcion: libera la memoria reservada para almacenar los identificadores
*		de los hilos.
*	Parametros: HILOS (puntero)
*	Return: nada
*/
void liberaHilos(HILOS * hilos) {
	
	if(NULL != hilos->jugador) {
		free(hilos->jugador);
		hilos->jugador = NULL;
	}
	if(NULL != hilos->fantasma) {
		free(hilos->fantasma);
		hilos->fantasma = NULL; 
	}
}

/*
*	Funcion dupStructJug
*	Descripcion: duplica una estructura JUGADOR en otra, realizando la asignacion
*	de cada parametro.
*	Parametros: estructura JUGADOR de origen y puntero a estructura JUGADOR destino.
*	Return: nada.
*/
void dupStructJug(JUGADOR origen, JUGADOR * destino) {	
	destino->id = origen.id;
	destino->controles.arriba = origen.controles.arriba;
	destino->controles.abajo = origen.controles.abajo;
	destino->controles.derecha = origen.controles.derecha;
	destino->controles.izquierda = origen.controles.izquierda;
	destino->mapa = origen.mapa;
}

/*
*	Funcion dupStructFant
*	Descripcion: duplica una estructura FANTASMA en otra, realizando la asignacion
*	de cada parametro.
*	Parametros: estructura FANTASMA de origen y puntero a estructura FANTASMA destino.
*	Return: nada.
*/
void dupStructFant(FANTASMA origen, FANTASMA * destino) {
	destino->id = origen.id;	
	destino->mapa = origen.mapa;
}