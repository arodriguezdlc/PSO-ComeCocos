#include <stdio.h>
#include <stdlib.h>
#include "fantasma.h"
//#include <ncurses.h>
#include "estructuras.h"
//int opciones = 0;
//int movimiento;

void fantasma(MAPA * mapa)//Función fantasma que es de tipo void y recibe el mapa del comecocos
{
int i =1;//Indica el numero del fantasma
char dir = 'A';//Memoria del fantasma para recordar el último movimiento
int mov=5;//Variable para ver el movimiento que realizará el fantasma
int ok = 0;//VAriable de comprobación de movimiento correcto
int posibles = 0;//Variables para guardar movimientos posibles de fantasma
mov=comprueba(&posibles);//mov será igual al parametro recibido de mi funcion comprueba

while(ok==0)
	{//Mientras Ok sea igual a 0, intento realizar un movimiento
		if(mov==0)
		{	//Si el movimiento es 0(Subir)
			if (mapa->mapa[mapa->fantasma[i].y-1][mapa->fantasma[i].x] == ' ') //Condición para poder subir
			{
				if(dir!='B'||posibles==1)	
				{	//Comprobamos que el movimiento anterior no fuera bajar, o que solo haya 1 camino
					dir = 'S';//recuerdo el movimiento de subir
					(mapa->fantasma[i].y)-=1;//Nuestra variable tiene que ser distinta de B, para que no vuelva a bajar
					ok++;//Aumento Ok para salir del bucle				
				}
				else	
				{//En caso contrario busco otro movimiento con la función rand
					do//Creo el do while para que el valor de mov no coincida con el que se acaba de comprobar
					mov = rand()%4;
					while(mov==0)
				}
			}
			else	
			{
				do
				mov = rand()%4;
				while(mov==0)
			}
		}
		
		if(mov==1)
		{
			if(mapa->mapa[mapa->fantasma[i].y+1][mapa->fantasma[i].x] == ' ' ) //Condición para Bajar
			{
				if(dir!='S'||posibles==1)	
				{//Decimos que sea distinto de Subir para que no haga bucle
					dir = 'B';
		    		(mapa->fantasma[i].y)+=1;
					ok++;
				}			
				else	
				{
					do
					mov = rand()%4;
					while(mov==1)
				}
			}
			else	
			{
				do
				mov = rand()%4;
				while(mov==1)
			}
	   }
				
		if(mov==2)
		{
			if(mapa->mapa[mapa->jfantasma[i].y][mapa->fantasma[i].x+1] == ' ') // Podemos movernos hacia la derecha
			{
				if(dir!='I'||posibles==1)	
				{
					dir = 'D';
		    		(mapa->fantasma[i].x)+=1;
					ok++;			
				}
				else	
				{
					do
					mov = rand()%4;
					while(mov==2)
		 	    }
			}
			else	
			{
				do
				mov = rand()%4;
				while(mov==2)
			}
		}

		if(mov==3)
		{
	 		if(mapa->mapa[mapa->fantasma[i].y][mapa->fantasma[i].x-1] == ' ') // Podemos movernos hacia la izquierda
			{
				if(dir!='D'||posibles==1)	
				{
					dir = 'I';
		    		(mapa->fantasma[i].x)-=1;
					ok++;			
				}
				else	
				{
					do
					mov = rand()%4;
					while(mov==3)
				}
			}
			else	
			{
				do
				mov = rand()%4;
				while(mov==3)
	    	}
	   }
	} 
}

int comprueba(int *posibles, MAPA * mapa)//Funcion que comprueba el numero de movimientos posibles para el fantasma
{//La función devuelve un entero que será mov y recibe un puntero a la variable posibles de la función fantasma
int i = 1;//variable de control
int tabla[4] {0 , 0, 0, 0};//tabla de enteros para comprobacion 0=subir, 1=bajar, 2=derecha, 3=izquierda
int mov = 0;
	if (mapa->mapa[mapa->fantasma[i].y-1][mapa->fantasma[i].x]==' ')
	{
		*posibles++;//Si puedo Subir aumento las posibilidades en 1
		tabla[0]=1;//Guardo en mi tabla que Subir que es el puesto 0 es = 1
	}
	if(mapa->mapa[mapa->fantasma[i].y+1][mapa->fantasma[i].x]==' ')
	{
		*posibles++;//Si puedo bajar aumento posibilidades en 1
		tabla[1]=1;//Guardo en mi tabla que Bajar que es el puesto 1 es = 1
	}
	if(mapa->mapa[mapa->fantasma[i].y][mapa->fantasma[i].x+1]==' ')
	{
		*posibles++;//Si puedo ir a la Derecha aumento las posibilidades en 1
		tabla[2]=1;//Guardo en mi tabla que Derecha que es el puesto 2 es = 1
	}
	if(mapa->mapa[mapa->fantasma[i].y][mapa->fantasma[i].x-1]==' ')
	{
		*posibles++;//Si puedo ir a la Izquierda aumento las posibilidades en 1
		tabla[3]=1;//Guardo en mi tabla que Izquierda que es el puesto 3 es = 1
	}
	if(*posibles == 1)//Si solo tenemos un camino posible
	{
		for(i=0;i<4;i++)//Recorro mi tabla para ver cual es el único camino posible
		{
			if(tabla[i]==1)//El camino posible tendrá puesto en su posición de memoria un 1
				mov=i;//Igualo el movimiento a mi variable auxiliar que coincidirá con mi movimiento permitido
		}	
	}
	else//En caso de que haya mas de 1 posibilidad elijo un numero aleatorio entre[0-3]
		mov = rand()%4;//Igualo movimiento al valor devuelto por el rand

return mov;//Devuelvo mov		
}

