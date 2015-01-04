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
void liberaHilos(HILOS * hilos, MAPA * mapa);



