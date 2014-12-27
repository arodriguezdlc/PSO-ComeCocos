/*
*	LECTURA DEL FICHERO DE CONFIGURACION. SE UTILIZA EL FORMATO INI Y UN PARSER (INIH)
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <ncurses.h>
#include "inih/ini.h"
#include "estructuras.h"
#include "imprimeMapa.h"

#define TRUE 1
#define FALSE 0

#define FILECONFIG "conftest.ini"
#define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0

/*
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
*/
//Estructura ampliada para albergar datos de control en los handlers.
typedef struct mapaAmpliado {
    MAPA * mapa;
    int control[5]; //Las cinco variables de handler2
} MAPAAMPLIADO;


char * eliminaEspacios(char * buffer);

/*
*	Funcion que maneja los callbacks de ini_parse. Solo se utilizara en este fichero, 
*	no se exportará. Se encarga de almacenar los valores del fichero de configuracion
*	en la estructura MAPA.
*/
static int handler1(void* user, const char* section, const char* name,
                   const char* value)
{
    MAPA * mapa = (MAPA *) user;

    //fprintf(stdout, "[DEBUG] Entramos en handler1\n");     
    if        (MATCH("DIMENSIONES", "X")) {
    	if(mapa->dimensiones.x == 0) {
    		mapa->dimensiones.x = atoi(value);
    	} else { //DEBUG    		
    		fprintf(stdout, "[DEBUG] Leido multiples veces - [DIMENSIONES - X]\n");
    	}
    } else if   (MATCH("DIMENSIONES", "Y")) {
        if(mapa->dimensiones.y == 0) {
            mapa->dimensiones.y = atoi(value);
        } else { //DEBUG            
            fprintf(stdout, "[DEBUG] Leido multiples veces - [DIMENSIONES - Y]\n");
        }
    } else if   (MATCH("JUGADORES", "NUM")) {
        if(mapa->numJugadores == 0) {
            mapa->numJugadores = atoi(value);
        } else { //DEBUG            
            fprintf(stdout, "[DEBUG] Leido multiples veces - [JUGADORES - NUM]\n");
        }
    } else if   (MATCH("FANTASMAS", "NUM")) {
        if(mapa->numFantasmas == 0) {
            mapa->numFantasmas = atoi(value);
        } else { //DEBUG            
            fprintf(stdout, "[DEBUG] Leido multiples veces - [FANTASMAS - NUM]\n");
        }        
    } else {
        //fprintf(stdout, "[DEBUG] Coincidencia no encontrada\n");
    }
    return 1;
}

static int handler2(void* user, const char* section, const char* name,
                   const char* value)
{
    MAPAAMPLIADO * mapaAmpliado = (MAPAAMPLIADO *) user;
    MAPA * mapa = mapaAmpliado->mapa;
    char * buffer;
    char * cadena;

    //MAPEO INICIAL
    int numJugadoresXLeidos = mapaAmpliado->control[0];
    int numJugadoresYLeidos = mapaAmpliado->control[1];
    int numFantasmasXLeidos = mapaAmpliado->control[2];
    int numFantasmasYLeidos = mapaAmpliado->control[3];
    int mapaLeido           = mapaAmpliado->control[4];

    //fprintf(stdout, "[DEBUG] Entramos en handler2\n");     
    if (MATCH("JUGADORES", "X")) {    		
  		if(numJugadoresXLeidos < mapa->numJugadores) {
   			mapa->jugador[numJugadoresXLeidos].x = atoi(value);
   			numJugadoresXLeidos++;
    	} else {
    		fprintf(stdout, "[DEBUG] Demasiadas coordenadas X para jugadores - numJugadoresXLeidos = %d\n", ++numJugadoresXLeidos);    			
       	}
    } else if (MATCH ("JUGADORES", "Y")) {
    	if(numJugadoresYLeidos < mapa->numJugadores) {
    		mapa->jugador[numJugadoresYLeidos].y = atoi(value);
    		numJugadoresYLeidos++;
    	} else {
    		fprintf(stdout, "[DEBUG] Demasiadas coordenadas Y para jugadores - numJugadoresYLeidos = %d\n", ++numJugadoresYLeidos);
    	}
    } else if (MATCH ("FANTASMAS", "X")) {
    	if(numFantasmasXLeidos < mapa->numFantasmas) {
    		mapa->fantasma[numFantasmasXLeidos].x = atoi(value);
    		numFantasmasXLeidos++;
    	} else {
    		fprintf(stdout, "[DEBUG] Demasiadas coordenadas X para fantasmas - numFantasmasXLeidos = %d\n", ++numFantasmasXLeidos);    		
    	}
    } else if (MATCH ("FANTASMAS", "Y")) {
    	if(numFantasmasYLeidos < mapa->numFantasmas) {
    		mapa->fantasma[numFantasmasYLeidos].y = atoi(value);
    		numFantasmasYLeidos++;
    	} else {
    		fprintf(stdout, "[DEBUG] Demasiadas coordenadas Y para fantasmas - numFantasmasYLeidos = %d\n", ++numFantasmasYLeidos);    		
    	}
    } else if (MATCH ("MAPA", "mapa")) {
        if(mapaLeido == FALSE) {
            if(NULL == (buffer = strdup(value))) {
                fprintf(stderr, "ERROR DE MEMORIA STRDUP\n");
            } else {
                cadena = eliminaEspacios(buffer);
                //LIBERAMOS MEMORIA STRDUP
                if(NULL != buffer) {
                    free(buffer);
                    buffer = NULL;
                }
                //procesaCadena();
                printf("%s", cadena);
            }
            mapaLeido = TRUE;
        } else {
            fprintf(stdout, "[DEBUG] Mapa ya leido\n");
        }
    } else {
        //fprintf(stdout, "[DEBUG] Coincidencia no encontrada\n");
    }
    //TODO LECTURA MAPA!!!!!!!
    
    //MAPEO INVERSO FINAL
    mapaAmpliado->control[0] = numJugadoresXLeidos;
    mapaAmpliado->control[1] = numJugadoresYLeidos;
    mapaAmpliado->control[2] = numFantasmasXLeidos;
    mapaAmpliado->control[3] = numFantasmasYLeidos;
    mapaAmpliado->control[4] = mapaLeido;

    return 1;    
}
char * eliminaEspacios(char * buffer) {
    
    size_t i = 0;
    size_t j = 0;
    int salir = FALSE;
    char aux[INI_MAX_LINE];    
    for(i = 0; salir == FALSE && i < strlen(buffer); i++) {
        if(!isspace((int) buffer[i])) {
            for(j = 0; j < (strlen(buffer)-i); j++) {
                aux[j] = buffer[i];
                i++;
            }  
            salir = TRUE;      
        }        
    }
    aux[j] = '\0';
    return strdup(aux);    
}

