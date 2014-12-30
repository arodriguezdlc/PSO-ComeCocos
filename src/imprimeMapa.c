#include <stdio.h>
#include <ncurses.h>
#include "estructuras.h"
#include "imprimeMapa.h"

/*
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
*/
#define COLISION 10
#define NUM_MAX_JUG 3
#define NUM_MAX_FANT 3
/*
	-----  FUNCION IMPRIMEMAPA  -----
	Argumentos => 
		MAPA mapa:estructura tipo MAPA con el mapa almacenado y sus
		dimensiones (ATENCION: se asume que las dimensiones son correctas).
		int inicio: si es distinto de 0 se inicia la pantalla ncurses, si
		es 0 no. Solo se debe inicializar la pantalla ncurses la primera
		vez que se llama a la funcion.
	Descripcion => inicializa la pantalla ncurses (si inicio != 0)
	e imprime el mapa si jugadores ni fantasmas.
	Return => nada (void)	
	VERSION => 1.0	 
*/
void imprimeMapa(MAPA mapa, int inicio) {

	unsigned int x;
	unsigned int y;
	int i;
	char simboloJugador = 'C';
	char simboloFantasma = 'A';	
	if(inicio != 0) {
		initscr(); //Inicializamos la pantalla
		if (has_colors()) {
  			start_color();
  			init_pair(1, COLOR_RED, COLOR_BLACK);
  			init_pair(2, COLOR_BLUE, COLOR_BLACK);
  			init_pair(3, COLOR_YELLOW, COLOR_BLACK);

  			init_pair(COLISION, COLOR_WHITE, COLOR_BLACK);
  		}
	} 	
	
	erase(); //Limpiamos la pantalla
	
	mvprintw(0,0, "COMECOCOS - PROYECTO S.O"); //Titulo
	//Impresion del mapa (Color amarillo)

	for (y = 0; y < mapa.dimensiones.y; y++) {		
		for(x = 0; x < mapa.dimensiones.x; x++) {	
			//Se deja a la y un margen de 2 para que quepa el titulo		
			mvprintw(y+2, x, "%c", mapa.mapa[y][x]);
		}		
	}
	//Impresion de jugadores
	//detectaColisiones(MAPA * mapa);	TODO
	for (i = 0; i < mapa.numJugadores; i++) {

		attron(COLOR_PAIR(i+1));
		mvprintw((mapa.jugador[i].y)+2, mapa.jugador[i].x, "%c", simboloJugador);
		attroff(COLOR_PAIR(i+1));
	}
	//Impresion de fantasmas
	for (i = 0; i < mapa.numFantasmas; i++) {
		attron(COLOR_PAIR(i+1));
		mvprintw((mapa.fantasma[i].y)+2, mapa.fantasma[i].x, "%c", simboloFantasma);
		attroff(COLOR_PAIR(i+1));
	}
}
/* TODO - NO ESTA TERMINADO
void detectaColisiones(MAPA * mapa) {
	int i; 
	for (i = 0; i < mapa.numJugadores; i++) {
		for (j = 0; j < mapa.numJugadores; i++) {
			if((i != j) && (mapa.jugadores[i].x == mapa.jugadores[j].x) && (mapa.jugadores[i].y == mapa.jugadores[j].y
					&& (mapa.jugadores[i].x != 0 || mapa.jugadores[i].y != 0))) {
				mapa.jugadores[j].x = 0;
				mapa.jugadores[j].y = 0;
			}
		}
	}
}
*/

