#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "estructuras.h"
#include "keyboard.h"

void * caracter(void * car){
	struct moving *mover;
//puts("4");
	mover=(struct moving *)car;
//puts("5");
	noecho();
	while(1){
		
		mover->movin=getch();
		//printf("%c\n",mover->movin);
	}
	pthread_exit(NULL);
}

void creaHilosKb(MOVING * a){

//puts("1");
	pthread_attr_init(&a->attr);
	pthread_attr_setdetachstate(&a->attr, PTHREAD_CREATE_DETACHED);
//puts("2");
	pthread_create(&a->th1, &a->attr, caracter, (void *)a);
//puts("3");
}
