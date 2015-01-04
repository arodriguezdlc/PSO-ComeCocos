/*
*	Estructuras basicas del programa
*	Autores:
*		Alberto Rodríguez de la Cruz
*		Juan Antonio Piñero Pérez
*		Azahara María Porras Tejada
*		Francisco Javier Rodríguez López
*/

//REQUIERE DE PTHREAD.H Y SEMAPHORE.H

typedef struct coordenada {
	unsigned int x;
	unsigned int y;
} COORDENADA;

typedef struct semaforo {
	sem_t ** jugador;
	sem_t ** fantasma;
} SEMAFORO;

typedef struct mapa {
	char ** mapa;		    //Mapa sin jugadores ni fantasmas	
	COORDENADA dimensiones; //Dimensiones del mapa
	int numFantasmas;		//Numero de fantasmas
	int numJugadores;		//Numero de jugadores
	COORDENADA * fantasma;  //Tabla de posiciones de fantasmas
	COORDENADA * jugador;   //Tabla de posiciones de jugadores
	SEMAFORO semaforo;	
} MAPA;

//	Estructura con la configuracion de controles de un jugador
typedef struct controles {	
	char arriba;	//Tecla asignada a arriba
	char abajo;		//Tecla asignada a abajo
	char derecha;	//Tecla asignada a derecha
	char izquierda;	//Tecla asignada a izquierda
} CONTROLES; 

//	Estructura de parametros que se le pasa al hilo del jugador
typedef struct jugador {
	unsigned int id;
	CONTROLES controles;
	MAPA * mapa;
} JUGADOR; 

//	Estructura de parametros que se le pasa al hilo del fantasma
typedef struct fantasma {
	unsigned int id;
	MAPA * mapa;
} FANTASMA; 

//	Estructura donde almacenar los identificadores de los hilos de jugadores y fantasmas.
typedef struct hilos {
	pthread_t * fantasma;	//Puntero a tabla de identificadores de fantasmas
	pthread_t * jugador;	//Puntero a tabla de identificadores de jugadores
	pthread_t control;		//Identificador de hilo de control
} HILOS;