/*
*	Funcion creaHilos
*	Descripcion: crea los hilos de los jugadores y los fantasmas
*	Parametros: puntero a estructura MAPA y puntero a estructura HILOS
*	Return: si ha habido error de memoria devuelve TRUE, en caso contrario
*		devuelve FALSE
*/
int creaHilos(MAPA * mapa, HILOS * hilos);

/*
*	Funcion liberaHilos
*	Descripcion: libera la memoria reservada para almacenar los identificadores
*		de los hilos.
*	Parametros: HILOS (puntero)
*	Return: nada
*/
void liberaHilos(HILOS * hilos);

/*
*	Funcion enviaSenial
*	Descripcion: envia una senial a todos los hilos creados por la funcion creaHilos
*	Parametros: estructura MAPA y estructura HILOS, habiendose llamado anteriormente 
*		a la funcion creaHilos.
*	Return: nada
*/
void enviaSenial(MAPA mapa, HILOS hilos);

/*
*	Funcion manejaSenial
*	Descripcion: configura la captura de las seniales en los hilos.
*	Parametros: sigset_t * set
*	Return: nada
*/
void manejaSenial(sigset_t * set);

/*
*	Funcion dupStructJug
*	Descripcion: duplica una estructura JUGADOR en otra, realizando la asignacion
*	de cada parametro.
*	Parametros: estructura JUGADOR de origen y puntero a estructura JUGADOR destino.
*	Return: nada.
*/
void dupStructJug(JUGADOR origen, JUGADOR * destino);

/*
*	Funcion dupStructFant
*	Descripcion: duplica una estructura FANTASMA en otra, realizando la asignacion
*	de cada parametro.
*	Parametros: estructura FANTASMA de origen y puntero a estructura FANTASMA destino.
*	Return: nada.
*/
void dupStructFant(FANTASMA origen, FANTASMA * destino);
