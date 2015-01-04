

a.out: TEST_jugador.o imprimeMapa.o jugador.o fantasma.o choque.o 
	gcc -g -W -Wall -pthread TEST_jugador.o imprimeMapa.o jugador.o fantasma.o choque.o -lncurses -lpthread

hilos: imprimeMapa.o jugador.o fantasma.o hilos.o principal.o semaforos.o keyboard.o
	gcc -g -W -Wall -pthread imprimeMapa.o jugador.o fantasma.o hilos.o principal.o semaforos.o keyboard.o -lncurses -lpthread

TEST_jugador.o: TEST_jugador.c
	gcc -g -W -Wall -c TEST_jugador.c	

imprimeMapa.o: imprimeMapa.c	
	gcc -g -W -Wall -c imprimeMapa.c

choque.o: choque.c
	gcc -g -W -Wall -c choque.c

keyboard.o: keyboard.c
	gcc -g -W -Wall -c keyboard.c	

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

