/*
*	principal.c -> funcion main de PSO-ComeCocos
*/	

/*	Librerias  */
#include <stdio.h>
#include <ncurses.h>
#ifndef PTHREAD
#define PTHREAD
	#include <pthread.h>
#endif
#include <signal.h>
#include <unistd.h>

/*  Includes propios */
//#include "error.h"
#include "estructuras.h"
#include "hilos.h"
#include "imprimeMapa.h"

#define NUMARGS			1
#define MAX_IT			3000

#define DIMY 			12
#define DIMX 			20
#define NUMJUGADORES	1
#define NUMFANTASMAS	3

#define TRUE 			1
#define FALSE 			0
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
	COORDENADA jugadores[NUMJUGADORES] = {{1,1}};
	COORDENADA fantasmas[NUMFANTASMAS] = {{7,6}, {9,6}, {11,6}};
	MAPA mapa = { (char **) &aux, {DIMX, DIMY}, NUMFANTASMAS, NUMJUGADORES, fantasmas, jugadores } ;
	
	//Comprobamos numero de argumentos
	if (argc != NUMARGS) {		
		//error(1);
		printf("%s: Numero de argumentos incorrecto\n", argv[0]);
	} else {
		imprimeMapa(mapa, TRUE);		 
		if (creaHilos(&mapa, &hilos)) {
			endwin();
			printf("Error en creaHilos\n");
		} else {	
			//TEMPORIZACION DEL PROGRAMA:			
			imprimeMapa(mapa, TRUE);
			for (i = 0; i < MAX_IT; i++) {					
				sleep(1);			
				enviaSenial(mapa, hilos);				
				imprimeMapa(mapa, FALSE);			
				mvprintw(mapa.dimensiones.y + 4,0, "Num Interacciones = %d", ++numInteracciones); 
			}
			liberaHilos(&hilos);
		}
		endwin();
	}
	return 0;
}