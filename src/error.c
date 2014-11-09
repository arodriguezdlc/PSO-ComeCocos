#include <stdio.h>

/*
	PLANTILLA:

	case (NUM):
	printf("ERROR %d: (DESCRIPCION ERROR)\n", numError);
	break;

	No olvidar documentar el error en la carpeta doc
*/

void error(int numError) {
		
	switch (numError) {
		case 1:
		printf("ERROR %d: Numero de parametros incorrectos. 
			Debe especificar ubicacion del mapa \n", numError);
		break;
		
	}

}