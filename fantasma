#include <stdio.h>
#include <stdlib.h>
//int opciones = 0;
//int movimiento;
int i =1;
char dir;
int mov;

int fantasma()
{
mov = rand()%4;

	if(mov==0){
		if ((mapa->fantasma[i].y)+1 == ' ') //Condición para poder subir
		       {
			if(dir!='B')	{//Comprobamos
				(mapa->fantasma[i].y)+1;//Nuestra variable tiene que ser distinta de B, para que no vuelva a bajar
				dir = 'S';				
					}
			else	{
				mov = rand()%4;
				}
		  	}
		   }
	
	if(mov==1){
		if ((mapa->fantasma[i].y)-1 == ' ') //Condición para Bajar
			{
			if(dir!='S')	{//Decimos que sea distinto de Subir para que no haga bucle
	    			(mapa->fantasma[i].y)-1;
				dir = 'B';
					}			
			else	{
				mov = rand()%4;
		    		}
			}
		   }
			
	if(mov==2){
		if ((mapa->fantasma[i].x)+1 == ' ') // Podemos movernos hacia la derecha
			{
			if(dir!='D')	{
	    			(mapa->fantasma[i].x)+1;
				dir = 'I';			
					}
			else	{
				mov = rand()%4;
	 	    		}
			}
		   }

	if(mov==3){
 		if ((mapa->fantasma[i].x)-1 == ' ') // Podemos movernos hacia la izquierda
			{
			if(dir!='I')	{
	    			(mapa->fantasma[i].x)-1;
				dir = 'D';			
					}
			else	{
				mov = rand()%4;
		    		}
			}
		   } 
return 0;
}
