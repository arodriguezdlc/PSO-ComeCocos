/*
*	principal.c -> funcion main de PSO-ComeCocos
*/	

/*	Librerias  */
#include <pthread.h>
#include <stdio.h>
/*  Includes propios */
#include "error.h"

/*
 	A la funcion main le pasamos el path del archivo de mapas
*/
int main(int argc, char * argv) {
	
	//Comprobamos numero de argumentos
	if (argc != 2) 
		error(1);
	else {
		lecturaMapa(); //TODO
		//TODO
	}
	return 0;
}