#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void separaCadena(char cadena[],char*separadas[]);
/*
PRUEBA DE separaCadena.c
Imprime por pantalla las cadenas previamente separadas
*/
int main()
{
	int i=0;
	
	// Ejemplo de cadena
	char cadena[]="Hola\nHoy es viernes\nAl año que viene nos mudamos\nTe quiero\nEstoy loca\nNo se que mas escribir\n";
	
	// Tabla de arrays donde guardamos las sub-cadenas
	char ** obtenida = NULL;
	obtenida=(char**)malloc(strlen(cadena));
	// Comprobamos si se ha asignado la memoria correctamente
	if (obtenida==NULL)
	{
		printf("Error de memoria\n");
	}
	else
	{
		//Lamada a la funcion
		separaCadena(cadena,obtenida);
	
		// Imprimimos
		while (obtenida[i] != NULL)
		{
			printf("%s\n",obtenida[i]);
			i++;
		}
		free(obtenida);
	}
	return 0;
}
