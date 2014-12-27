/*
*	Estructuras basicas del programa
*	Autores:
		Alberto Rodríguez de la Cruz
		Juan Antonio Piñero Pérez
		Azahara María Porras Tejada
		Francisco Javier Rodríguez López
*/

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