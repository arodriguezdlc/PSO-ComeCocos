/*
*	Funcion leeMapa
*	Descripcion:  Lee el mapa del fichero y lo guarda
*	en un array.
*/

#include <stdio.h>
#include <string.h>

#define TAMBUFFER 1000 //maximo tamanio de linea
#define TRUE 1
#define FALSE 0 

char * leeMapa(FILE * fichero) {


	char * mapa; //Puntero al array con el mapa
	char buffer[TAMBUFFER]; //buffer para almacenar lineas
	int numLineas = 0; //Numero de lineas leidas
	int tamLinea = 0; //Tamanio de la linea leida
	char * plinea; //puntero al inicio de linea;
	//Lectura de linea de forma segura 
	//Consultar: http://niallohiggins.com/2009/10/03/read-a-file-line-by-line-in-c-secure-fgets-idiom/
	while(salir == FALSE && fgets(buffer, TAMBUFFER, fichero) != NULL) {
		buffer[strcspn(buffer, "\n")] = '\0';
		tamLinea = strlen(buffer);
		numLineas++;
		if (buffer[0] == '\0') {
			salir == TRUE;
		}
		else {
			plinea = malloc(tamLinea * sizeof(char));
			strcp(plinea, buffer);
			
		}
	}
	compruebaMapa(); //TODO
	 //Comprobamos que el mapa esta bien
	//los criterios habra que documentarlos

	return mapa;
}