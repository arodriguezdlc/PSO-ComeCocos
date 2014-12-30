

a.out: TEST_fantasma.o imprimeMapa.o jugador.o fantasma.o
	gcc -g -W -Wall TEST_fantasma.o imprimeMapa.o jugador.o fantasma.o -lncurses

hilos: imprimeMapa.o jugador.o fantasma.o hilos.o principal.o
	gcc -g -W -Wall -pthread imprimeMapa.o jugador.o fantasma.o hilos.o principal.o -lncurses 

TEST_fantasma.o: TEST_fantasma.c
	gcc -g -W -Wall -c TEST_fantasma.c	

imprimeMapa.o: imprimeMapa.c	
	gcc -g -W -Wall -c imprimeMapa.c

jugador.o: jugador.c
	gcc -g -W -Wall -c jugador.c

fantasma.o: fantasma.c
	gcc -g -W -Wall -c fantasma.c

hilos.o: hilos.c
	gcc -g -W -Wall -c hilos.c

principal.o: principal.c
	gcc -g -W -Wall -c principal.c

clean:
	rm -rf *.o
	rm -rf a.out*

