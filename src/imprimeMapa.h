/*
	Fichero de cabecera de imprimeMapa

	Define las estructuras coordenada y mapa. (seran movidas a otra ubicacion)
	Tambien define la funcion imprimeMapa.
*/

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
void imprimeMapa(MAPA mapa, int inicio);