#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "estructuras.h"

void controles1(char * right, char * left, char * up, char * down, char controlesj1[4]){

*right = controlesj1[0];
*left = controlesj1[1];
*up = controlesj1[2];
*down = controlesj1[3];
}



void jugador1 (int cambiocontroles, char controlesj1[4]){

char right = 'd';
char left = 'a';
char up = 'w';
char down = 's';
char mov;//vble para guardar el caracter pulsado
int dir= 0;//vble para el switch

if(cambiocontroles != 0)
	controles1(&right, &left, &up, &down, &controlesj1[4]);//si se han cambiado los controles del jugador uno, sustituye los que vienen por defecto
cbreak();
//flushinp();//vaciar buffer del teclado
mov = getch();

if(mov==right) dir = 1;
else if (mov == left) dir = 2;
else if (mov == up) dir = 3;
else if (mov == down) dir = 4;

switch(dir){
	case(1):if(mapa->jugador[1].y+1==' ') (mapa->jugador[1].y)+1;
	break;
	case(2):if(mapa->jugador[1].y-1==' ') (mapa->jugador[1].y)-1;
	break;
	case(3):if(mapa->jugador[1].x-1==' ') (mapa->jugador[1].x)-1;
	break;
	case(4):if(mapa->jugador[1].x+1==' ') (mapa->jugador[1].x)+1;
	break;
	}
}


/*habria que poner en el main un print preguntando si se quiere cambiar los controles, y si dice que si, poner cambiocontroles a 1 y rellenar la tabla de controles 1 con los nuevos controles*/
