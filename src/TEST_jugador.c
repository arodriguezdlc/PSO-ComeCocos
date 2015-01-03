#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include "estructuras.h"
#include "fantasma.h"
#include "jugador.h"
#include "imprimeMapa.h"
#include "choque.h"

#define DIMY 			12
#define DIMX 			20
#define NUMJUGADORES	1
#define NUMFANTASMAS	3

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
	int cla1 = 0; //Memoria Fantasma
	int cla2 = 0;
	int cla3 = 0;
	int gameover=0;//para ver si choca
	for(i = 0; i < DIMY; i++) {
		aux[i] = cuadrado[i];
	}

	COORDENADA jugadores[NUMJUGADORES] = {{1,1}};
	COORDENADA fantasmas[NUMFANTASMAS] = {{7,6}, {9,6}, {11,6}};
	

	MAPA mapa = { (char **) &aux, {DIMX, DIMY}, NUMFANTASMAS, NUMJUGADORES, fantasmas, jugadores } ;

	imprimeMapa(mapa, true);	
	while(gameover==0) {

		jugador(&mapa, 0, NULL, 0);
		if(choque(&mapa, 0,0)!=0)//para atravesarlo
			gameover++;
		if(choque(&mapa, 1,0)!=0)
			gameover++;
		if(choque(&mapa, 2,0)!=0)
			gameover++;
		fantasma(&mapa, 0, &cla1);

		fantasma(&mapa, 1, &cla2);

		fantasma(&mapa, 2, &cla3);

		usleep(500000);
		imprimeMapa(mapa, false);
		if(choque(&mapa, 0,0)!=0||choque(&mapa, 1,0)!=0||choque(&mapa, 2,0)!=0)//para acabar en el mismo punto
			gameover++;			
		mvprintw(mapa.dimensiones.y + 4,0, "Num Interacciones = %d", ++numInteracciones);
				
	}

	endwin();
	puts("\n\n\n\n\t\t\tgame over\n\n\n\n");
	return 0;
}
