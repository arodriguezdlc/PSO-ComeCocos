#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

void jugador1 (int cambiocontroles, char controles1[4]){

char right = 'd';
char left = 'a';
char up = 'w';
char down = 's';
char mov;

if(cambiocontroles != 0)
	controles1(right, left, up, down, controles[4]);//si se han cambiado los controles del jugador uno, sustituye los que vienen por defecto
cbreak();
//flushinp();//vaciar buffer del teclado
mov = getch();

switch(mov){
	case(down):if(mapa->jugador[1].y+1==' ') (mapa->jugador[1].y)+1;
	break;
	case(up):if(mapa->jugador[1].y-1==' ') (mapa->jugador[1].y)-1;
	break;
	case(left):if(mapa->jugador[1].x-1==' ') (mapa->jugador[1].x)-1;
	break;
	case(right):if(mapa->jugador[1].x+1==' ') (mapa->jugador[1].x)+1;
	break;
	}
}

void controles1(char * right, char * left, char * up, char * down, char controles[4]){

&right = controles1[0];
&left = controles1[1];
&up = controles1[2];
&down = controles1[3];
}

/*habria que poner en el main un print preguntando si se quiere cambiar los controles, y si dice que si, poner cambiocontroles a 1 y rellenar la tabla de controles 1 con los nuevos controles*/
