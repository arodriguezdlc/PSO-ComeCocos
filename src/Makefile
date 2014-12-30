

a.out: TEST_fantasma.o imprimeMapa.o jugador.o fantasma.o
	gcc -g -W -Wall -lncurses TEST_fantasma.o imprimeMapa.o jugador.o fantasma.o

TEST_fantasma.o: TEST_fantasma.c
	gcc -g -W -Wall -c TEST_fantasma.c	

imprimeMapa.o: imprimeMapa.c	
	gcc -g -W -Wall -c imprimeMapa.c

jugador.o: jugador.c
	gcc -g -W -Wall -c jugador.c

fantasma.o: fantasma.c
	gcc -g -W -Wall -c fantasma.c

clean:
	rm -rf *.o
	rm -rf a.out*

