#include <stdio.h>
/* COLOREAR CARACTERES EN EL TERMINAL (ver http://www.elrincondelc.com/nuevorincon/foros/viewtopic.php?t=9335)
Para abrir: \E[XXm (sustituir XX por los códigos de abajo)
Para cerrar: \E[00m

Colores de letra (foreground)
------------------------------

Combinación   Color
========================
0;30          Negro
0;31          Rojo
0;32          Verde
0;33          Marrón
0;34          Azul
0;35          Púrpura
0;36          Cian
0;37          Gris claro
1;30          Gris oscuro
1;31          Rojo claro
1;32          Verde claro
1;33          Amarillo
1;34          Azul claro
1;35          Púrpura claro
1;36          Cian claro
1;37          Blanco

Colores de fondo (background)
------------------------------

Combinación   Color
========================
40            Negro
41            Rojo
42            Verde
43            Marrón
44            Azul
45            Púrpura
46            Turquesa
47            Gris

Efectos de carácter
-------------------------------

Combinación   Estilo
========================
0;4           Subrayado
0;5           Titilante (blink)(puede que no funcione)
0;1           Negrita
0;8           Transparente (?)
*/
http://www.elrincondelc.com/nuevorincon/foros/viewtopic.php?t=9335
int main()
{
	printf("\E[0;31m Hola \E[00m mundo\n");
	
	return 0;
}