void procesaCadena(char * cadena, MAPA * mapa) {
    int error;
    unsigned int i;
    char aux[INI_MAX_LINE];
    char * paux = &aux[0];
    paux = strtok(cadena, "\n");
    if(strlen(paux) != mapa->dimensiones.x) {
        error = TRUE;
        printf("Dimensiones del mapa incorrectas (linea 0)\n");
    } else {
        strcpy(paux, mapa->mapa[0]);
        for(i = 1; i < mapa->dimensiones.y; i++) {
            mapa->mapa[i] = strtok(NULL, "\n");
            if(strlen(mapa->mapa[i]) != mapa->dimensiones.x) {
                printf("ERROR LONGITUD\n");
            }
        }
    }
}

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
int compruebaConfiguracion2(MAPA * mapa) {
    int error = FALSE;
    int i;
    if(mapa->jugador == NULL) {
        error = TRUE;
    } else if (mapa->fantasma == NULL) {
        error = TRUE;
    } else {
        for(i = 0; (i < mapa->numJugadores) && (error == FALSE); i++) {
            if((mapa->jugador[i].x == 0) || (mapa->jugador[i].y == 0)) {
                error = TRUE;
                printf("Faltan coordenadas de jugadores\n");
            }
        } for(i = 0; (i < mapa->numFantasmas) && (error == FALSE); i++) {
            if((mapa->fantasma[i].x == 0) || (mapa->fantasma[i].y == 0)) {
                error = TRUE;
                printf("Faltan coordeandas de fantasmas\n");
            }
        }
    }
    return error;	
}

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

int leeConfig(MAPA * mapa) {
	//fprintf(stdout, "[DEBUG] Entramos en leeConfig\n");
	
    int error = FALSE;
    MAPAAMPLIADO mapaAmpliado = {mapa, {0, 0, 0, 0, FALSE}}; 
	if (ini_parse(FILECONFIG, handler1, mapa) < 0) {
        printf("Can't load 'conftest.ini'\n");       //MODIFICAR!!!!!!!!!!!  
    	error = TRUE;
    } else if (compruebaConfiguracion1(mapa)) { //Comprobamos que la configuracion inicial es correcta
    	error = TRUE;
    } else if (reservaMemoria(mapa)) {
     	error = TRUE;   
    } else if (ini_parse(FILECONFIG, handler2, &mapaAmpliado) <0) {
    	printf("Can't load 'conftest.ini'\n");
    	error = TRUE;
    } else if (compruebaConfiguracion2(mapa)) {
    	error = TRUE;
    }
    return error;
}

/* Main para testeo */
int main () {
    int i;
	MAPA mapa = { NULL, {0, 0}, 0, 0, NULL, NULL} ;		
	//if(leeConfig(&mapa)) {
    //    printf("ERROR EN LEECONFIG\n");
    //} else {
    leeConfig(&mapa);
    	printf("mapa.dimensiones.x = %d\n", mapa.dimensiones.x);
    	printf("mapa.dimensiones.y = %d\n", mapa.dimensiones.y);
    	printf("mapa.numJugadores  = %d\n", mapa.numJugadores);
    	printf("mapa.numFantasmas  = %d\n", mapa.numFantasmas);

        printf("\nCOORDENADAS DE JUGADORES\n");
    	for(i = 0; i < mapa.numJugadores; i++) {
            printf("mapa.jugador[%d].x  = %d\n", i, mapa.jugador[i].x);
            printf("mapa.jugador[%d].y  = %d\n", i, mapa.jugador[i].y);
        }
        printf("\nCOORDENADAS DE FANTASMAS\n");
        for(i = 0; i < mapa.numFantasmas; i++) {
            printf("mapa.fantasma[%d].x = %d\n", i, mapa.fantasma[i].x);
            printf("mapa.fantasma[%d].y = %d\n", i, mapa.fantasma[i].y);
        }
        printf("\nPulse una tecla para continuar\n");
        /*imprimeMapa(mapa, TRUE);
        mvprintw(mapa.dimensiones.y + 3,0, "PARA SALIR PULSE q");
        noecho();
        while((char) getch() != 'q') ;
        endwin();*/
    //}
    liberaMemoria(&mapa);
	return 0;
}