#include <stdio.h>
#include <stdlib.h>
//int opciones = 0;
//int movimiento;
int i =1;
char dir;
int mov;
int OK = 0;

int fantasma()
{
mov = rand()%4;

while(OK==0){
	if(mov==0){
		if ((mapa->fantasma[i].y)+1 == ' ' || mapa->fantasma[i].y)+1 == '-') //Condición para poder subir
		       {
			if(dir!='B')	{//Comprobamos
				(mapa->fantasma[i].y)+1;//Nuestra variable tiene que ser distinta de B, para que no vuelva a bajar
				dir = 'S';
				OK++;				
					}
			else	{
				do
				mov = rand()%4;
				while(mov==0)
				}
		  	}
		else	{
			do
			mov = rand()%4;
			while(mov==0)
		    	}
		   }
	
	if(mov==1){
		if ((mapa->fantasma[i].y)-1 == ' ') //Condición para Bajar
			{
			if(dir!='S')	{//Decimos que sea distinto de Subir para que no haga bucle
	    			(mapa->fantasma[i].y)-1;
				dir = 'B';
				OK++;
					}			
			else	{
				do
				mov = rand()%4;
				while(mov==1)
		    		}
			}
		else	{
			do
			mov = rand()%4;
			while(mov==1)
		    	}
		   }
			
	if(mov==2){
		if ((mapa->fantasma[i].x)+1 == ' ') // Podemos movernos hacia la derecha
			{
			if(dir!='D')	{
	    			(mapa->fantasma[i].x)+1;
				dir = 'I';
				OK++;			
					}
			else	{
				do
				mov = rand()%4;
				while(mov==2)
	 	    		}
			}
		else	{
			do
			mov = rand()%4;
			while(mov==2)
		    	}
		   }

	if(mov==3){
 		if ((mapa->fantasma[i].x)-1 == ' ') // Podemos movernos hacia la izquierda
			{
			if(dir!='I')	{
	    			(mapa->fantasma[i].x)-1;
				dir = 'D';
				OK++;			
					}
			else	{
				do
				mov = rand()%4;
				while(mov==3)
		    		}
			}
		else	{
			do
			mov = rand()%4;
			while(mov==3)
		    	}
		   }
} 
return 0;
}
