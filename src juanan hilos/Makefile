

a.out: TEST_jugador.o imprimeMapa.o jugador.o fantasma.o choque.o
	gcc -g -W -Wall TEST_jugador.o imprimeMapa.o jugador.o fantasma.o choque.o -lncurses -lpthread

hilos: imprimeMapa.o jugador.o fantasma.o hilos.o principal.o semaforos.o 
	gcc -g -W -Wall -pthread imprimeMapa.o jugador.o fantasma.o hilos.o principal.o semaforos.o -lncurses 

TEST_jugador.o: TEST_jugador.c
	gcc -g -W -Wall -c TEST_jugador.c -lpthread	

imprimeMapa.o: imprimeMapa.c	
	gcc -g -W -Wall -c imprimeMapa.c

choque.o: choque.c
	gcc -g -W -Wall -c choque.c

kbhit.o: kbhit.c
	gcc -g -W -Wall -c kbhit.c	

jugador.o: jugador.c
	gcc -g -W -Wall -c jugador.c

fantasma.o: fantasma.c
	gcc -g -W -Wall -c fantasma.c

hilos.o: hilos.c
	gcc -g -W -Wall -c hilos.c

principal.o: principal.c
	gcc -g -W -Wall -c principal.c

semaforos.o: semaforos.c
	gcc -g -W -Wall -c semaforos.c

clean:
	rm -rf *.o
	rm -rf a.out*

