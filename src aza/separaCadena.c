#include <stdio.h>
#include <string.h>

/*
	Recibe como argumentos la cadena que se quiere partir y una tabla de arrays donde se guardaran todas las sub-cadenas
*/

void separaCadena(char cadena[],char*separadas[])
{
	int i=0;
	
	// Separa la primera cadena que encuentra
	separadas[i]=strtok (cadena, "\n");
	
	while (separadas[i] != NULL)
	{
		//printf("%s\n",separadas[i]);
		i++;
		// Separa las demas cadenas a partir de la ultima que ha encontrado
		separadas[i]=strtok(NULL, "\n");
	}
}

