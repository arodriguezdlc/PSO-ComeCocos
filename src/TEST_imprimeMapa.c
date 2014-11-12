#include <stdio.h>
#include <ncurses.h>

typedef struct coordenada {
	unsigned int x;
	unsigned int y;
} COORDENADA;

typedef struct mapa {
	char ** mapa;		    //Mapa sin jugadores ni fantasmas	
	COORDENADA dimensiones; //Dimensiones del mapa
	COORDENADA * fantasma;  //Tabla de posiciones de fantasmas
	COORDENADA * jugador;   //Tabla de posiciones de jugadores
} MAPA;

/*
	Funcion imprimeMapa:
	Argumentos => 
		MAPA mapa:estructura tipo MAPA con el mapa almacenado y sus
		dimensiones (ATENCION: se asume que las dimensiones son correctas).
		int inicio: si es distinto de 0 se inicia la pantalla ncurses, si
		es 0 no. Solo se debe inicializar la pantalla ncurses la primera
		vez que se llama a la funcion.
	Descripcion => inicializa la pantalla ncurses (si inicio != 0)
	e imprime el mapa si jugadores ni fantasmas.
	Return => nada (void)		 
*/
void imprimeMapa(MAPA mapa, int inicio) {

	unsigned int x;
	unsigned int y;
	if(inicio != 0) {
		initscr(); //Inicializamos la pantalla
	} 	
	erase(); //Limpiamos la pantalla
	mvprintw(0,0, "COMECOCOS - PROYECTO S.O"); //Titulo
	//Impresion del mapa
	for (y = 0; y < mapa.dimensiones.y; y++) {		
		for(x = 0; x < mapa.dimensiones.x; x++) {	
			//Se deja a la y un margen de 2 para que quepa el titulo		
			mvprintw(y+2, x, "%c", mapa.mapa[y][x]);
		}		
	}
}
/*
void imprimir(char ** mapa) {

}
*/

 
int main() {
	//tabla[y][x];
	char cuadrado[10][20]= {
		"####################",
		"#                  #",
		"#                  #",
		"#                  #",
		"#                  #",
		"#                  #",
		"#                  #",
		"#                  #",
		"#                  #",
		"####################",
	};
	char * aux[10];
	int i;
	for(i = 0; i < 10; i++) {
		aux[i] = cuadrado[i];
	}

	//printf("cuadrado[0][0] = %d",(int) &cuadrado[0][0]);

	MAPA mapaPrueba = { (char **) &aux, {20, 10}, NULL, NULL} ;	
	//MAPA mapaPrueba = { (char **) cuadrado, {20,20}, NULL, NULL};


	imprimeMapa(mapaPrueba, true);	

	mvprintw(mapaPrueba.dimensiones.y + 3,0, "PARA SALIR PULSE q");
	noecho();
	while((char) getch() != 'q') ;

	endwin();

	return 0;
}

