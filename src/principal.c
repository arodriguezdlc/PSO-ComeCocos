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
#include "choque.h"

#define NUMARGS			1
#define MAX_IT			100

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
	int n = 1000000;
	int salir = FALSE;
	MOVING moving; 
	COORDENADA jugadores[NUMJUGADORES] = {{1,1}};
	COORDENADA fantasmas[NUMFANTASMAS] = {{7,6}, {9,6}, {11,6}};
	MAPA mapa = { (char **) &aux, {DIMX, DIMY}, NUMFANTASMAS, NUMJUGADORES, fantasmas, jugadores, {0, 0} } ;
	COORDENADA jugadoresAnt[NUMJUGADORES] = {{0,0}};
	COORDENADA fantasmasAnt[NUMFANTASMAS] = {{0,0}, {0,0}, {0,0}};
	MAPAANT mapaAnt = { 0, 0, fantasmasAnt, jugadoresAnt};

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

		for (i = 0; salir == FALSE && numInteracciones < MAX_IT ;i++) {							
			usleep(n);
			guardamapa(&mapa, &mapaAnt);
			subirSemaforos(&mapa);			
			imprimeMapa(mapa, FALSE);				
			mvprintw(mapa.dimensiones.y + 4,0, "Num Interacciones = %d", ++numInteracciones);
			if(i>=20){
				n=n/2;
				i=0;
				}
			refresh();
			if(TRUE == choque(&mapa, &mapaAnt, mapa.numFantasmas, mapa.numJugadores)) {
				salir = TRUE;
			}

		}
		liberaHilos(&hilos);
	}		
	endwin();		
	eliminaSemaforos(&mapa, FALSE);
	printf("Usted ha durado %d interacciones\n", numInteracciones);
	if(numInteracciones == MAX_IT) {
		printf("HA GANADO!!!\n");
	}
	return 0;
}
