/*
*	Funcion creaHilos
*	Descripcion: crea los hilos de los jugadores y los fantasmas
*	Parametros: puntero a estructura MAPA y puntero a estructura HILOS
*	Return: si ha habido error de memoria devuelve TRUE, en caso contrario
*		devuelve FALSE
*/
int creaHilos(MAPA * mapa, HILOS * hilos, MOVING * moving);

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

