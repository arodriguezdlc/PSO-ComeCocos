#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inih/ini.h"
#include "estructuras.h"
#include "utilConfig.h"
#define TRUE 1
#define FALSE 0

/*
*	Funcion eliminaEspacios
*	Descripcion: elimina los espacios que hay al principio de una cadena de caracteres.
*		Devuelve una cadena con memoria reservada dinamicamente para albergarla. Funciona con cadenas
*		de tamanio maximo INI_MAX_LINE, definido en ini.h
*	Parametros: cadena a la que se le quieren quitar los espacios
*	Return: cadena con memoria reservada sin espacios. Hay que liberarla fuera.
*/
char * eliminaEspacios(char * buffer) {    
    size_t i = 0;
    size_t j = 0;
    int salir = FALSE;
    char aux[INI_MAX_LINE];    
    for(i = 0; salir == FALSE && i < strlen(buffer); i++) {
        if(!isspace((int) buffer[i])) {
            for(j = 0; j < strlen(buffer); j++) {
                aux[j] = buffer[i];
                i++;
            }  
            salir = TRUE;      
        }        
    }
    aux[j] = '\0';
    return strdup(aux);
}

/*
*	Funcion reservaMemoria
*	Descripcion: Reserva la memoria necesaria para almacenar los datos de configuracion
*	Parametros: estructura MAPA
*	Return: devuelve TRUE si ha habido error y FALSE en caso contrario
*/
int reservaMemoria(MAPA * mapa) {
	int error = FALSE;	
	if (NULL == (mapa->mapa = (char **) calloc(mapa->dimensiones.y, sizeof(char *)))) {
        error = TRUE;
        printf("Error de memoria\n");
    } else if (NULL == (mapa->jugador = (COORDENADA *) calloc(mapa->numJugadores, sizeof(COORDENADA)))) {
		error = TRUE;
		printf("Error de memoria\n");
	} else if (NULL == (mapa->fantasma = (COORDENADA *) calloc(mapa->numFantasmas, sizeof(COORDENADA)))) {
		error = TRUE;
		printf("Error de memoria\n");
	}
	return error;
}

/*
*	Funcion liberaMemoria
*	Descripcion: Libera la memoria reservada anteriormete para almacenar los datos de configuracion
*	Parametros: estructura MAPA
*	Return: nada.
*/
void liberaMemoria(MAPA * mapa) {
	unsigned int i; 
    if(mapa->jugador != NULL) {
		free(mapa->jugador);
		mapa->jugador = NULL;		
	}
    if(mapa->fantasma != NULL) {
		free(mapa->fantasma);
		mapa->fantasma = NULL;
	} 
    for(i = 0; i < mapa->dimensiones.y; i++) {
        if(mapa->mapa[i] != NULL) {
            free(mapa->mapa[i]);
            mapa->mapa[i] = NULL;
        }            
    }
    if(mapa->mapa != NULL) {
        free(mapa->mapa);
        mapa->mapa = NULL;
    }
}

/*
*	Funcion compruebaConfiguracion1
*	Descripcion: comprueba que la configuracion obtenida en el primer parseo sea correcta.
*	Parametros: puntero a estructura mapa (no se modifica).
*	Return: devuelve TRUE si hay un error de configuracion o FALSE si todo es correcto.	
*/
int compruebaConfiguracion1(MAPA * mapa) {
	int error = FALSE;
	if(mapa->dimensiones.x == 0) {
		error = TRUE;
		printf("Valor invalido para dimensiones.x\n");
	} else if (mapa->dimensiones.y == 0) {
		error = TRUE;
		printf("Valor invalido para dimensiones.y\n");		
	} else if (mapa->numJugadores == 0) {
		error = TRUE;
		printf("Valor invalido para numJugadores\n");
	} else if (mapa->numFantasmas == 0) {
		error = TRUE;
		printf("Valor invalido para numFantasmas\n");
	}
	return error;
}


//TEST DE ELIMINAESPACIOS [OK]

int main () {
	char buffer[] = "       	hola guapo\n";
	char * cadena = &buffer[0];
	cadena = eliminaEspacios(cadena);

	printf("%s", cadena);
	printf("\n\n-----------------\n");
	printf("Tamanio cadena: %lu", strlen(cadena));

	if(NULL != cadena) {
		free(cadena);
		cadena = NULL;	
		printf("\n*** Memoria Liberada ***\n");
	} else {
		printf("\n*** Memoria NO Liberada ***\n");
	}
	
	return 0;
}


