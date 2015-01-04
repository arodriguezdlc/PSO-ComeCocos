/*
*	principal.c -> funcion main de PSO-ComeCocos
*/	

/*	Librerias  */
#include <stdio.h>
#include <ncurses.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

/*  Includes propios */
//#include "error.h"
#include "estructuras.h"
#include "semaforos.h"
#include "hilos.h"
#include "imprimeMapa.h"
#include "keyboard.h"

#define NUMARGS			1
#define MAX_IT			3000

#define DIMY 			12
#define DIMX 			20
#define NUMJUGADORES	1
#define NUMFANTASMAS	3

#define TRUE 			1
#define FALSE 			0
#define DELAY 			1000
/*
 	A la funcion main le pasamos el path del archivo de mapas
*/
int main(int argc, char ** argv) {	

	//VARIABLES
	unsigned int numInteracciones = 0;
	char cuadrado[DIMY][DIMX]= {
		"###################",
		"#                 #",
		"##### ### ### #####",
		"##### ### ### #####",
		"#                 #",
		"# ### ###-### ### #",
		"#     #     #     #",
		"# ### ####### ### #",
		"#                 #",
		"# ####### ####### #",		
		"#                 #",
		"###################"
	};
	char * aux[DIMY];
	int i;
	for(i = 0; i < DIMY; i++) {
		aux[i] = cuadrado[i];
	}
	HILOS hilos;
	MOVING moving; 
	COORDENADA jugadores[NUMJUGADORES] = {{1,1}};
	COORDENADA fantasmas[NUMFANTASMAS] = {{7,6}, {9,6}, {11,6}};
	MAPA mapa = { (char **) &aux, {DIMX, DIMY}, NUMFANTASMAS, NUMJUGADORES, fantasmas, jugadores, {0, 0} } ;
	
	//Comprobamos numero de argumentos
	if (argc != NUMARGS) {		
		//error(1);
		printf("%s: Numero de argumentos incorrecto\n", argv[0]);
	} else if (creaSemaforos(&mapa)) {			
		printf("Error en creaSemaforos\n");
	} else if (creaHilos(&mapa, &hilos, &moving)) {			
		printf("Error en creaHilos\n");
	} else {		
		//TEMPORIZACION DEL PROGRAMA:			
		imprimeMapa(mapa, TRUE);
		mvprintw(mapa.dimensiones.y + 4,0, "Num Interacciones = %d", 0);
		creaHilosKb(&moving);

		for (i = 0; i < MAX_IT; i++) {							
			sleep(1);
			subirSemaforos(&mapa);								
			imprimeMapa(mapa, FALSE);				
			mvprintw(mapa.dimensiones.y + 4,0, "Num Interacciones = %d", ++numInteracciones);
			refresh();
		}
		liberaHilos(&hilos);
	}		
	endwin();		
	eliminaSemaforos(&mapa, FALSE);
	
	return 0;
}
