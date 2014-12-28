#include <stdio.h>

#define MAXCADENA 20
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
	char * obtenida[MAXCADENA];
	//Lamada a la funcion
	separaCadena(cadena,obtenida);
	// Imprimimos
	while (obtenida[i] != NULL)
	{
		printf("%s\n",obtenida[i]);
		i++;
	}
	return 0;
}
