#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"

#define NO 0
#define SI 1


int choque(MAPA * mapa, int i, int j){//funcion para ver si chocan el jugador y el fantasma

int resultado = NO;

if(((mapa->jugador[j].x)==(mapa->fantasma[i].x))&&((mapa->jugador[j].y)==(mapa->fantasma[i].y)))
resultado=SI;

return resultado;
}
