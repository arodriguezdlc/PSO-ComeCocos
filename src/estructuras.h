/*
*	Estructuras basicas del programa
*	Autores:
		Alberto Rodríguez de la Cruz
		Juan Antonio Piñero Pérez
		Azahara María Porras Tejada
		Francisco Javier Rodríguez López
*/
#ifndef PTHREAD
#define PTHREAD
	#include <pthread.h>
#endif

typedef struct coordenada {
	unsigned int x;
	unsigned int y;
} COORDENADA;

typedef struct mapa {
	char ** mapa;		    //Mapa sin jugadores ni fantasmas	
	COORDENADA dimensiones; //Dimensiones del mapa
	int numFantasmas;		//Numero de fantasmas
	int numJugadores;		//Numero de jugadores
	COORDENADA * fantasma;  //Tabla de posiciones de fantasmas
	COORDENADA * jugador;   //Tabla de posiciones de jugadores
} MAPA;

typedef struct controles {	
	char arriba;	//Tecla asignada a arriba
	char abajo;		//Tecla asignada a abajo
	char derecha;	//Tecla asignada a derecha
	char izquierda;	//Tecla asignada a izquierda
} CONTROLES; 

typedef struct jugador {
	unsigned int id;
	CONTROLES controles;
	MAPA * mapa;
} JUGADOR; 

typedef struct fantasma {
	unsigned int id;
	MAPA * mapa;
} FANTASMA; 

typedef struct hilos {
	pthread_t * fantasma;
	pthread_t * jugador;		
} HILOS;