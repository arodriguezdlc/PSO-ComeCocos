#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#include "estructuras.h"
#include "choque.h"

#define NO 0
#define SI 1


int choque(MAPA * mapa, COORDENADA anterior){//funcion para ver si chocan el jugador y el fantasma

int resultado = NO;

if(((mapa->jugador[j].x)==(mapa->fantasma[i].x))&&((mapa->jugador[j].y)==(mapa->fantasma[i].y)))
  resultado=SI;
else if(((anterior.x)==(mapa->fantasma[i].x))&&((anterior.y)==(mapa->fantasma[i].y)))
{
  if(((mapa->jugador[j].x)==(anterior.x))&&((mapa->jugador[j].y)==(anterior.y)))
  resultado=SI;
}

return resultado;
}
