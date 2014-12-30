#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "estructuras.h"
#include "fantasma.h"
#include "jugador.h"
#include "imprimeMapa.h"

#define DIMY 			12
#define DIMX 			20
#define NUMJUGADORES	1
#define NUMFANTASMAS	1

int main() {
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

	COORDENADA jugadores[NUMJUGADORES] = {{1,1}};
	COORDENADA fantasmas[NUMFANTASMAS] = {{9,4}};
	

	MAPA mapa = { (char **) &aux, {DIMX, DIMY}, NUMFANTASMAS, NUMJUGADORES, fantasmas, jugadores } ;

	imprimeMapa(mapa, true);	
	while(1) {
		jugador1(&mapa, 0, NULL);
		fantasma(&mapa);
		//sleep(1);
		imprimeMapa(mapa, false);			
		mvprintw(mapa.dimensiones.y + 4,0, "Num Interacciones = %d", ++numInteracciones);
	}

	endwin();
	return 0;
}