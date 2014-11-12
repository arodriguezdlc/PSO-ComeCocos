#include <stdio.h>
#include <ncurses.h>

#define FALSE 0
#define TRUE 1

int main() {

	int x = 2;
	int y = 2;
	char tecla;
	int salir = FALSE;
	initscr();
	while(salir == FALSE) {
		erase();
		mvprintw(y,x,	 " ###");
		mvprintw(y+1,x,  "#");
		mvprintw(y+2,x,  "#");
		mvprintw(y+3,x,  " ###");
		noecho();
		tecla = (char) getch(); 
		switch (tecla) {
			case	'w': 
				y--;
				break;
			case 	'a':  
				x--;
				break;
			case 	's':
				y++;
				break;
			case 	'd':
				x++;
				break;
			case 	'q':	
				salir = TRUE;
			default:
				;
				break;
		}
	}

	endwin();	 //Cerramos modo ncurses
	return 0;
}

/*
int leeComando() {
	int comando;

	return comando;
}
*/