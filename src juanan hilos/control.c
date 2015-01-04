#include <stdio.h>
#include <ncurses.h>
#include <pthread.h>
#include <fcntl.h>
#include <semaphore.h>

#define SEMAFORO_TECLA "comecocosleetecla"

void error(int num) {
	fprintf(stderr, "Error %d\n", num);
}

void * leeTecla(void * pteclaVoid) {

	sem_t * sem = NULL;	
	char * ptecla = (char *) pteclaVoid; //Convertimos el puntero void a char
	char tecla;

	if((sem = sem_open(SEMAFORO_TECLA, 0)) == SEM_FAILED) {	
		error(2); //Error en la creacion del semaforo
	}
	else {
		noecho();
		cbreak();	//Para que getch no bloquee el programa
		while(*ptecla != 0) {
			tecla = (char) getch();
			if(tecla != ERR) {	
				if(sem_wait(sem) == -1) { //Bajamos semaforo
					error(3); //Error al bajar el semaforo
				} else {
					*ptecla = tecla;
					sem_post(sem); //Subimos semaforo
				}
			}
		}
		if(sem_unlink(SEMAFORO_TECLA) == -1)
			error(6);		
	}
	pthread_exit(NULL);	
}

/*
*	Funcion para la escritura o lectura de la variable compartida tecla.
	tecla => puntero a la variable tecla que no se debe tocar manualmente
	escribir => indica si se quiere escribir (true) o leer (false)
	nuevoValor => nuevo valor de la tecla en caso de que modificar sea true
	
	Return => se devuelve el valor de tecla.
*/
char rwTecla(char * tecla, int escribir, char nuevoValor) {
	
	char aux = 0;
	sem_t * sem;	

	if((sem = sem_open(SEMAFORO_TECLA, O_CREAT, 0600, 1)) == SEM_FAILED) {
		error(4);
	}
	else {
		if(sem_wait(sem) == -1) {
			error(5);
		}
		else {
			if(escribir == true ) { 
				*tecla = nuevoValor;
			}
			aux = *tecla;
			sem_post(sem);
		}
		if(sem_unlink(SEMAFORO_TECLA) == -1)
			error(7);	
	}	
	return aux;
}

int main() {

	pthread_t th1;	
	int salir = false;
	char tecla; //NO TOCAR
	char teclaAux;
	initscr();
	pthread_create(&th1, NULL, leeTecla, (void *) &tecla);
	while(salir == false) {
		if((teclaAux = rwTecla(&tecla, false, 0)) == 'p') {
			rwTecla(&tecla, true, 0);
			salir = true;
		} else {
			mvprintw(0,0, "%c", teclaAux);
		}		
	}
	pthread_join(th1, NULL);

	return 0;
}
