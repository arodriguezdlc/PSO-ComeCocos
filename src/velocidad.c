#include <stdio.h>

void velocidad(int * velNum, int * velDen, int * iteraciones){

int seleccion= 6;
char caracter = '6';

while(seleccion>5){
	printf("seleccione modo y pulse intro:\n 1:muy facil\n 2:facil\n 3:normal\n 4:dificil\n 5:imposible\n ");
	caracter=getchar();
	if(caracter=='1'||caracter=='2'||caracter=='3'||caracter=='4'||caracter=='5')
		seleccion = caracter-48;
	}
switch(seleccion){
	case (1):
		*iteraciones = 50;
		*velNum = 3;
		*velDen = 4;
		break;
	case (2):
		*iteraciones = 60;
		break;
	case (3):
		*iteraciones = 100;
		break;
	case (4):
		*iteraciones = 150;
		*velNum = 1;
		*velDen = 3;		
		break;
	case (5):
		*iteraciones = 200;
		*velNum = 1;
		*velDen = 4;
		break;
	}
}
