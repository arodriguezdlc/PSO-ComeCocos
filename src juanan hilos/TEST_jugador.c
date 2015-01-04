#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "estructuras.h"
#include "fantasma.h"
#include "jugador.h"
#include "imprimeMapa.h"
#include "choque.h"
#include "semaforos.h"

#define DIMY 			12
#define DIMX 			20
#define NUMJUGADORES	1
#define NUMFANTASMAS	3

struct moving{
char movin;
};

void * caracter(void * car);/*{
char * car2;
car2=(char *)car;
while(1){
*car2 = getch();
}}*/

int main(void) {
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
	//char mov = 'd';
	struct moving a;
	pthread_t th1;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	

	for(i = 0; i < DIMY; i++) {
		aux[i] = cuadrado[i];
	}

	COORDENADA jugadores[NUMJUGADORES] = {{1,1}};
	COORDENADA fantasmas[NUMFANTASMAS] = {{7,6}, {9,6}, {11,6}};
	

	MAPA mapa = { (char **) &aux, {DIMX, DIMY}, NUMFANTASMAS, NUMJUGADORES, fantasmas, jugadores, {0,0} } ;

	imprimeMapa(mapa, true);
	pthread_create(&th1, &attr, caracter, (void *)&a);	
	while(gameover==0) {
		
		jugador(&mapa, 0, NULL, 0, a.movin);
		if(choque(&mapa, 0,0)!=0)//para atravesarlo
			gameover++;
		if(choque(&mapa, 1,0)!=0)
			gameover++;
		if(choque(&mapa, 2,0)!=0)
			gameover++;
		fantasma(&mapa, 0, &cla1);

		fantasma(&mapa, 1, &cla2);

		fantasma(&mapa, 2, &cla3);
		usleep(75000);
		//flushinp();//vaciar buffer del teclado
		usleep(425000);
		imprimeMapa(mapa, false);
		if(choque(&mapa, 0,0)!=0||choque(&mapa, 1,0)!=0||choque(&mapa, 2,0)!=0)//para acabar en el mismo punto
			gameover++;			
		mvprintw(mapa.dimensiones.y + 4,0, "Num Interacciones = %d", ++numInteracciones);
		mvprintw(mapa.dimensiones.y + 3,0, "mov = %c", a.movin);
				
	}

	endwin();
	puts("\n\n\n\n\t\t\tgame over\n\n\n\n");
	
    pthread_attr_destroy(&attr);
	return 0;
}
void * caracter(void * car){
	struct moving *mover;
	//char * car2;
	//car2=(char *)car;
	mover=(struct moving *)car;
	while(1){
		//*car2 = getch();
		noecho();
		mover->movin=getch();
	}
	pthread_exit(NULL);
}
