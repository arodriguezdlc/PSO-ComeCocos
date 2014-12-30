#include <stdio.h>
#include <ncurses.h>
#include "estructuras.h"
//#include "fantasma.h"
#include "jugador.h"
#include "imprimeMapa.h"

#define DIMY 			12
#define DIMX 			20
#define NUMJUGADORES	1
#define NUMFANTASMAS	0

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
	char tecla;
	for(i = 0; i < 10; i++) {
		aux[i] = cuadrado[i];
	}

	COORDENADA jugadores[NUMJUGADORES] = {{2,2}};
	//COORDENADA fantasmas[NUMFANTASMAS] = {{8,7}};
	

	MAPA mapa = { (char **) &aux, {DIMY, DIMX}, NUMFANTASMAS, NUMJUGADORES, jugadores, NULL } ;

	imprimeMapa(mapa, true);
	while((tecla = (char) getch()) != 'q') {
		jugador1(&mapa, 0, NULL);
		imprimeMapa(mapa, false);
		mvprintw(mapa.dimensiones.y + 3,0, "PARA SALIR PULSE q");		
		mvprintw(mapa.dimensiones.y + 4,0, "Num Interacciones = %d", ++numInteracciones);
	}

	endwin();
	return 0;
}