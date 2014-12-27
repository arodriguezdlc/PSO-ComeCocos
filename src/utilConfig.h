

/*
*	Funcion eliminaEspacios
*	Descripcion: elimina los espacios que hay al principio de una cadena de caracteres.
*		Devuelve una cadena con memoria reservada dinamicamente para albergarla. Funciona con cadenas
*		de tamanio maximo INI_MAX_LINE, definido en ini.h
*	Parametros: cadena a la que se le quieren quitar los espacios
*	Return: cadena con memoria reservada sin espacios. Hay que liberarla fuera.
*/
char * eliminaEspacios(char * buffer);

/*
*	Funcion reservaMemoria
*	Descripcion: Reserva la memoria necesaria para almacenar los datos de configuracion
*	Parametros: estructura MAPA
*	Return: devuelve TRUE si ha habido error y FALSE en caso contrario
*/
int reservaMemoria(MAPA * mapa);

/*
*	Funcion liberaMemoria
*	Descripcion: Libera la memoria reservada anteriormete para almacenar los datos de configuracion
*	Parametros: estructura MAPA
*	Return: nada.
*/
void liberaMemoria(MAPA * mapa);

/*
*	Funcion compruebaConfiguracion1
*	Descripcion: comprueba que la configuracion obtenida en el primer parseo sea correcta.
*	Parametros: puntero a estructura mapa (no se modifica).
*	Return: devuelve TRUE si hay un error de configuracion o FALSE si todo es correcto.	
*/
int compruebaConfiguracion1(MAPA * mapa);