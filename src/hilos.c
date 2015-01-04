#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

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
						((JUGADOR *) pjugador)->mapa,
						((JUGADOR *) pjugador)->moving,
						((JUGADOR *) pjugador)->sem };

	char  tablaControles[4] = 	{ 	jug.controles.derecha, 
									jug.controles.izquierda,
									jug.controles.arriba,
									jug.controles.abajo
								} ;
	sem_post(jug.sem);

	//sigset_t set;	
	//int sig;	
	//manejaSenial(&set); 		
	while(1) {						
		sem_wait(jug.mapa->semaforo.jugador[jug.id]);
		jugador(jug.mapa, 0, tablaControles, jug.id, jug.moving->movin);			
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
	FANTASMA fant = { ((FANTASMA *) pfantasma)->id, ((FANTASMA *) pfantasma)->mapa, ((FANTASMA *) pfantasma)->sem }; 		
	int cla = 0;	
	sem_post(fant.sem);
	while(1) {		
		sem_wait(fant.mapa->semaforo.fantasma[fant.id]);		
		fantasma(fant.mapa, fant.id, &cla);
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
int creaHilos(MAPA * mapa, HILOS * hilos, MOVING * moving) {

	int i;	
	int error = FALSE;	
	JUGADOR jugador = {0, {'w', 's', 'd', 'a'}, mapa, moving, NULL};	
	FANTASMA fantasma = {0, mapa, NULL};
	sem_t * leeConfig;

	//Creamos semaforo de control de lectura de las estructuras JUGADOR y FANTASMA
	sem_unlink("ComeCocos-LeeConfig");
	if(SEM_FAILED == (leeConfig = sem_open("ComeCocos-LeeConfig", O_CREAT, 0700, 1))) {
		error = TRUE;
		printf("Error al crear semaforo LeeConfig\n");	
	} else if (NULL == (hilos->jugador = calloc(mapa->numJugadores, sizeof(pthread_t)))) {
		error = TRUE;
		printf("error de memoria\n");
	} else if (NULL == (hilos->fantasma = calloc(mapa->numFantasmas, sizeof(pthread_t)))) {
		error = TRUE;
		printf("error de memoria\n");
	} else {
		jugador.sem = leeConfig;
		for(i = 0; i < mapa->numJugadores; i++) {
			sem_wait(leeConfig);
			jugador.id = i;			
			pthread_create(&(hilos->jugador[i]), NULL, hiloJugador,  &jugador);
		}
		fantasma.sem = leeConfig;
		for(i = 0; i < mapa->numFantasmas; i++) {			
			sem_wait(leeConfig);
			fantasma.id = i;					
			pthread_create(&(hilos->fantasma[i]), NULL, hiloFantasma, &fantasma);			
		}
		sem_wait(leeConfig);
		sem_close(leeConfig);
	}
	sem_unlink("ComeCocos-LeeConfig");

	if(error == TRUE) {
		liberaHilos(hilos);
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

